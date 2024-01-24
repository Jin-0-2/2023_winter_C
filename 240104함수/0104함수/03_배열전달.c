// 03_�迭����.c
/*
�� �� : �迭 ���� �ּ�, ����
�޴���: ���� ���� O : ������
		���� ���� X : const ������
*/

#include <stdio.h>

void arr_init(int* arr, int size);
void arr_print(const int* arr, int size);
int arr_sum1(const int* arr, int size);
void arr_sum2(const int* arr, int size, int* pnum);

#define DATA_MAX 1000

int main()
{
	int arr[DATA_MAX];

	arr_init(arr, DATA_MAX);		// 1..10���� �� ����

	arr_print(arr, DATA_MAX);		// �迭�� ��� ����� �� ���

	int sum;
	sum = arr_sum1(arr, DATA_MAX);	// �� ��ȯ
	arr_sum2(arr, DATA_MAX, &sum);	// �� ��ȯ

	printf("���� ��� : %d\n", sum);

	return 0;
}
void arr_init(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = i + 1;
	}
}
void arr_print(const int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%4d", arr[i]);
	}
	printf("\n");
}

int arr_sum1(const int* arr, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum = sum + arr[i];
	}
	return sum;
}

void arr_sum2(const int* arr, int size, int* pnum)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum = sum + arr[i];
	}
	*pnum = sum;
}