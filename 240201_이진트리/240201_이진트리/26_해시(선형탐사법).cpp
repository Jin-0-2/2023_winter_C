//26_선형탐사법.cpp
#include <iostream>
using namespace std;

#define EMPTY	-1		// 빈 곳을 표시
#define DELETED  -2		// 삭제된 곳을 표시 

typedef struct _taghtable
{
	int *table;
	int full_max;		//120%더 크게
	int user_max;
	int size;		//옵션
}htable;

int hlp_init(htable * table, int max)
{
	table->user_max = max;
	table->size		= 0;
	table->full_max = (int)(max * 1.2);
	table->table	= (int*)malloc(sizeof(int) * table->full_max);
	if (table->table == NULL)
		return 0;

	for (int i = 0; i < table->full_max; i++)
		table->table[i] = EMPTY;

	return 1;
}

int hash_func(const htable* table, int key)
{
	int h;
	h = key % table->full_max;
	return h;
}

int hlp_insert(htable* htable, int key)
{
	if (htable->user_max <= htable->size)
		return -1;

	//1. 해쉬값 획득
	int hv = hash_func(htable, key);

	//2. 빈 곳이나 삭제된 곳
	while (htable->table[hv] != EMPTY && htable->table[hv] != DELETED)
	{
		hv = (hv + 1) % htable->full_max;	// 선형 탐사(원형 이동)
	}

	//3. 찾은 곳에 key를 수록
	htable->table[hv] = key;

	//4. 자료수 증가
	htable->size++;

	// 삽입한 곳을 리턴
	return hv;
}

//인덱스
int hlp_search(const htable* htable, int key)
{
	int hv = hash_func(htable, key);
	while (htable->table[hv] != EMPTY)
	{
		if (htable->table[hv] == key)
			return hv;

		// 선형 검색
		hv = (hv + 1) % htable->full_max;
	}
	return -1;
}

int hlp_delete(htable* htable, int key)
{
	// 삭제할 키를 찾음
	int hv = hlp_search(htable, key);
	if (hv == -1)
		return 0;

	// 찾은 곳에 삭제를 표시
	htable->table[hv] = DELETED;

	// 자료수 감소
	htable->size--;
	return 1;
}

void hlp_print(const htable* htable)
{
	printf("[저장개수 : %d]\n", htable->size);
	printf("----------------------------------------------------------------\n");
	for (int i = 0; i < htable->full_max; i++)
	{
		printf("[%2d] : %d(%d)\n", i, htable->table[i], hash_func(htable, htable->table[i]));
	}
	printf("----------------------------------------------------------------\n");
}

int main()
{
	htable table;
	hlp_init(&table, 10);
	hlp_print(&table);

	//저장
	hlp_insert(&table, 20);
	hlp_insert(&table, 11);
	hlp_insert(&table, 9);
	hlp_insert(&table, 24);
	hlp_insert(&table, 128);
	hlp_insert(&table, 31);
	hlp_insert(&table, 51);
	hlp_insert(&table, 35);
	hlp_insert(&table, 32);
	hlp_insert(&table, 48);
	hlp_print(&table);

	//삭제
	hlp_delete(&table, 128);
	hlp_print(&table);

	//검색
	int hv = hlp_search(&table, 32);
	printf("결과값 : %d\n", table.table[hv]);

	hv = hlp_search(&table, 100);
	if (hv == -1)
		printf("없다\n");

	return 0;
}