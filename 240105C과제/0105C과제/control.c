// control.c [����� ����]
#include "std.h"

int g_flag[DATA_MAX];			//������ �������� �ľ� 1 or 0
char g_name[DATA_MAX][20];		//�̸�
char g_phone[DATA_MAX][20];		//��ȣ
int g_age[DATA_MAX];			//����

void con_init()
{
	for (int i = 0; i < 10; i++)
	{
		g_flag[i] = 0;
	}
}

void con_printall()
{
	for (int i = 0; i < DATA_MAX; i++)
	{
		member_print(i, g_flag[i], g_name[i], g_phone[i], g_age[i]);
	}
	printf("\n");
}

// �����Է� -> �������� ����
void con_insert()		
{
	printf("[ȸ������]\n");

	int idx;
	char name[20], phone[20];
	int age;

	printf("������ ��ġ(0~%d) : ", DATA_MAX - 1);
	scanf_s("%d", &idx);
	char dummy = getchar();

	if (member_idx_check(idx, g_flag[idx]) == 0)
		return;


	printf("��    �� : ");			gets_s(name, sizeof(name));
	printf("��ȭ��ȣ : ");			gets_s(phone, sizeof(phone));
	printf("��    �� : ");			scanf_s("%d", &age);
	dummy = getchar();
	
	member_insert(&g_flag[idx], g_name[idx], g_phone[idx], &g_age[idx], name, phone, age);

	printf("����Ǿ����ϴ�.\n");
}

// �˻������Է� -> [�˻�] -> ��� ���
void con_select()
{
	printf("[ȸ������ �˻�]\n");
	
	char name[20];
	printf("�˻��� �̸� �Է� : ");		gets_s(name, sizeof(name));

	int idx = name_to_idx(name);

	if (idx != -1)
		member_println(g_name[idx], g_phone[idx], g_age[idx]);
	else
		printf("���� ���̵��Դϴ�.\n");
}

// �˻������Է� -> ������ ���� -> [�˻�] -> ���̸� ���� -> ��� ���
void con_update()
{
	printf("[ȸ������ ����]\n");

	int age;
	char phone[20], name[20];

	printf("������ �̸� �Է� : ");			gets_s(name, sizeof(name));
	printf("������ ��ȭ��ȣ �Է� : ");				gets_s(phone, sizeof(phone));
	printf("������ ���� �Է�     : ");				scanf_s("%d", &age);
	char dummy = getchar();
	
	int idx = name_to_idx(name);
	if (idx != -1)
	{
		member_update(g_phone[idx], &g_age[idx], phone, age);
		printf("����Ǿ����ϴ�.\n");
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

	char name[20];

	printf("������ �̸� �Է� : ");			gets_s(name, sizeof(name));

	int idx = name_to_idx(name);

	if (idx != -1)
	{
		member_delete(g_name[idx], g_phone[idx], &g_age[idx], &g_flag[idx]);
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
int name_to_idx(char* name)
{
	for (int i = 0; i < DATA_MAX; i++)
	{
		if (strcmp(g_name[i], name) == 0)
		{
			return i;
		}
	}
	return -1;
}