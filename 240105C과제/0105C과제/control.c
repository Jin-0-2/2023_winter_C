// control.c [기능의 시작]
#include "std.h"

int g_flag[DATA_MAX];			//데이터 존재유무 파악 1 or 0
char g_name[DATA_MAX][20];		//이름
char g_phone[DATA_MAX][20];		//번호
int g_age[DATA_MAX];			//나이

void con_init()
{
	for (int i = 0; i < 10; i++)
	{
		g_flag[i] = 0;
	}
}

void con_printall()
{
	for (int i = 0; i < DATA_MAX; i++)
	{
		member_print(i, g_flag[i], g_name[i], g_phone[i], g_age[i]);
	}
	printf("\n");
}

// 정보입력 -> 전역변수 저장
void con_insert()		
{
	printf("[회원저장]\n");

	int idx;
	char name[20], phone[20];
	int age;

	printf("저장할 위치(0~%d) : ", DATA_MAX - 1);
	scanf_s("%d", &idx);
	char dummy = getchar();

	if (member_idx_check(idx, g_flag[idx]) == 0)
		return;


	printf("이    름 : ");			gets_s(name, sizeof(name));
	printf("전화번호 : ");			gets_s(phone, sizeof(phone));
	printf("나    이 : ");			scanf_s("%d", &age);
	dummy = getchar();
	
	member_insert(&g_flag[idx], g_name[idx], g_phone[idx], &g_age[idx], name, phone, age);

	printf("저장되었습니다.\n");
}

// 검색정보입력 -> [검색] -> 결과 출력
void con_select()
{
	printf("[회원정보 검색]\n");
	
	char name[20];
	printf("검색할 이름 입력 : ");		gets_s(name, sizeof(name));

	int idx = name_to_idx(name);

	if (idx != -1)
		member_println(g_name[idx], g_phone[idx], g_age[idx]);
	else
		printf("없는 아이디입니다.\n");
}

// 검색정보입력 -> 수정할 나이 -> [검색] -> 나이를 수정 -> 결과 출력
void con_update()
{
	printf("[회원정보 변경]\n");

	int age;
	char phone[20], name[20];

	printf("변경할 이름 입력 : ");			gets_s(name, sizeof(name));
	printf("변경할 전화번호 입력 : ");				gets_s(phone, sizeof(phone));
	printf("변경할 나이 입력     : ");				scanf_s("%d", &age);
	char dummy = getchar();
	
	int idx = name_to_idx(name);
	if (idx != -1)
	{
		member_update(g_phone[idx], &g_age[idx], phone, age);
		printf("변경되었습니다.\n");
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

	char name[20];

	printf("삭제할 이름 입력 : ");			gets_s(name, sizeof(name));

	int idx = name_to_idx(name);

	if (idx != -1)
	{
		member_delete(g_name[idx], g_phone[idx], &g_age[idx], &g_flag[idx]);
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
int name_to_idx(char* name)
{
	for (int i = 0; i < DATA_MAX; i++)
	{
		if (strcmp(g_name[i], name) == 0)
		{
			return i;
		}
	}
	return -1;
}