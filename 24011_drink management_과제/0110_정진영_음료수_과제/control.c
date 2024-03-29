// control.c [기능의 시작]
/*
[회원정보-이름(문자열), 전화번호(문자열)] 관리프로그램
*/
#include "std.h"

drink* g_drink;			// 힙에 있는 배열 주소	
int     g_size;			// 저장 개수 == 저장 위치
int		g_max;			// 저장할 최대 개수


void con_init()
{
	system("cls");

	if (file_load1() == 0)
	{
		int max;
		printf("저장 개수 : ");		scanf_s("%d", &max);
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

// 정보입력 -> 전역변수 저장
void con_insert()					// insert 알고리즘. 
{
	printf("[음료저장]\n");

	if (g_max <= g_size)
	{
		printf("Overflow\n");
		return;
	}
	
	char name[20];
	int price, count;

	printf("음료 이름 : ");					gets_s(name, sizeof(name));
	printf("음료의 가격 :");				scanf_s("%d", &price);
	printf("음료의 개수 :");				scanf_s("%d", &count);
	char dummy = getchar();

	g_drink[g_size++] = drink_create(name, price, count);

	printf("저장되었습니다.\n");
}

// 검색정보입력 -> [검색] -> 결과 출력
void con_select()
{
	printf("[음료정보 검색]\n");

	char name[20];
	printf("검색할 음료 이름 입력 : ");			gets_s(name, sizeof(name));

	int idx = name_to_idx(name);

	if (idx != -1)
	{
		drink_println(&g_drink[idx]);
	}
	else
	{
		printf("없는 음료입니다.");
	}
}

// 검색정보입력 -> 수정할 이름 -> [검색] -> 가격를 수정 -> 결과 출력
void con_update()
{
	printf("[음료정보 변경]\n");

	char name[20];
	int price;

	printf("변경할 음료 이름 입력 : ");			gets_s(name, sizeof(name));
	printf("변경할 가격 입력: ");				scanf_s("%d", &price);
	char dummy = getchar();

	int idx = name_to_idx(name);

	if (idx != -1)
	{
		drink_update(&g_drink[idx], price);
		printf("변경되었습니다.");
	}
	else
	{
		printf("없는 아이디입니다.");
	}
}

// 검색정보입력 -> [검색] -> 삭제처리 -> 결과 출력
/*
--> 20을 삭제해줘 (인덱스 1의 값을 삭제해줘) 1[삭제할 위치]...3[g_size-1]
[4] 50
[3] 40 -> 50  arr[3] = arr[4]
[2] 30 -> 40  arr[2] = arr[3]
[1] 20 -> 30  arr[1] = arr[2]
[0] 10
*/
void con_delete()
{
	printf("[음료정보 삭제]\n");


	char name[20];
	printf("삭제할 음료이름 입력 : ");			gets_s(name, sizeof(name));

	int idx = name_to_idx(name);
	if (idx != -1)
	{	
		for (int i = idx; i <= g_size - 1; i++)
		{
			g_drink[i] = g_drink[i + 1];
		}
		g_size--;

		printf("삭제되었습니다.");
	}
	else
	{
		printf("없는 아이디입니다.");
	}
}

void con_clsprint()
{
	system("cls");
	printf("---------[전체출력]---------\n");
	con_printall();
	printf("----------------------------\n");
}

void con_exit()
{
	file_save1();

	free(g_drink);
	g_drink = NULL;
}

// 배열의 순차검색 알고리즘
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