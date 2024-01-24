// wbfile.c
#include "std.h"

#define FILE_NAME "members.txt"

extern	member* g_members;		// ���� �ִ� �迭 �ּ�	
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

	//������
	for (int i = 0; i < g_size; i++)
	{
		fprintf(fp, "%s %s\n", g_members[i].name, g_members[i].phone);
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
	g_members = (member*)malloc(sizeof(member) * max);
	//------------------------------------------------------


	// data
	for (int i = 0; i < size; i++)
	{
		fscanf_s(fp, "%s %s",
			g_members[i].name, (int)sizeof(g_members[i].name), 
			g_members[i].phone, (int)sizeof(g_members[i].phone));
	}

	fclose(fp);
	return 1;
}
void file_save1()
{
	FILE* fp;
	int  ret = fopen_s(&fp, FILE_NAME, "wb");
	if (ret != 0)
	{
		printf("���Ͽ������\n");
		return;
	}

	// head : �ִ� ���尳��, ���� ����� ����
	fwrite(&g_max, sizeof(int), 1, fp);
	fwrite(&g_size, sizeof(int), 1, fp);

	//������
	fwrite(g_members, sizeof(member), g_size, fp);

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
	fread(&g_max, sizeof(int), 1, fp);
	fread(&g_size, sizeof(int), 1, fp);

	//------------------------------------------------------
	g_members = (member*)malloc(sizeof(member) * g_max);
	//------------------------------------------------------

	//������
	fread(g_members, sizeof(member), g_size, fp);


	fclose(fp);

	return 1;
}