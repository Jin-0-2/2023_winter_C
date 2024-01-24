// control.c [����� ����]
/*
[ȸ������-���̵�(���ڿ�), ����(����), ����(����)] �������α׷�
*/
#include "std.h"

member g_members[DATA_MAX];

void con_init()
{
	for (int i = 0; i < 10; i++)
	{
		g_members[i].flag = 0;
	}
}

void con_printall()
{
	for (int i = 0; i < DATA_MAX; i++)
	{
		member mem = g_members[i];
		printf("[%2d]", i);
		if (mem.flag == 1)
			member_print(&mem);
		else
			prntf("\n");
	}
	printf("\n");
}

// �����Է� -> �������� ����
void con_insert()					// insert �˰���. 
{
	printf("[ȸ������]\n");

	int idx;
	char id[20], phone[20];
	int age;

	printf("������ ��ġ(0~%d) : ", DATA_MAX - 1);
	scanf_s("%d", &idx);
	char dummy = getchar();

	if (idx < 0 || idx > DATA_MAX)
	{
		printf("�߸��� ��ġ �Է�\n");
		return;
	}

	if (g_members[idx].flag == 1)
	{
		printf("�̹� ������� �ε����Դϴ�\n");
		return;
	}

	printf("ȸ���� ���̵� : ");					gets_s(id, sizeof(id));
	printf("ȸ���� ��ȭ��ȣ :");				gets_s(phone, sizeof(phone));
	printf("ȸ���� ����      : ");				scanf_s("%d", &age);
	dummy = getchar();
	

	member mem = member_create(id, phone, age);
	g_members[idx] = mem;

	printf("����Ǿ����ϴ�.\n");
}

// �˻������Է� -> [�˻�] -> ��� ���
void con_select()
{
	printf("[ȸ������ �˻�]\n");

	char id[20];
	printf("�˻��� ���̵� �Է� : ");			gets_s(id, sizeof(id));

	int idx = id_to_idx(id);

	if (idx != -1)
	{
		member_println(&g_members[idx]);
	}
	else
	{
		printf("���� ���̵��Դϴ�.");
	}
}

// �˻������Է� -> ������ ���� -> [�˻�] -> ���̸� ���� -> ��� ���
void con_update()
{
	printf("[ȸ������ ����]\n");

	char id[20];
	char phone[20];
	int age;
	printf("������ ���̵� �Է� : ");			gets_s(id, sizeof(id));
	printf("������ ��ȭ��ȣ�Է�: ");			gets_s(phone, sizeof(phone));
	printf("������ ���� �Է� : ");				scanf_s("%d", &age);
	char dummy = getchar();

	int idx = id_to_idx(id);

	if (idx != -1)
	{
		member_update(&g_members[idx], phone, age);
		printf("����Ǿ����ϴ�.");
	}
	else
	{
		printf("���� ���̵��Դϴ�.");
	}
}

// �˻������Է� -> [�˻�] -> ����ó�� -> ��� ���
void con_delete()
{
	printf("[ȸ������ ����]\n");


	char id[20];
	printf("������ ���̵� �Է� : ");			gets_s(id, sizeof(id));

	int idx = id_to_idx(id);

	if (idx != -1)
	{	
		member_delete(&g_members[idx]);

		printf("�����Ǿ����ϴ�.");
	}
	else
	{
		printf("���� ���̵��Դϴ�.");
	}
}

void con_exit()
{

}

// �迭�� �����˻� �˰���
int id_to_idx(const char* id)
{
	for (int i = 0; i < DATA_MAX; i++)
	{
		if (strcmp(g_members[i].id, id) == 0)
		{
			return i;
		}
	}
	return -1;
}