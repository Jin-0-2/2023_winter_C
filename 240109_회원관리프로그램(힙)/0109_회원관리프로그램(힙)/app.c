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
		case '2': con_select();		    break;
		case '3': con_update();			break;
		case '4': con_delete();		    break;  // switch문 끝내기
		case '5': return;     // 함수 끝내기
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
	printf("2024-01-09\n");
	printf("정진영(구조체 메모리)\n");
	printf("***************************\n");
	system("pause");
}

void menuprint()
{
	printf("***************************\n");
	printf(" [1] 회원저장(insert)\n");
	printf(" [2] 회원검색(select)\n");
	printf(" [3] 회원수정(update)\n");
	printf(" [4] 회원삭제(delete)\n");
	printf(" [5] 프로그램 종료(exit)\n");
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