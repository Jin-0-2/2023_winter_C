// control.c [기능의 시작]
#include "std.h"
#define DATA_MAX 10

int g_flag[10];		//데이터 존재유무 파악 1 or 0
int g_id[10];		//계정(유일해야 함)
int g_age[10];		//나이		
char g_gender[10];	//성별		
float g_weight[10];	//몸무게

int g_arr[DATA_MAX]; // 전역 변수


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
		printf("[%2d] ", i);
		if (g_flag[i] != 0)
			printf("%d \t %d \t %c\n, %.1f", g_id[i], g_age[i], g_gender[i], g_weight[i]);
		else
			printf("\n");
	}
	printf("\n");
}

// 정보입력 -> 전역변수 저장
void con_insert()					// insert 알고리즘. 
{
	printf("[회원저장]\n");

	int idx;
	int id, age;
	char gender;

	printf("저장할 위치(0~%d) : ", DATA_MAX - 1);
	scanf_s("%d", &idx);

	if (idx < 0 || idx > DATA_MAX)
	{
		printf("잘못된 위치 입력\n");
		return;
	}

	if (g_flag[idx] == 1)
	{
		printf("이미 사용중인 인덱스입니다\n");
		return;
	}

	printf("회원의 아이디 : ");				scanf_s("%d", &id);

	for (int i = 0; i < DATA_MAX; i++)
	{
		if (g_id[i] == id)
		{
			printf("이미 존재하는 아이디입니다.\n");
			return;
		}
	}
	
	printf("회원의 나이      : ");				scanf_s("%d", &age);
	char dummy = getchar();
	printf("회원의 성별(m/w) : ");				scanf_s("%c", &gender, (int)sizeof(char));
	printf("회원의 몸무게(kg): ");				scanf_s("%f", &g_weight);

	g_flag[idx] = 1;
	g_id[idx] = id;
	g_age[idx] = age;
	g_gender[idx] = gender;
	

	printf("저장되었습니다.\n");
}

// 검색정보입력 -> [검색] -> 결과 출력
void con_select()
{
	printf("[회원정보 검색]\n");


	int id;
	printf("검색할 아이디 입력 : ");			scanf_s("%d", &id);

	int idx = id_to_idx(id);

	if (idx != -1)
	{
		printf("아이디 : %d\n", g_id[idx]);
		printf("나  이 : %d\n", g_age[idx]);
		printf("성  별 : %c\n", g_gender[idx]);
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


	int id, age;
	char gender;
	printf("변경할 아이디 입력 : ");			scanf_s("%d", &id);
	printf("변경할 나이 입력 : ");				scanf_s("%d", &age);
	char dummy = getchar();
	printf("변경할 성별 입력(m/w) : ");			scanf_s("%c", &gender, (int)sizeof(char));

	int idx = id_to_idx(id);

	if (idx != -1)
	{
		g_age[idx] = age;
		g_gender[idx] = gender;
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


	int id;
	printf("삭제할 아이디 입력 : ");			scanf_s("%d", &id);

	int idx = id_to_idx(id);

	if (idx != -1)
	{	
		g_id[idx] = 0;
		g_age[idx] = 0;
		g_gender[idx] = 0;
		g_flag[idx] = 0;  // 중요 > 존재유무

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
int id_to_idx(int id)
{
	for (int i = 0; i < DATA_MAX; i++)
	{
		if (g_id[i] == id)
		{
			return i;
		}
	}
	return -1;
}