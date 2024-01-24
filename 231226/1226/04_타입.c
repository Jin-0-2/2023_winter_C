// 01_타입.c
#include <stdio.h>

void exam1();
void exam2();
void exam3();
void exam4();

void main()
{
	exam2();
}

// 정수 타입의 크기
void exam1()
{
	short a; // -32768 ~ 32767
	int b = 1;  // short보다 범위가 크다.

	a = 32767;

	printf("%d\n", a); // 32767
	
	a = a + b; // a = 32767 +1; a = 32748;
	printf("%d\n", a); // -32768
}

// 실수형 타입
// 12.4  : double
// 12.4f : float
// 실수형은 그냥 사용하면 double로 인식(기본), 정확한 숫자의 저장 x
void exam2()
{
	float d1;
	d1 = 12.0f;			printf("%f\n", d1);
	d1 = d1 + 0.1f;     printf("%f\n", d1);
	d1 = d1 + 0.1f;     printf("%f\n", d1);
	d1 = d1 + 0.1f;     printf("%f\n", d1);
	d1 = d1 + 0.1f;     printf("%f\n", d1);
	d1 = d1 + 0.1f;     printf("%f\n", d1);
}

// 타입 크기
void exam3()
{
	int a;
	char b;

	printf("%zdbtye, %zdbyte\n", sizeof(int), sizeof(a));  // zd를 쓰는 것을 권고
	printf("%zdbtye, %zdbyte\n", sizeof(char), sizeof(b));
}

// 강제 형변환
void exam4()
{
	int num;
	float f_num = 10.123f;

	num = (int)f_num; // int =(int)float

	int num1 = 10;
	int num2 = 3;
	float result;

	result = num1 / (float)num2;

	printf("%f\n", result);
}