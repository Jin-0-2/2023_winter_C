// wbfile.c
#include "std.h"

#define FILE_NAME "drink.txt"

extern	drink* g_drink;			// ���� �ִ� �迭 �ּ�	
extern	int     g_size;			// ���� ���� == ���� ��ġ
extern	int		g_max;			// ������ �ִ� ����

void file_save()
{
	FILE* fp;
	int  ret = fopen_s(&fp, FILE_NAME, "w");
	if (ret != 0)
	{
		printf("���Ͽ������\n");
		return;
	}

	// head : �ִ� ���尳��, ���� ����� ����
	fprintf(fp, "%d\n", g_max);
	fprintf(fp, "%d\n", g_size);

	// ������
	for (int i = 0; i < g_size; i++)
	{
		fprintf(fp, "%s %d %d\n", g_drink[i].name, g_drink[i].price, g_drink[i].count);
	}


	fclose(fp);
}
int file_load()
{
	FILE* fp;
	int  ret = fopen_s(&fp, FILE_NAME, "r");
	if (ret != 0)
	{
		printf("���Ͽ������\n");
		return 0;
	}

	// head
	int max, size;
	fscanf_s(fp, "%d", &max);
	fscanf_s(fp, "%d\n", &size);

	//------------------------------------------------------
	g_max = max;
	g_size = size;
	g_drink = (drink*)malloc(sizeof(drink) * max);
	//------------------------------------------------------


	// data
	for (int i = 0; i < size; i++)
	{
		fscanf_s(fp, "%s %d %d",
			g_drink[i].name, (int)sizeof(g_drink[i].name),
			&g_drink[i].price,
			&g_drink[i].count);
	}
	fclose(fp);

	return 1;
}
void file_save1()
{
	FILE* fp;
	int  ret = fopen_s(&fp, FILE_NAME, "wb");		// ������ 0 ��ȯ
	if (ret != 0)
	{
		printf("���Ͽ������\n");
		return;
	}

	// head : �ִ� ���尳��, ���� ����� ����
	fwrite(&g_max, sizeof(int), 1, fp);		// (�ּҿ� �ִ� ����, size�̸���, �, ���⿡ �����Ұ�)
	fwrite(&g_size, sizeof(int), 1, fp);

	//������
	fwrite(g_drink, sizeof(drink), g_size, fp);

	fclose(fp);
}
int file_load1()
{
	FILE* fp;
	int  ret = fopen_s(&fp, FILE_NAME, "rb");
	if (ret != 0)
	{
		printf("���Ͽ������\n");
		return 0;
	}

	// head : �ִ� ���尳��, ���� ����� ����
	fread(&g_max, sizeof(int), 1, fp);	// (�ּҿ� �ִ� ����, size�̸���, �, �о�ð�)
	fread(&g_size, sizeof(int), 1, fp);

	//-----------------------------------------------------
	g_drink = (drink*)malloc(sizeof(drink) * g_max);
	//------------------------------------------------------

	//������
	fread(g_drink, sizeof(drink), g_size, fp);

	fclose(fp);

	return 1;
}