//member.h

#pragma once
#define DATA_MAX 10

typedef struct tagmember member;

struct tagmember
{
	int flag;
	char id[20];
	char phone[20];
	int age;
};

// insert���� Ȱ��(member mem �������� -> ���޵� ������ �ʱ�ȭ, flag�� 1�� -> mem ��ȯ)
member member_create(const char* name, const char* phone, int age);

// printall���� Ȱ��(���޵� ȸ�������� ���ٿ� ���)
void member_print(const member* pmem);

// select���� Ȱ�� (���޵� ȸ�������� �����ٿ� ���)
void member_println(const member* pmem);

// update���� Ȱ��(���޵� ȸ�������� 2nd, 3nd ���ڷ� ����)
void member_update(member* pmem, const char* phone, int age);

// delete���� Ȱ��(���޵� ȸ�������� "","",0���� �ʱ�ȭ, flag�� 0���� �ʱ�ȭ
void member_delete(member* pmem);