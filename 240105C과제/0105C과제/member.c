// member.c
#include "std.h"

void member_print(int i, int flag, char* name, char* phone, int age)
{
	printf("[%2d]\t", i);
	if (flag != 0)
		printf("%s \t %s \t %d\n", name, phone, age);
	else
		printf("\n");
}

void member_println(char* name, char* phone, int age)
{
	printf("이    름 : %s\n", name);
	printf("전화번호 : %s\n", phone);
	printf("나    이 : %d\n", age);
}

int member_idx_check(int idx, int flag)
{
	if (idx < 0 || idx > DATA_MAX)
	{
		printf("잘못된 위치 입력\n");
		char dummy = getchar();

		return 0;
	}

	if (flag == 1)
	{
		printf("이미 사용중인 인덱스입니다\n");
		return 0;
	}
	return 1;
}

int member_insert(int* flag, char* name, char* phone, int* age, const char* n, const char* p, int a)
{
	strcpy_s(name, sizeof(char) * 20, n);
	strcpy_s(phone, sizeof(char) * 20, p);
	*age = a;
	*flag = 1;

	return 1;
}

int member_update(char* phone, int* age, const char* p, const int a)
{
	strcpy_s(phone, sizeof(phone) * 20, p);
	*age = a;

	return 1;
}

int member_delete(char* name, char* phone, int* age, int* flag)
{
	*flag = 0;
	strcpy_s(name, sizeof(char) * 20, "");
	strcpy_s(phone, sizeof(char) * 20, "");
	*age = 0;

	return 0;
}