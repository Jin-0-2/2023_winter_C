// control.c [기능의 시작]
#include "std.h"


// 전역변수 : 함수 외부에 선언하는 변수, 누구나 접근 가능
// 지역변수 : 함수 내부에 선언하는 변수, 해당 함수에서만 접근 가능
#define DATA_MAX 10

int g_arr[DATA_MAX]; // 전역 변수


void con_init()
{
	for (int i = 0; i < 10; i++)
	{
		g_arr[i] = -1;
	}
}

void con_printall()
{
	for (int i = 0; i < 10; i++)
	{
		printf("[%03d] %d\n", i, g_arr[i]);
	}
	printf("\n");
}

void con_insert()					// insert 알고리즘. 
{
	printf("[insert]\n");

	int number;
	int idx;

	printf("저장할 위치(0~%d) : ", DATA_MAX -1);
	scanf_s("%d", &idx);

	if (idx < 0 || idx > DATA_MAX)
	{
		printf("잘못된 위치 입력\n");
		return;
	}

	printf("저장할 정수 : ");
	scanf_s("%d", &number);

	g_arr[idx] = number;

	printf("저장되었습니다.\n");
}

void con_select()
{

}

void con_update()
{

}

void con_delete()
{
	printf("[delete]\n");

	int number;


	printf("삭제할 정수 : ");
	scanf_s("%d", &number);

	// 순차검색 > 반복문
	for (int i = 0; i < DATA_MAX; i++)
	{
		if (g_arr[i] == number)
		{
			g_arr[i] = -1;
			printf("삭제되었습니다.");
			return;
		}
	}
	printf("없는 정수입니다.\n");
}

void con_exit()
{

}