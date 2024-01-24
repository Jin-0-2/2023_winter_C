//member.h

#pragma once

typedef struct tagdrink drink;

struct tagdrink
{
	char name[20];
	int price;
	int count;
};

drink drink_create(const char* name, const int price, const int count);

void drink_print(const drink* pmem);

void drink_println(const drink* pmem);

// update���� Ȱ��(���޵� ȸ�������� 2nd, 3nd ���ڷ� ����)
void drink_update(drink* pmem, const int price);