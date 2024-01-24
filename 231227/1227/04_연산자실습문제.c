#include<stdio.h>

void exam1();
void exam2();
void exam3();
void exam4();

void main()
{
	exam4();
}

//1. 정수 2개를 입력받아 곱과 나눗셈 결과를 출력하시오.
//단 나눗셈은 소숫점 1자리까지 출력하시오.

void exam1()
{
	int in_a, in_b, out_a;
	float out_b;
	
	printf("정수 입력 : ");
	scanf_s("%d", &in_a);
	printf("정수 입력 : ");
	scanf_s("%d", &in_b);
	printf("\n");

	out_a = in_a * in_b;
	out_b = in_a / (float)in_b;

	printf("두 정수의 곱 : %d\n", out_a);
	printf("두 정수의 나누기 : %.1f", out_b);
}

//2.  소문자를 입력받아 대문자로 변환하여 출력하시오.
void exam2()
{
	char in_a, out_a;

	printf("소문자 입력 : ");
	scanf_s("%c", &in_a, (int)sizeof(in_a));

	out_a = in_a - ('a' - 'A');
	printf("대문자 변환 : %c", out_a);
}

// 3. 정수를 입력받아 몇개월 몇일인지를 출력하시오.
// 단, 1개월은 30일로 가정함.
void exam3()
{
	int in_a, out_a, out_b;
	printf("정수 입력 : ");
	scanf_s("%d", &in_a);
	out_a = in_a / 30;
	out_b = in_a % 30;

	printf("%d개월 %d일", out_a, out_b);
}

// 4. 양의 정수를 입력받아 짝수면 "짝수" 아니면 "홀수"를 출력하시오.
// 결과값 = 입력한 수 % 2;
// 결과값이 0이면 짝수, 1이면 홀수(3항연산자를 사용하여 결과를 출력 할 것)
void exam4()
{
	unsigned int in_a;
	int out_a;

	printf("양의 정수 입력 : ");
	scanf_s("%d", &in_a);

	out_a = in_a % 2;

	printf("%s", out_a == 0 ? "짝수" : "홀수");
}
