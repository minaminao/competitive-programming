#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
using Int = mp::cpp_int;
//#define int Int;

/*
long long ^ 2 �̂悤�ɃI�[�o�[�t���[���鎞�̍ŏI��i�Ƃ���
*/

void f() {
	//https://boostjp.github.io/tips/multiprec-int.html
	Int x = 1;
	rep(i, 1, 100)x *= i;
	cout << x << endl;

	Int y("100");
	y.str();

	(int)x;
}