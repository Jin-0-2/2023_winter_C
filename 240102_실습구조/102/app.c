// app.c [흐름]

#include "std.h"

void app_init()
{
	logo();
	con_init();
}

void app_run()
{
	while (1)
	{
		system("cls");
		con_printall();
		menuprint();
		char ch = _getch();  // 문자 입력(출력 X, 즉각반응)
		switch (ch)
		{
		case '1': con_insert();		    break;
		case '2': printf("[select]\n"); break;
		case '3': printf("[update]\n"); break;
		case '4': con_delete();		    break;  // switch문 끝내기
		case '5': return;     // 함수 끝내기
		}
		system("pause");
	}
}

void app_exit()
{
	ending();
}


void logo()
{
	system("cls");
	printf("***************************\n");
	printf("2023 겨울학기 비트 단기과정\n");
	printf("C언어 기반 코드 구조\n");
	printf("2024-01-02\n");
	printf("정진영\n");
	printf("***************************\n");
	system("pause");
}

void menuprint()
{
	printf("***************************\n");
	printf(" [1] insert\n");
	printf(" [2] select\n");
	printf(" [3] update\n");
	printf(" [4] delete\n");
	printf(" [5] exit\n");
	printf("***************************\n");
}

void ending()
{
	system("cls");
	printf("***************************\n");
	printf("프로그램을 종료합니다.\n");
	printf("***************************\n");
	system("pause");
}