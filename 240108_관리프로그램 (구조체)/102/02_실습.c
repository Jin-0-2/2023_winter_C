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


// 1. ���� 10���� �����ϴ� 1���� �迭�� �����ϰ� ��� 0���� �ʱ�ȭ �Ͻÿ�.
//����� ����� ��
#define ARR1_MAX 10
void exam1()
{
	int arr1[ARR1_MAX] = { 0 };

	for (int i = 0; i < ARR1_MAX; i++)
	{
		printf("%3d", arr1[i]);
	}	
}

// 2. ���� 10���� �����ϴ� 1���� �迭�� �����ϰ� 1���� 10���� �ʱ�ȭ �Ͻÿ�.
//����� ����� ��
void exam2()
{
	int arr2[10] = { 1,2,3,4,5,6,7,8,9,10 };

	for (int i = 0; i < 10; i++)
	{
		printf("%3d", arr2[i]);
	}
}

// 3.���� 3*5���� �����ϴ� 1���� �迭�� �����ϰ� ��� 0���� �ʱ�ȭ �Ͻÿ�.
//����� ����� ��
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

// 4. ���� 3*5���� �����ϴ� 2���� �迭�� �����ϰ� 1~15������ ������ �ʱ�ȭ �Ͻÿ�.
// ����� ����� ��
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

// ���� 5���� �����ϴ� 1���� �迭�� �����ϰ�  5���� ������ �Է� �޾� �迭�� ���������� �����Ͻÿ�.
// ������ ��� �հ� ����� ����Ͻÿ�.

void exam5()
{
	int arr5[5];
	int sum = 0;
	float aver = 0;

	for (int i = 0; i < 5; i++)
	{
		printf("���� �Է� : ");
		scanf_s("%d", &arr5[i]);
	}

	for (int i = 0; i < 5; i++)
	{
		sum = sum + arr5[i];
	}
	aver = sum / (float)5;

	printf("������ ���� �� : %d\n ������ ���� ��� : %.1f\n", sum, aver);
}