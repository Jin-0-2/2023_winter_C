// 01_2차원 배열.c

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
2차원 배열의 선언
*/
void exam1()
{
	// [공통]정수 56개 저장
	// [차이] 00 01 02 10 11 12		vs		00 01 10 11 20 21
	// [타입] int(*)[3]  vs  int(*)[2]
	int arr1[2][3] = { {1,2,3}, {4,5,6} };
	int arr2[3][2] = { {1,2}, {3,4}, {5,6} };
}

// 주소 확인을 위해 x86으로 변경
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
	// printf("%d\n", arr1[2][-5]);			// 6, 이런식으로 코딩 할 이릉ㄴ 없지만 메모리적으로 가능한 것.
}

// 2차원 배열과 반복문
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

// 학생 2명의 국, 영, 수, 합계 저장
// 모든 학생의 과목별 합계 저장
/*
		국어	영어	수학	합계
--------------------------------------
학생1	00		01		02		03
학생2	10		11		12		13
--------------------------------------
합계	20		21		22		23
*/
void exam4()
{
	int jumsu[3][4] = { 0 };

	// 첫 번째 학생 점수 입력
	// ex)국어 점수 scanf_s("%d", &jumsu[0][0]);

	printf("첫 번째 학생의 국어, 영어, 수학점수 입력 : ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &jumsu[0][i]);
	}
	for (int i = 0; i < 3 ; i++)
	{
		jumsu[0][3] = jumsu[0][3] + jumsu[0][i];
	}

	printf("두 번째 학생의 국어, 영어, 수학점수 입력 : ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &jumsu[1][i]);
	}
	for (int i = 0; i < 3; i++)
	{
		jumsu[1][3] = jumsu[1][3] + jumsu[1][i];
	}

	// 과목별 합(국어)
	for (int i = 0; i < 2; i++)
	{
		jumsu[2][0] = jumsu[2][0] + jumsu[i][0];
	}
	

	// 모든 과목을 한번에 더하기
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			jumsu[2][i] = jumsu[2][i] + jumsu[j][i];
		}
	}



	// 출력
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%5d", jumsu[i][j]);
		}
		printf("\n");
	}
}