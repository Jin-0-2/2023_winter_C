// 04_2�����迭.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 30
#define COL 40

void arr_randominsert(char(*arr)[COL], int r, int c);
void arr_printall(const char(*arr)[COL], int r, int c);
void arr_row_print(const char(*arr)[COL], int r, int c, int select);
int get_arrdata(const char(*arr)[COL], int r, int c, int x, int y, char* ch);
int set_arrdata(char(*arr)[COL], int r, int c, int x, int y, char ch);
int arr_count(char* arr, int size, char ch);

int main()
{
	char arr[ROW][COL];

	arr_randominsert(arr, ROW, COL);
	arr_printall(arr, ROW, COL);
	printf("\n");
	arr_row_print(arr, ROW, COL, 10);

	char ch;
	int ret = get_arrdata(arr,ROW, COL, 5, 5, &ch);
	if (ret == 1)
		printf("%c\n", ch);
	else
		printf("�߸��� �ε��� ����\n");

	printf("\n");

	ret = set_arrdata(arr, ROW, COL, 5, 5, 'E');
	if (ret == 1)
		printf("����\n");
	
	else
		printf("����\n");
	int count = arr_count((char*)arr, ROW*COL, 'A');
	printf("%d��\n", count);
	

	return 0;
}

void arr_randominsert(char(*arr)[COL], int r, int c)
{
	srand((unsigned int)time(0));
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			arr[i][j] = rand()%26 + 'A';		// A~Z
		}
	}
}

void arr_printall(const char(*arr)[COL], int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		printf("[%2d]", i);
		for (int j = 0; j < c; j++)
		{
			printf("%2c", arr[i][j]);
		}
		printf("\n");
	}
	
}

void arr_row_print(const char(*arr)[COL], int r, int c, int select)
{
	if (select < 0 || select >= r)
	{
		printf("���� �ε���\n");
		return;
	}

	printf("[%2d]", select);
	for (int j = 0; j < c; j++)
	{
		printf("%2c", arr[select][j]);
	}
	printf("\n");
}

int get_arrdata(const char(*arr)[COL], int r, int c, int x, int y, char* ch)
{
	if (x < 0 || x >= r)
	{
		printf("�߸��� ROW\n");
		return 0;
	}

	if (y < 0 || y >= c)
	{
		printf("�߸��� COL\n");
		return 0;
	}

	*ch = arr[x][y];
	return 1;
}

int set_arrdata(char(*arr)[COL], int r, int c, int x, int y, char ch)
{
	if (x < 0 || x >= r)
	{
		printf("�߸��� ROW\n");
		return 0;
	}

	if (y < 0 || y >= c)
	{
		printf("�߸��� COL\n");
		return 0;
	}
	arr[x][y] = ch;

	return 1;
}

int arr_count(char* arr, int size, char ch)
{	
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == ch)
			count++;
	}
	return count;
}