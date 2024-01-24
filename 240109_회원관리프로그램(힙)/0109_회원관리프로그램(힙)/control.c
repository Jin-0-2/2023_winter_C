// control.c [����� ����]
/*
[ȸ������-�̸�(���ڿ�), ��ȭ��ȣ(���ڿ�)] �������α׷�
*/
#include "std.h"

member* g_members;		// ���� �ִ� �迭 �ּ�	
int     g_size;			// ���� ���� == ���� ��ġ
int		g_max;			// ������ �ִ� ����


void con_init()
{
	system("cls");
	int max;
	printf("���� ���� : ");		scanf_s("%d", &max);
	char dummy = getchar();

	g_members = (member*)malloc(sizeof(member) * max);
	g_size    = 0;
	g_max     = max;
}

void con_printall()
{
	printf("[max: %d] \t [size : %d]\n", g_max, g_size);
	for (int i = 0; i < g_size; i++)
	{
		printf("[%2d]", i);
		member_print(&g_members[i]);
	}
	printf("\n");
}

// �����Է� -> �������� ����
void con_insert()					// insert �˰���. 
{
	printf("[ȸ������]\n");

	if (g_max <= g_size)
	{
		printf("Overflow\n");
		return;
	}

	char id[20], phone[20];

	printf("ȸ���� ���̵� : ");					gets_s(id, sizeof(id));
	printf("ȸ���� ��ȭ��ȣ :");				gets_s(phone, sizeof(phone));
	
	g_members[g_size++] = member_create(id, phone);

	printf("����Ǿ����ϴ�.\n");
}

// �˻������Է� -> [�˻�] -> ��� ���
void con_select()
{
	printf("[ȸ������ �˻�]\n");

	char name[20];
	printf("�˻��� ���̵� �Է� : ");			gets_s(name, sizeof(name));

	int idx = name_to_idx(name);

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

	char name[20], phone[20];

	printf("������ ���̵� �Է� : ");			gets_s(name, sizeof(name));
	printf("������ ��ȭ��ȣ�Է�: ");			gets_s(phone, sizeof(phone));

	int idx = name_to_idx(name);

	if (idx != -1)
	{
		member_update(&g_members[idx], phone);
		printf("����Ǿ����ϴ�.");
	}
	else
	{
		printf("���� ���̵��Դϴ�.");
	}
}

// �˻������Է� -> [�˻�] -> ����ó�� -> ��� ���
/*
--> 20�� �������� (�ε��� 1�� ���� ��������) 1[������ ��ġ]...3[g_size-1]
[4] 50
[3] 40 -> 50  arr[3] = arr[4]
[2] 30 -> 40  arr[2] = arr[3]
[1] 20 -> 30  arr[1] = arr[2]
[0] 10
*/
void con_delete()
{
	printf("[ȸ������ ����]\n");


	char name[20];
	printf("������ ���̵� �Է� : ");			gets_s(name, sizeof(name));

	int idx = name_to_idx(name);
	if (idx != -1)
	{	
		for (int i = idx; i <= g_size - 1; i++)
		{
			g_members[i] = g_members[i + 1];
		}
		g_size--;

		printf("�����Ǿ����ϴ�.");
	}
	else
	{
		printf("���� ���̵��Դϴ�.");
	}
}

void con_exit()
{
	free(g_members);
	g_members = NULL;
}

// �迭�� �����˻� �˰���
int name_to_idx(const char* name)
{
	for (int i = 0; i < g_size; i++)
	{
		if (strcmp(g_members[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}