// control.c [기능의 시작]
/*
[회원정보-아이디(문자열), 나이(정수), 성별(문자)] 관리프로그램
*/
#include "std.h"

member g_members[DATA_MAX];

void con_init()
{
	for (int i = 0; i < 10; i++)
	{
		g_members[i].flag = 0;
	}
}

void con_printall()
{
	for (int i = 0; i < DATA_MAX; i++)
	{
		member mem = g_members[i];
		printf("[%2d]", i);
		if (mem.flag == 1)
			member_print(&mem);
		else
			prntf("\n");
	}
	printf("\n");
}

// 정보입력 -> 전역변수 저장
void con_insert()					// insert 알고리즘. 
{
	printf("[회원저장]\n");

	int idx;
	char id[20], phone[20];
	int age;

	printf("저장할 위치(0~%d) : ", DATA_MAX - 1);
	scanf_s("%d", &idx);
	char dummy = getchar();

	if (idx < 0 || idx > DATA_MAX)
	{
		printf("잘못된 위치 입력\n");
		return;
	}

	if (g_members[idx].flag == 1)
	{
		printf("이미 사용중인 인덱스입니다\n");
		return;
	}

	printf("회원의 아이디 : ");					gets_s(id, sizeof(id));
	printf("회원의 전화번호 :");				gets_s(phone, sizeof(phone));
	printf("회원의 나이      : ");				scanf_s("%d", &age);
	dummy = getchar();
	

	member mem = member_create(id, phone, age);
	g_members[idx] = mem;

	printf("저장되었습니다.\n");
}

// 검색정보입력 -> [검색] -> 결과 출력
void con_select()
{
	printf("[회원정보 검색]\n");

	char id[20];
	printf("검색할 아이디 입력 : ");			gets_s(id, sizeof(id));

	int idx = id_to_idx(id);

	if (idx != -1)
	{
		member_println(&g_members[idx]);
	}
	else
	{
		printf("없는 아이디입니다.");
	}
}

// 검색정보입력 -> 수정할 나이 -> [검색] -> 나이를 수정 -> 결과 출력
void con_update()
{
	printf("[회원정보 변경]\n");

	char id[20];
	char phone[20];
	int age;
	printf("변경할 아이디 입력 : ");			gets_s(id, sizeof(id));
	printf("변경할 전화번호입력: ");			gets_s(phone, sizeof(phone));
	printf("변경할 나이 입력 : ");				scanf_s("%d", &age);
	char dummy = getchar();

	int idx = id_to_idx(id);

	if (idx != -1)
	{
		member_update(&g_members[idx], phone, age);
		printf("변경되었습니다.");
	}
	else
	{
		printf("없는 아이디입니다.");
	}
}

// 검색정보입력 -> [검색] -> 삭제처리 -> 결과 출력
void con_delete()
{
	printf("[회원정보 삭제]\n");


	char id[20];
	printf("삭제할 아이디 입력 : ");			gets_s(id, sizeof(id));

	int idx = id_to_idx(id);

	if (idx != -1)
	{	
		member_delete(&g_members[idx]);

		printf("삭제되었습니다.");
	}
	else
	{
		printf("없는 아이디입니다.");
	}
}

void con_exit()
{

}

// 배열의 순차검색 알고리즘
int id_to_idx(const char* id)
{
	for (int i = 0; i < DATA_MAX; i++)
	{
		if (strcmp(g_members[i].id, id) == 0)
		{
			return i;
		}
	}
	return -1;
}