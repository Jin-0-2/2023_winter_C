// wbprint.cpp
#include "std.h"

void wbprint::logo()
{
	system("cls");
	printf("***************************************\n");
	printf("음료수 관리 관리프로그램\n");
	printf("2024-01-19\n");
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
	printf(" [1] 제품명 저장(insert)\n");
	printf(" [2] 제품명 검색(select)\n");
	printf(" [3] 제품명 수정(update)\n");
	printf(" [4] 제품명 삭제(delete)\n");
	printf(" [5] 프로그램종료(exit)\n");
	printf("***************************************\n");

}