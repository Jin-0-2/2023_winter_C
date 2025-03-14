// 05_참조자.cpp
/*
참조자 == 별명(별칭)
0. 반드시 선언과 동시에 초기화가 되어야 한다. 
1. 별도의 메모리가 생성되지 않는다.
2. 대상(특정 변수)의 또다른 식별자
*/
#include <iostream>
using namespace std;

/*
100		num1(r_num1)	 10 -> 20
[main stack]
*/ 
int main()
{
	int num1 = 10;

	// r_num1은 num1의 별명이다.
	int& r_num1 = num1;		// r_num1 : 참조자

	cout << r_num1 << ", " << num1 << endl;	// 10, 10

	r_num1 = 20;
	cout << r_num1 << ", " << num1 << endl;	// 20, 20
	cout << &r_num1 << ", " << &num1 << endl;	// 동일한 주소

	return 0;
}