// 04_정적변수.c
/*
정적지역변수 : 전역정적메모리에 저장
	- 변수 선언된 함수가 종료되도라도 계속 존재함
	-> 지역변수를 전역변수처럼 사용가능
	- 선언된 <함수> 내에서만 사용 가능

정적전역변수 : 전역정적메모리에 저장
	- extern 사용 불가
	  선언된 <파일> 내에서만 사용 가능!
*/
#include <stdio.h>

void fun()
{
	int		    num = 1;				// 지역변수     --> 스택
	static int s_num = 1;				// 정적지역변수 --> 전역정적

	num++;		s_num++;

	printf("%d, %d\n", num, s_num);
}

void fun1();

extern int g_num1;
// extern static int g_num;		// 정적변수는  참조선언이 불가능하다.

void fun1()
{
	g_num1 = 10;
	g_num = 20;
}

int main()
{
	fun();		// 스택메모리 생성 -> 소멸		2, 2
	fun();		// 스택메모리 생성 -> 소멸		2, 3
	fun();		// 스택메모리 생성 -> 소멸		2, 4

	return 0;
}

static int g_num;		// 정적전역변수
int g_num1;				// 전역변수