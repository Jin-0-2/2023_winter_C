// 01_Ÿ��.c
#include <stdio.h>

void exam1();
void exam2();
void exam3();
void exam4();

void main()
{
	exam2();
}

// ���� Ÿ���� ũ��
void exam1()
{
	short a; // -32768 ~ 32767
	int b = 1;  // short���� ������ ũ��.

	a = 32767;

	printf("%d\n", a); // 32767
	
	a = a + b; // a = 32767 +1; a = 32748;
	printf("%d\n", a); // -32768
}

// �Ǽ��� Ÿ��
// 12.4  : double
// 12.4f : float
// �Ǽ����� �׳� ����ϸ� double�� �ν�(�⺻), ��Ȯ�� ������ ���� x
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

// Ÿ�� ũ��
void exam3()
{
	int a;
	char b;

	printf("%zdbtye, %zdbyte\n", sizeof(int), sizeof(a));  // zd�� ���� ���� �ǰ�
	printf("%zdbtye, %zdbyte\n", sizeof(char), sizeof(b));
}

// ���� ����ȯ
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