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
		char ch = _getch();
		switch (ch)
		{
		case '1': con_insert();		    break;
		case '2': con_select();		    break;
		case '3': con_update();			break;
		case '4': con_delete();		    break;
		case '5': con_clsprint();		break;
		case '6': return;
		}
		system("pause");
	}
}

void app_exit()
{
	ending();
	con_exit();
}

void logo()
{
	system("cls");
	printf("***************************\n");
	printf("2023 겨울학기 비트 단기과정\n");
	printf("C언어 기반 관리프로그램\n");
	printf("2024-01-10\n");
	printf("정진영 C언어 음료수 관리프로그램\n");
	printf("***************************\n");
	system("pause");
}

void menuprint()
{
	printf("***************************\n");
	printf(" [1] 음료저장(insert)\n");
	printf(" [2] 음료검색(select)\n");
	printf(" [3] 음료수정(update)\n");
	printf(" [4] 음료삭제(delete)\n");
	printf(" [5] 전체출력(allprint)\n");
	printf(" [6] 프로그램 종료(exit)\n");
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