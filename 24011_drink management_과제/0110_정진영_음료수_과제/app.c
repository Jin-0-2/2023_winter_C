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
		char ch = _getch();
		switch (ch)
		{
		case '1': con_insert();		    break;
		case '2': con_select();		    break;
		case '3': con_update();			break;
		case '4': con_delete();		    break;
		case '5': con_clsprint();		break;
		case '6': return;
		}
		system("pause");
	}
}

void app_exit()
{
	ending();
	con_exit();
}

void logo()
{
	system("cls");
	printf("***************************\n");
	printf("2023 �ܿ��б� ��Ʈ �ܱ����\n");
	printf("C��� ��� �������α׷�\n");
	printf("2024-01-10\n");
	printf("������ C��� ����� �������α׷�\n");
	printf("***************************\n");
	system("pause");
}

void menuprint()
{
	printf("***************************\n");
	printf(" [1] ��������(insert)\n");
	printf(" [2] ����˻�(select)\n");
	printf(" [3] �������(update)\n");
	printf(" [4] �������(delete)\n");
	printf(" [5] ��ü���(allprint)\n");
	printf(" [6] ���α׷� ����(exit)\n");
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