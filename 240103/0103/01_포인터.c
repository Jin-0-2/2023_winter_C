// 01_������.c
/*
1. [�ּ�]�� ���� �� �� �ִ� ������ ����
2. ������ ������ ���� ���� ũ��? > ��� �����ϴ�.
	32bit -> 4byte, 64bit -> 8byte

	�� ���� ���� : Ÿ�Կ� ���� ũ�Ⱑ �ٸ���.
	sizeof(int) -> 4byte		sizeof(char) -> 1byte		sizeof(float) -> 4byte
3. ������ ����(�ּ�)�� ������ Ÿ�Կ� ���� �̵��� ũ�Ⱑ �޶�����.
	int *p1 = �����迭�� �ּ�;		p1 + 1; > sizeof(int)*1  �̵�
	char *p2 = ���ڹ迭�� �ּ�;		p2 + 1; > sizeof(char)*1 �̵�
*/
#include <stdio.h>

void exam1();
void exam2();

void main()
{
	exam1();
}

void exam1()
{
	int num1;
	char ch;
	float f_num2;

	int* p1;
	char* p2;
	float* p3;

	printf("%d, %d\n", (int)sizeof(int), (int)sizeof(num1));
	printf("%d, %d\n", (int)sizeof(char), (int)sizeof(ch));
	printf("%d, %d\n", (int)sizeof(float), (int)sizeof(f_num2));

	// �������� ��������� ��� ũ�Ⱑ �����ϴ�.
	printf("%d, %d\n", (int)sizeof(int*), (int)sizeof(p1));
	printf("%d, %d\n", (int)sizeof(char*), (int)sizeof(p2));
	printf("%d, %d\n", (int)sizeof(float*), (int)sizeof(p3));
}

// �ּ� �̵�(32bitȯ������ ���� �� ���
void exam2()
{
	int arr1[10];
	char arr2[10];

	int* p1 = arr1;
	char* p2 = arr2;

	// ������ Ÿ�Ժ� �̵� ũ�Ⱑ �ٸ���.
	printf("%d, %d\n", (int)p1, (int)(p1 + 1)); // 11859716, 11859720 > int ũ�⸸ŭ
	printf("%d, %d\n", (int)p2, (int)(p2 + 1)); // 11859696, 11859697 > char ũ�⸸ŭ
}