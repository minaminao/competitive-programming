#define idx(i) (i+25)
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end())
#define REMOVE(v,a) v.erase(remove(v.begin(),v.end(),a),v.end())

#define X first
#define Y second
using P = pair<int, int>;

//#define int long long
//#define double long double

////Žg‚¦‚¸
//#define _overload(_1,_2,_3,name,...) name
//#define _rep(i,n) _rep2(i,0,n)
//#define _rrep(i,n) _rrep2(i,0,n)
//#define _rep2(i,a,b) for(int i=(a);i<(b);i++)
//#define _rrep2(i,a,b) for(int i=(b)-1;i>=(a);i--)
//#define rep(...) _overload(__VA_ARGS__,_rep2,_rep,)(__VA_ARGS__)
//#define rrep(...) _overload(__VA_ARGS__,_rrep2,_rrep,)(__VA_ARGS__)

stringstream _cerr;
#define cerr _cerr;
