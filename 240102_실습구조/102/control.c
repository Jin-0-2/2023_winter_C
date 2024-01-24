// control.c [����� ����]
#include "std.h"


// �������� : �Լ� �ܺο� �����ϴ� ����, ������ ���� ����
// �������� : �Լ� ���ο� �����ϴ� ����, �ش� �Լ������� ���� ����
#define DATA_MAX 10

int g_arr[DATA_MAX]; // ���� ����


void con_init()
{
	for (int i = 0; i < 10; i++)
	{
		g_arr[i] = -1;
	}
}

void con_printall()
{
	for (int i = 0; i < 10; i++)
	{
		printf("[%03d] %d\n", i, g_arr[i]);
	}
	printf("\n");
}

void con_insert()					// insert �˰���. 
{
	printf("[insert]\n");

	int number;
	int idx;

	printf("������ ��ġ(0~%d) : ", DATA_MAX -1);
	scanf_s("%d", &idx);

	if (idx < 0 || idx > DATA_MAX)
	{
		printf("�߸��� ��ġ �Է�\n");
		return;
	}

	printf("������ ���� : ");
	scanf_s("%d", &number);

	g_arr[idx] = number;

	printf("����Ǿ����ϴ�.\n");
}

void con_select()
{

}

void con_update()
{

}

void con_delete()
{
	printf("[delete]\n");

	int number;


	printf("������ ���� : ");
	scanf_s("%d", &number);

	// �����˻� > �ݺ���
	for (int i = 0; i < DATA_MAX; i++)
	{
		if (g_arr[i] == number)
		{
			g_arr[i] = -1;
			printf("�����Ǿ����ϴ�.");
			return;
		}
	}
	printf("���� �����Դϴ�.\n");
}

void con_exit()
{

}