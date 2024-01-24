// member.c
#include "std.h"

void drink_print(const drink* pmem)		// con_printall
{
	printf("%s \t %d \t %d\n", pmem->name, pmem->price, pmem->count);
}
//
drink drink_create(const char* name, const int price, const int count)		// con_insert
{
	drink mem;

	strcpy_s(mem.name, sizeof(mem.name), name);
	mem.price = price;
	mem.count = count;

	return mem;
}

void drink_println(const drink* pmem)		// con_select
{
	printf("이름 : %s\n", pmem->name);
	printf("가격 : %d\n", pmem->price);
	printf("개수 : %d\n", pmem->count);
}

void drink_update(drink* pmem, const int price)
{
	pmem->price = price;
}