// wbfile.c
#include "std.h"

#define FILE_NAME "drink.txt"

extern	drink* g_drink;			// 힙에 있는 배열 주소	
extern	int     g_size;			// 저장 개수 == 저장 위치
extern	int		g_max;			// 저장할 최대 개수

void file_save()
{
	FILE* fp;
	int  ret = fopen_s(&fp, FILE_NAME, "w");
	if (ret != 0)
	{
		printf("파일열기실패\n");
		return;
	}

	// head : 최대 저장개수, 현재 저장된 개수
	fprintf(fp, "%d\n", g_max);
	fprintf(fp, "%d\n", g_size);

	// 데이터
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
		printf("파일열기실패\n");
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
	int  ret = fopen_s(&fp, FILE_NAME, "wb");		// 성공시 0 반환
	if (ret != 0)
	{
		printf("파일열기실패\n");
		return;
	}

	// head : 최대 저장개수, 현재 저장된 개수
	fwrite(&g_max, sizeof(int), 1, fp);		// (주소에 있는 값을, size이만함, 몇개, 여기에 저장할거)
	fwrite(&g_size, sizeof(int), 1, fp);

	//데이터
	fwrite(g_drink, sizeof(drink), g_size, fp);

	fclose(fp);
}
int file_load1()
{
	FILE* fp;
	int  ret = fopen_s(&fp, FILE_NAME, "rb");
	if (ret != 0)
	{
		printf("파일열기실패\n");
		return 0;
	}

	// head : 최대 저장개수, 현재 저장된 개수
	fread(&g_max, sizeof(int), 1, fp);	// (주소에 있는 값을, size이만함, 몇개, 읽어올거)
	fread(&g_size, sizeof(int), 1, fp);

	//-----------------------------------------------------
	g_drink = (drink*)malloc(sizeof(drink) * g_max);
	//------------------------------------------------------

	//데이터
	fread(g_drink, sizeof(drink), g_size, fp);

	fclose(fp);

	return 1;
}