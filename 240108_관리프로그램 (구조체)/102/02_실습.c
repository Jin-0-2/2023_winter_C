#include <stdio.h>

void exam1();
void exam2();
void exam3();
void exam4();
void exam5();

void main()
{
	exam3();
}


// 1. 정수 10개를 저장하는 1차원 배열을 선언하고 모두 0으로 초기화 하시오.
//결과를 출력할 것
#define ARR1_MAX 10
void exam1()
{
	int arr1[ARR1_MAX] = { 0 };

	for (int i = 0; i < ARR1_MAX; i++)
	{
		printf("%3d", arr1[i]);
	}	
}

// 2. 정수 10개를 저장하는 1차원 배열을 선언하고 1부터 10까지 초기화 하시오.
//결과를 출력할 것
void exam2()
{
	int arr2[10] = { 1,2,3,4,5,6,7,8,9,10 };

	for (int i = 0; i < 10; i++)
	{
		printf("%3d", arr2[i]);
	}
}

// 3.정수 3*5개를 저장하는 1차원 배열을 선언하고 모두 0으로 초기화 하시오.
//결과를 출력할 것
void exam3()
{
	int arr3[3][5];
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arr3[i][j] = 0;
		}
		printf("\n");
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%3d", arr3[i][j]);
		}
		printf("\n");
	}
}

// 4. 정수 3*5개를 저장하는 2차원 배열을 선언하고 1~15까지의 값으로 초기화 하시오.
// 결과를 출력할 것
void exam4()
{
	int arr4[3][5] = {
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15}
	};

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%3d", arr4[i][j]);
		}
		printf("\n");
	}
}

// 정수 5개를 저장하는 1차원 배열을 선언하고  5개의 정수를 입력 받아 배열에 순차적으로 저장하시오.
// 저장한 모든 합과 평균을 출력하시오.

void exam5()
{
	int arr5[5];
	int sum = 0;
	float aver = 0;

	for (int i = 0; i < 5; i++)
	{
		printf("정수 입력 : ");
		scanf_s("%d", &arr5[i]);
	}

	for (int i = 0; i < 5; i++)
	{
		sum = sum + arr5[i];
	}
	aver = sum / (float)5;

	printf("저장한 값의 합 : %d\n 저장한 값의 평균 : %.1f\n", sum, aver);
}