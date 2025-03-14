// 03_열거형.cpp
/*
1. 태그가 타입명이다. [구조체, 열거형...]
2. 열거형 타입에 정수형 변수 대입불가![C언어 문제]
*/
#include <iostream>
using namespace std;

enum subject
{
	COM, IT = 101, GAME, ETC = 200
};

int main()
{
	// 1. enum에 열거된 키워드 사용
	printf("%d\n", COM);	// 0

	// 2. 변수 선언
	enum subject s1 = COM; 
	cout << s1 << endl;

	s1 = GAME;
	cout << s1 << endl;

	enum subject s2 = IT;
	cout << s2 << endl;

	enum subject s3 = GAME;
	cout << s3 << endl;

	enum subject s4 = ETC;
	cout << s4 << endl;




	// 3. C++에서는 에러
	// s1 = 300;

	printf("%d\n", s1);

	return 0;
}