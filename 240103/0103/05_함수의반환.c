// 05_함수의 반환(리턴타입)
/*
함수의 종료 방법
1) 모든 코드 실행 + ' } '
2) return 키워드
*/
#include <stdio.h>

void fun1();		// 반환 X
int fun2();			// int
char fun3();		// char

void main()
{
	fun1();
	// 반환은 선택적이다..!
	fun2();							// 10
	int num = fun2();				// int num = 10;
	printf("%d\n", num);
	
	fun3();
	char ch = fun3();
	printf("%c\n", ch);
}

void fun1()
{
	printf("1\n");
	return;
	printf("2\n");
	printf("3\n");
}

int fun2()
{
	return 10 + 20 + 30;
}

char fun3()
{
	char ch = 'A';
	return ch + 1;
}