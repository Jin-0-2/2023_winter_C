// member.c
#include "std.h"

void member_print(const member* pmem)
{
	printf("%s \t %s\n", pmem->name, pmem->phone);
}

member member_create(const char* name, const char* phone)
{
	member mem;

	strcpy_s(mem.name, sizeof(mem.name), name);
	strcpy_s(mem.phone, sizeof(mem.phone), phone);

	return mem;
}

void member_println(const member* pmem)
{
	printf("아이디   : %s\n", pmem->name);
	printf("전화번호 : %s\n", pmem->phone);
}

void member_update(member* pmem, const char* phone)
{
	strcpy_s(pmem->phone, sizeof(pmem->phone), phone);
}