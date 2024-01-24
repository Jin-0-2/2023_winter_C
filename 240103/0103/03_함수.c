// 03_함수.c
/*
함수 : C언어의 핵심 모듈
1) 선언 : 함수의 원형을 컴파일러에게 알려줌
2) 정의 : 함수 생성 -> 변수 선언 연산 등의 코드를 작성
3) 호출 :  흐름

------------------------------------------------------
함수의 원형(선언부) : 리턴타입 함수명 (매개변수, 매개변수...);
- 매개변수 : [in]   : 필요한 정보
- 리턴타입 : [out]	: 결과를 반환
* [필요한 정보를 받아서] [연산을 수행하고] [결과를 반환한다.]

예) int fun1(int, int) : [int,int] -> [out]
	void fun2();	   : [void]	   -> [void]
	[생략] fun2();	   : [void]	   -> [int]  바람직하지 않다.

	매개변수의 개수 : 0 ~ N
	리턴타입		: 0 ~ 1
*/
#include <stdio.h>


void fun1();
void fun2(int n1);
void fun3(char n1, int n2);
void fun4(const char* msg);		// 상수 문자열

void main()
{
	// 함수 호출은 반드시 원형의 모양과 일치
	// 매개변수와 인자전달 : 대입연산의 원리와 100% 일치
	fun1();

	fun2(10);
	int num1 = 20;	fun2(num1);
	fun2(num1 + 20);

	fun3('A', 10);

	fun4("문자열 전달");
}

void fun1()
{
	int num1 = 10;
	printf("%d\n", num1);
}

void fun2(int n1)
{
	int n2;
	n2 = n1;
	printf("%d, %d\n", n1, n2);
}

void fun3(char n1, int n2)			// 매개변수 : 호출 시 초기화
{
	int n3;							// 지역변수 : 쓰레기

	printf("%c, %d\n", n1, n2);		
	//printf("%d\n", n3);			// 의미없는 코드
}

void fun4(const char* msg)
{
	printf("%s\n", msg);
}