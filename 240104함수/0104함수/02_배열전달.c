// 02_�迭 ����.c
// �� ����
// �ּ� ���� :  �� ���� ���� ��û�ϰ��� �� ���
#include <stdio.h>

void fun1(int* arr1, int arr2[]);			// �迭�� �ּ�
void fun2(int num1, int num2);				// ����� ��
void fun3(int* pnum1, int* pnum2);			// ����� �ּ�

int main()
{
	int arr[5] = { 1,2,3,4,5 };

	fun1(arr, arr + 2);					// int*, int*
	fun2(arr[0], arr[3]);				// int , int
	fun3(&arr[1], &*(arr + 2));			// int*, int*
	
	return 0;
}

void fun1(int* arr1, int arr2[])
{
	*arr1       = 11;					// arr[0] = 11;
	*(arr1 + 1) = 22;					// arr[1] = 22;
	arr1[2]     = 33;					// arr[2] = 33;

	*arr2   = 44;						// arr[2] = 44;
	arr2[2] = 55;						// arr[4] = 55;
}

void fun2(int num1, int num2)
{
	num1 = 1;
	num2 = 4;
}

void fun3(int* pnum1, int* pnum2)
{
	pnum1[2] = 22;						// arr[3] = 22;
	*pnum1 = 44;						// arr[1] = 44; OK.
}