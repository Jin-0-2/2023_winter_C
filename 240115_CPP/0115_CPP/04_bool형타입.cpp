// 04_bool형타입.cpp
/*
[기본형타입 : 미리 제공되는 타입]
정수 int
실수 float
문자 char    -> 문자도 정수이다.
----------------------------------
불형 bool ture(1), false(0)	--> 정수이다.
*/
#include <iostream>
using namespace std;

int main()
{
	bool b = true;			cout << b << endl;		//1
	b = false;				cout << b << endl;		//0

	b = 1;					cout << b << endl;		//1
	b = 0;					cout << b << endl;		//0

	b = -1;					cout << b << endl;		//1  > 거짓의 의미를 가지는 것은 0뿐 
	b = 100;				cout << b << endl;		//1

	return 0;
}