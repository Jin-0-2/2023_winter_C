// 03_배열전달.c
/*
전 달 : 배열 시작 주소, 개수
받는쪽: 원본 변경 O : 포인터
		원본 변경 X : const 포인터
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

	arr_init(arr, DATA_MAX);		// 1..10까지 값 저장

	arr_print(arr, DATA_MAX);		// 배열의 모든 요소의 값 출력

	int sum;
	sum = arr_sum1(arr, DATA_MAX);	// 합 반환
	arr_sum2(arr, DATA_MAX, &sum);	// 합 반환

	printf("합의 결과 : %d\n", sum);

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