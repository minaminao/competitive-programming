//#define double long double
const double EPS = 1e-8; //問題ごとに変更
#define equals(a,b) (fabs((a)-(b)) < EPS)
template<class T> bool chequals(T &a, const T &b) { if (fabs(a - b) < EPS) { a = b; return true; } return false; }

struct Point {
	double x, y, z;
	Point() {}
	Point(double x, double y, double z) :x(x), y(y), z(z) {}

	Point operator+(const Point &p)const { return Point(x + p.x, y + p.y, z + p.z); }
	Point operator-(const Point &p)const { return Point(x - p.x, y - p.y, z - p.z); }
	Point operator*(double a)const { return Point(a * x, a * y, a * z); }
	Point operator/(double a)const { return Point(x / a, y / a, z / a); }
	bool operator<(const Point &p)const {
		if (x < p.x)return true;
		if (x > p.x)return false;
		if (y < p.y)return true;
		if (y > p.y)return false;
		if (z < p.z)return true;
		return false;
	}
	bool operator==(const Point &p)const { return equals(x, p.x) && equals(y, p.y) && equals(z, p.z); }

	double abs() { return sqrt(norm()); }
	double norm() { return x*x + y*y + z*z; }

};
inline ostream &operator << (ostream &os, const Point &p) { os << p.x << " " << p.y << " " << p.z; return os; }
inline istream &operator >> (istream &is, Point &p) { double x, y, z; is >> x >> y >> z; p = Point(x, y, z); return is; }

struct Vector :public Point {
	using Point::Point;
	Vector() {}
	Vector(const Point &P) { x = P.x; y = P.y; z = P.z; }
	Vector unit() { return *this / abs(); }
};

//http://www.math.s.chiba-u.ac.jp/~yasuda/Chiba/Lec/naiseki.pdf
//内積 dot product
double dot(Vector a, Vector b) {
	double ret = a.x*b.x + a.y*b.y + a.z*b.z;
	chequals(ret, 0.0);
	return ret;
}
//外積 cross product
Vector cross(Vector a, Vector b) {
	Vector ret;
	ret.x = a.y*b.z - a.z*b.y; chequals(ret.x, 0.0);
	ret.y = a.z*b.x - a.x*b.z; chequals(ret.y, 0.0);
	ret.z = a.x*b.y - a.y*b.x; chequals(ret.z, 0.0);
	return ret;
}

struct Line {
	Point p1, p2;
	Line() {}
	Line(Point p1, Point p2) :p1(p1), p2(p2) {}
};

struct Segment :public Line {
	using Line::Line;
	Segment() {}
	Segment(const Line &L) { p1 = L.p1; p2 = L.p2; }
	Vector vec() { return p2 - p1; }
};

//球
struct Sphere {
	Point c;
	double r;
	Sphere() {}
	Sphere(const Point &c, double r) :c(c), r(r) {};
};

//平面
struct Plane {
	double a, b, c, d;// ax+by+cz+d=0
	Plane() {}
	Plane(double a, double b, double c, double d) :a(a), b(b), c(c), d(d) {}
	Plane(const Vector &n, const Point &p) :a(n.x), b(n.y), c(n.z) {
		d = -(a*p.x + b*p.y + c*p.z);
	};

	Vector normal() { return Vector(a, b, c); } //法線
	Point point() { return Point(a*d, b*d, c*d); }
};

struct Triangle {
	Point p1, p2, p3;
	Triangle() {}
	Triangle(const Point &p1, const Point &p2, const Point &p3) :p1(p1), p2(p2), p3(p3) {}
	Plane plane() {
		Vector OA(p2 - p1), OB(p3 - p1);
		Vector n(cross(OA, OB));
		return Plane(n, p1);
	}
};

//度からラジアン degree to radian
double rad(double deg) { return acos(-1)*deg / 180; }
//偏角 argument
double arg(Vector p) { return atan2(p.y, p.x); }
//2つのベクトルの角度
double angle(Vector a, Vector b) {
	double lena = a.abs(), lenb = b.abs();
	if (lena == 0 || lenb == 0)return 0; //解なし
	double costheta = dot(a, b) / (lena*lenb);
	if (equals(costheta, 1))costheta = 1; //誤差対策
	return acos(costheta);
}

//直交判定
bool is_orthogonal(Vector a, Vector b) { return equals(dot(a, b), 0.0); }
bool is_orthogonal(Segment s1, Segment s2) { return equals(dot(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0); }

//射影
Point project(Segment s, Point p) {
	Vector base = s.p2 - s.p1;
	double r = dot(p - s.p1, base) / base.norm();
	return s.p1 + base*r;
}
//反射
Point reflect(Segment s, Point p) { return p + (project(s, p) - p)*2.0; }

//2点間の距離
double get_distance(Point a, Point b) { return (a - b).abs(); }
//http://www.sousakuba.com/Programming/gs_dot_line_distance.html
//直線と点の距離
double get_distance(Line l, Point p) { return cross(l.p2 - l.p1, p - l.p1).abs() / (l.p2 - l.p1).abs(); }
//線分と点の距離
double get_distance(Segment s, Point p) {
	if (dot(s.p2 - s.p1, p - s.p1) < 0.0)return get_distance(p, s.p1);
	if (dot(s.p1 - s.p2, p - s.p2) < 0.0)return get_distance(p, s.p2);
	return get_distance(Line(s), p);
}

//球と線分の交差判定
bool intersect(Sphere SP, Segment S) {
	return SP.r + EPS >= get_distance(S, SP.c);
}

//球と直線の交点
pair<Point, Point> get_cross_points(Sphere SP, Line L) {
	assert(intersect(SP, L));
	Vector pr = project(L, SP.c);
	Vector e = (L.p2 - L.p1) / (L.p2 - L.p1).abs();
	double base = sqrt(SP.r*SP.r - (pr - SP.c).norm());
	return make_pair(pr + e*base, pr - e*base);
}

/* バグあり
//平面と線分の交差判定
bool intersect(Plane pl, Segment sg) {
Vector O(pl.point());
Vector OA(sg.p1 - O), OB(sg.p2 - O);
double dot1 = dot(pl.normal(), OA);
double dot2 = dot(pl.normal(), OB);
if (equals(dot1, 0))dot1 = 0;
if (equals(dot2, 0))dot2 = 0;
if (dot1 == 0 && dot2 == 0)return false; //両端が平面上
else if (dot1*dot2 <= 0)return true;
else return false;
}

//平面と線分の交点
Point get_cross_point(Plane pl, Segment sg) {
assert(intersect(pl, sg));
Vector O(pl.point());
dumpl(O);
Vector OA(sg.p1 - O), OB(sg.p2 - O);
Vector AB(sg.vec());
double dot1 = dot(pl.normal(), OA);
double dot2 = dot(pl.normal(), OB);
if (equals(dot1, 0))dot1 = 0;
if (equals(dot2, 0))dot2 = 0;
double r = abs(dot1) / (abs(dot1) + abs(dot2));
return sg.p1 + AB*r;
}

enum { OUT = 0, ON, IN };
//三角形と同一平面上の点の内包
int contains(Triangle t, Point p) {
Vector AB(t.p2 - t.p1), BC(t.p3 - t.p2), CA(t.p1 - t.p3);
Vector AP(p - t.p1), BP(p - t.p2), CP(p - t.p3);
Vector c1(cross(AB, BP)), c2(cross(BC, CP)), c3(cross(CA, AP));
double d1 = dot(c1, c2), d2 = dot(c1, c3);
if (equals(d1, 0) || equals(d2, 0))return ON;
if (d1*d2 > 0)return IN;
return OUT;
}

//三角形と線分の交差判定
bool intersect(Triangle t, Segment s) {
Plane pl = t.plane();
dumpl(pl.normal());
if (!intersect(pl, s))return false;
Point cp = get_cross_point(pl, s);
dumpl(cp);
dumpl(contains(t, cp));
return contains(t, cp) > 0;
}
*/