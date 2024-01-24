// member.c
#include "std.h"

member member_create(const char* name, const char* phone, int age)
{
	member mem;
	
	mem.flag = 1;
	strcpy_s(mem.id, sizeof(mem.id), name);
	strcpy_s(mem.phone, sizeof(mem.phone), phone);
	mem.age = age;

	return mem;
}

void member_print(const member* pmem)
{
	printf("%s \t %s \t %d\n", pmem->id, pmem->phone, pmem->age);
}

void member_println(const member* pmem)
{
	printf("아이디   : %s\n", pmem->id);
	printf("전화번호 : %s\n", pmem->phone);
	printf("나이     : %d\n", pmem->age);
}

void member_update(member* pmem, const char* phone, int age)
{
	strcpy_s(pmem->phone, sizeof(pmem->phone), phone);
	pmem->age = age;
}

void member_delete(member* pmem)
{
	strcpy_s(pmem->id, sizeof(pmem->id), "");
	strcpy_s(pmem->phone, sizeof(pmem->phone), "");
	pmem->age = 0;
	pmem->flag = 0;
}
