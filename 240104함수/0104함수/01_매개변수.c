// 01_매개변수(매개변수 리스트).c
/*
함수 호출 시 정보를 전달할 수 있다.
이 과정에서 값을 받도록 변수를 선언 > 매개변수

-방법-
1) 값   전달(value)	 : 복사, 주면 끝
2) 주소 전달(address): 원본, 내 정보에 접근 요청(필요하다면 변경)
*/
#include <stdio.h>

void fun(int n1, int *p);

int main()
{
	int num1 = 10;

	fun(num1, &num1); // 값, 주소

	printf("%d\n", num1);

	return 0;
}

void fun(int n1, int* p)  // 10, 100번지
{
	n1 = 20;			  // 20 
	*p = 30;			  // 100번지의 역참조 > num1 = 30
}