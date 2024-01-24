// app.c [�帧]

#include "std.h"

void app_init()
{
	logo();
	con_init();
}

void app_run()
{
	while (1)
	{
		system("cls");
		con_printall();
		menuprint();
		char ch = _getch();  // ���� �Է�(��� X, �ﰢ����)
		switch (ch)
		{
		case '1': con_insert();		    break;
		case '2': printf("[select]\n"); break;
		case '3': printf("[update]\n"); break;
		case '4': con_delete();		    break;  // switch�� ������
		case '5': return;     // �Լ� ������
		}
		system("pause");
	}
}

void app_exit()
{
	ending();
}


void logo()
{
	system("cls");
	printf("***************************\n");
	printf("2023 �ܿ��б� ��Ʈ �ܱ����\n");
	printf("C��� ��� �ڵ� ����\n");
	printf("2024-01-02\n");
	printf("������\n");
	printf("***************************\n");
	system("pause");
}

void menuprint()
{
	printf("***************************\n");
	printf(" [1] insert\n");
	printf(" [2] select\n");
	printf(" [3] update\n");
	printf(" [4] delete\n");
	printf(" [5] exit\n");
	printf("***************************\n");
}

void ending()
{
	system("cls");
	printf("***************************\n");
	printf("���α׷��� �����մϴ�.\n");
	printf("***************************\n");
	system("pause");
}