#include "std.h"

void wbprint::logo()
{
	system("cls");
	printf("***************************************\n");
	printf("회원관리프로그램\n");
	printf("2024-02-02\n");
	printf("정진영\n");
	printf("***************************************\n");
	system("pause");

}

void wbprint::ending()
{
	system("cls");
	printf("***************************************\n");
	printf("프로그램을 종료합니다\n");
	printf("***************************************\n");
	system("pause");

}

void wbprint::menuprint()
{
	printf("***************************************\n");
	printf(" [1] 회원 저장(insert)\n");
	printf(" [2] 회원 검색(select)\n");
	printf(" [3] 회원 수정(update)\n");
	printf(" [4] 회원 삭제(delete)\n");
	printf(" [5] 프로그램종료(exit)\n");
	printf("***************************************\n");

}