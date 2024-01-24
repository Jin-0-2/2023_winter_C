// control.c [����� ����]
/*
[ȸ������-�̸�(���ڿ�), ��ȭ��ȣ(���ڿ�)] �������α׷�
*/
#include "std.h"

drink* g_drink;			// ���� �ִ� �迭 �ּ�	
int     g_size;			// ���� ���� == ���� ��ġ
int		g_max;			// ������ �ִ� ����


void con_init()
{
	system("cls");

	if (file_load1() == 0)
	{
		int max;
		printf("���� ���� : ");		scanf_s("%d", &max);
		char dummy = getchar();

		g_drink = (drink*)malloc(sizeof(drink) * max);
		g_size    = 0;
		g_max     = max;
	}
}

void con_printall()
{
	printf("[max: %d] \t [size : %d]\n", g_max, g_size);
	for (int i = 0; i < g_size; i++)
	{
		printf("[%2d]", i);
		drink_print(&g_drink[i]);
	}
	printf("\n");
}

// �����Է� -> �������� ����
void con_insert()					// insert �˰���. 
{
	printf("[��������]\n");

	if (g_max <= g_size)
	{
		printf("Overflow\n");
		return;
	}
	
	char name[20];
	int price, count;

	printf("���� �̸� : ");					gets_s(name, sizeof(name));
	printf("������ ���� :");				scanf_s("%d", &price);
	printf("������ ���� :");				scanf_s("%d", &count);
	char dummy = getchar();

	g_drink[g_size++] = drink_create(name, price, count);

	printf("����Ǿ����ϴ�.\n");
}

// �˻������Է� -> [�˻�] -> ��� ���
void con_select()
{
	printf("[�������� �˻�]\n");

	char name[20];
	printf("�˻��� ���� �̸� �Է� : ");			gets_s(name, sizeof(name));

	int idx = name_to_idx(name);

	if (idx != -1)
	{
		drink_println(&g_drink[idx]);
	}
	else
	{
		printf("���� �����Դϴ�.");
	}
}

// �˻������Է� -> ������ �̸� -> [�˻�] -> ���ݸ� ���� -> ��� ���
void con_update()
{
	printf("[�������� ����]\n");

	char name[20];
	int price;

	printf("������ ���� �̸� �Է� : ");			gets_s(name, sizeof(name));
	printf("������ ���� �Է�: ");				scanf_s("%d", &price);
	char dummy = getchar();

	int idx = name_to_idx(name);

	if (idx != -1)
	{
		drink_update(&g_drink[idx], price);
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
	printf("[�������� ����]\n");


	char name[20];
	printf("������ �����̸� �Է� : ");			gets_s(name, sizeof(name));

	int idx = name_to_idx(name);
	if (idx != -1)
	{	
		for (int i = idx; i <= g_size - 1; i++)
		{
			g_drink[i] = g_drink[i + 1];
		}
		g_size--;

		printf("�����Ǿ����ϴ�.");
	}
	else
	{
		printf("���� ���̵��Դϴ�.");
	}
}

void con_clsprint()
{
	system("cls");
	printf("---------[��ü���]---------\n");
	con_printall();
	printf("----------------------------\n");
}

void con_exit()
{
	file_save1();

	free(g_drink);
	g_drink = NULL;
}

// �迭�� �����˻� �˰���
int name_to_idx(const char* name)
{
	for (int i = 0; i < g_size; i++)
	{
		if (strcmp(g_drink[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}