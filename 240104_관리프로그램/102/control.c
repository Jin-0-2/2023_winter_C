// control.c [����� ����]
#include "std.h"
#define DATA_MAX 10

int g_flag[10];		//������ �������� �ľ� 1 or 0
int g_id[10];		//����(�����ؾ� ��)
int g_age[10];		//����		
char g_gender[10];	//����		
float g_weight[10];	//������

int g_arr[DATA_MAX]; // ���� ����


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
		printf("[%2d] ", i);
		if (g_flag[i] != 0)
			printf("%d \t %d \t %c\n, %.1f", g_id[i], g_age[i], g_gender[i], g_weight[i]);
		else
			printf("\n");
	}
	printf("\n");
}

// �����Է� -> �������� ����
void con_insert()					// insert �˰���. 
{
	printf("[ȸ������]\n");

	int idx;
	int id, age;
	char gender;

	printf("������ ��ġ(0~%d) : ", DATA_MAX - 1);
	scanf_s("%d", &idx);

	if (idx < 0 || idx > DATA_MAX)
	{
		printf("�߸��� ��ġ �Է�\n");
		return;
	}

	if (g_flag[idx] == 1)
	{
		printf("�̹� ������� �ε����Դϴ�\n");
		return;
	}

	printf("ȸ���� ���̵� : ");				scanf_s("%d", &id);

	for (int i = 0; i < DATA_MAX; i++)
	{
		if (g_id[i] == id)
		{
			printf("�̹� �����ϴ� ���̵��Դϴ�.\n");
			return;
		}
	}
	
	printf("ȸ���� ����      : ");				scanf_s("%d", &age);
	char dummy = getchar();
	printf("ȸ���� ����(m/w) : ");				scanf_s("%c", &gender, (int)sizeof(char));
	printf("ȸ���� ������(kg): ");				scanf_s("%f", &g_weight);

	g_flag[idx] = 1;
	g_id[idx] = id;
	g_age[idx] = age;
	g_gender[idx] = gender;
	

	printf("����Ǿ����ϴ�.\n");
}

// �˻������Է� -> [�˻�] -> ��� ���
void con_select()
{
	printf("[ȸ������ �˻�]\n");


	int id;
	printf("�˻��� ���̵� �Է� : ");			scanf_s("%d", &id);

	int idx = id_to_idx(id);

	if (idx != -1)
	{
		printf("���̵� : %d\n", g_id[idx]);
		printf("��  �� : %d\n", g_age[idx]);
		printf("��  �� : %c\n", g_gender[idx]);
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


	int id, age;
	char gender;
	printf("������ ���̵� �Է� : ");			scanf_s("%d", &id);
	printf("������ ���� �Է� : ");				scanf_s("%d", &age);
	char dummy = getchar();
	printf("������ ���� �Է�(m/w) : ");			scanf_s("%c", &gender, (int)sizeof(char));

	int idx = id_to_idx(id);

	if (idx != -1)
	{
		g_age[idx] = age;
		g_gender[idx] = gender;
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


	int id;
	printf("������ ���̵� �Է� : ");			scanf_s("%d", &id);

	int idx = id_to_idx(id);

	if (idx != -1)
	{	
		g_id[idx] = 0;
		g_age[idx] = 0;
		g_gender[idx] = 0;
		g_flag[idx] = 0;  // �߿� > ��������

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
int id_to_idx(int id)
{
	for (int i = 0; i < DATA_MAX; i++)
	{
		if (g_id[i] == id)
		{
			return i;
		}
	}
	return -1;
}