// 01_2���� �迭.c

#include <stdio.h>

void exam1();
void exam2();
void exam3();
void exam4();

void main()
{
	exam4();
}

/*
2���� �迭�� ����
*/
void exam1()
{
	// [����]���� 56�� ����
	// [����] 00 01 02 10 11 12		vs		00 01 10 11 20 21
	// [Ÿ��] int(*)[3]  vs  int(*)[2]
	int arr1[2][3] = { {1,2,3}, {4,5,6} };
	int arr2[3][2] = { {1,2}, {3,4}, {5,6} };
}

// �ּ� Ȯ���� ���� x86���� ����
void exam2()
{
	int arr1[2][5] = { {1,2,3,4,5},
					   {6,7,8,9,10} };
	printf("%d\n", (int)arr1);				// 412
	printf("%d\n", (int)(arr1 + 1));		// 396
	printf("%d\n", (int)((*arr1) + 1));		// 1
	printf("%d\n", (int)(**arr1));			// 416
	printf("%d\n", (int)(arr1[1] + 1));		// 
	printf("%d\n", arr1[1][2]);				// 8
	// printf("%d\n", arr1[2][-5]);			// 6, �̷������� �ڵ� �� �̸��� ������ �޸������� ������ ��.
}

// 2���� �迭�� �ݺ���
void exam3()
{
	int arr[5] = { 1,2,3,4,5 };
	for (int i = 0; i < 5; i++)
	{
		printf("%2d", arr[i]);
	}
	printf("\n\n");

	int arr1[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%3d", arr1[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

// �л� 2���� ��, ��, ��, �հ� ����
// ��� �л��� ���� �հ� ����
/*
		����	����	����	�հ�
--------------------------------------
�л�1	00		01		02		03
�л�2	10		11		12		13
--------------------------------------
�հ�	20		21		22		23
*/
void exam4()
{
	int jumsu[3][4] = { 0 };

	// ù ��° �л� ���� �Է�
	// ex)���� ���� scanf_s("%d", &jumsu[0][0]);

	printf("ù ��° �л��� ����, ����, �������� �Է� : ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &jumsu[0][i]);
	}
	for (int i = 0; i < 3 ; i++)
	{
		jumsu[0][3] = jumsu[0][3] + jumsu[0][i];
	}

	printf("�� ��° �л��� ����, ����, �������� �Է� : ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &jumsu[1][i]);
	}
	for (int i = 0; i < 3; i++)
	{
		jumsu[1][3] = jumsu[1][3] + jumsu[1][i];
	}

	// ���� ��(����)
	for (int i = 0; i < 2; i++)
	{
		jumsu[2][0] = jumsu[2][0] + jumsu[i][0];
	}
	

	// ��� ������ �ѹ��� ���ϱ�
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			jumsu[2][i] = jumsu[2][i] + jumsu[j][i];
		}
	}



	// ���
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%5d", jumsu[i][j]);
		}
		printf("\n");
	}
}