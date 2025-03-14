// 03_함수템플릿.cpp
/*
함수 템플릿 사용
- 암시적 사용(......활용)
	인자 전달을 이용해 T를 추론
- 명시적 사용
	사용자가 직접 T를 정의
*/
#include <iostream>
using namespace std;

template <typename T>
T myadd(T n1, T n2)
{
	return n1 + n2;
}

template <typename T>
T mysub(T n1, T n2)
{
	return n1 - n2;
}

template <typename T1, typename T2, typename T3, typename T4>
T1 mymul(T1 n1, T2 n2, T3 n3, T4 n4)
{
	return n1 * n2 * n3 * n4;
}

template <typename T1, typename T2, typename T3, typename T4, typename  T5>
T5 mymul1(T1 n1, T2 n2, T3 n3, T4 n4)
{
	return n1 * n2 * n3 * n4;
}

int main()
{
	cout << myadd(10, 20) << endl;
	cout << myadd(10.1f, 20.2f) << endl;

	// 암시적
	cout << mysub(10, 20) << endl;
	cout << mysub(10.1f, 20.2f) << endl;

	// 명시적
	cout << mysub<float>(10, 20.2f) << endl;		//?

	cout << mymul(1, 2, 3, 4) << endl;		// int, int, int, int
	cout << mymul<int, int, int, int>(1, 2, 3, 4) << endl;
	cout << mymul(1, 10.1f, 20.2f, 30) << endl;

	// 명시적사용만 가능
	cout << mymul1<int, float, float, int, float>(1, 10.1f, 20.2f, 30) << endl;
	
	return 0;
}