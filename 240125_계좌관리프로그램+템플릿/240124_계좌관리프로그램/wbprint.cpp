// wbprint.cpp
#include "std.h"

void wbprint::logo()
{
	system("cls");
	printf("***************************************\n");
	printf("계좌 관리 관리프로그램\n");
	printf("2024-01-24\n");
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
	printf(" [1] 계좌 저장(insert)\n");
	printf(" [2] 계좌 검색(select)\n");
	printf(" [3] 계좌 입금(update)\n");
	printf(" [4] 계좌 출금(update)\n");
	printf(" [5] 계좌 삭제(delete)\n");
	printf(" [6] 프로그램종료(exit)\n");
	printf("***************************************\n");

}