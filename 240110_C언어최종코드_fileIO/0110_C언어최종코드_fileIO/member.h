//member.h

#pragma once

typedef struct tagmember member;

struct tagmember
{
	char name[20];
	char phone[20];
};
// printall���� Ȱ��(���޵� ȸ�������� ���ٿ� ���)
void member_print(const member* pmem);

// insert���� Ȱ��(member mem �������� -> ���޵� ������ �ʱ�ȭ)
member member_create(const char* name, const char* phone);

// select���� Ȱ�� (���޵� ȸ�������� �����ٿ� ���)
void member_println(const member* pmem);

// update���� Ȱ��(���޵� ȸ�������� 2nd, 3nd ���ڷ� ����)
void member_update(member* pmem, const char* phone);