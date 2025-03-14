//27_해시(연결법).cpp

#include <iostream>
using namespace std;

// 노드 구성 
typedef struct _node
{
	int key;
	struct _node* next;
}node;

typedef struct _taghtable
{
	node* *table;
	int max;
	int size;		//옵션
}htable;

int hlp_init(htable *htable, int max)
{
	htable->size = 0;
	htable->max = max;
	htable->table = (node**)malloc(sizeof(node*) * max);
	if (htable->table == NULL)
		return 0;

	for (int i = 0; i < max; i++)
		htable->table[i] = NULL;
	return 1;
}

void hlp_print(const htable* htable)
{
	printf("[저장개수 : %d]\n", htable->size);
	printf("----------------------------------------------------------------\n");
	for (int i = 0; i < htable->max; i++)
	{
		printf("[%2d] : ", i);

		node* cur = htable->table[i];
		while (cur != NULL)
		{
			printf("%d -> ", cur->key);
			cur = cur->next;
		}

		printf("\n");
	}
	printf("----------------------------------------------------------------\n");
}

int hash_func(const htable* table, int key)
{
	int h;
	h = key % table->max;
	return h;
}

int hlp_insert(htable* htable, int key)
{
	//노드 생성 초기화
	node* newnode = (node*)malloc(sizeof(node));
	newnode->key = key;
	newnode->next = NULL;

	// 해쉬값을 찾음
	int hv = hash_func(htable, key);

	// 연결 리스트의 선두에 t를 삽입
	if (htable->table[hv] == NULL)
	{
		htable->table[hv] = newnode;
	}
	else
	{
		newnode->next = htable->table[hv];
		htable->table[hv] = newnode;
	}

	// 자료수 증가
	htable->size++;
	return hv;
}

node* hlp_search(htable* htable, int key)
{
	int hv = hash_func(htable, key);

	node* cur = htable->table[hv];

	// 순차 검색(NULL or 찾았다)
	while (cur != NULL && cur->key != key)
		cur = cur->next;

	// t를 리턴, 검색에 실패했을 경우는 NULL을 리턴 
	return cur;
}

int hlp_delete(htable* htable, int key)
{
	if (htable->size == 0)
		return 0;

	// 삭제할 노드의 앞 노드를 가리킴, 삭제할 노드
	int hv = hash_func(htable, key);
	node *prev = htable->table[hv];
	node *del  = htable->table[hv];

	if (del->key == key) //첫번째 노드를 삭제하는 상황
	{
		htable->table[hv] = del->next; 
		
	}
	else
	{
		while (del != NULL && del->key != key)
		{
			prev = del;
			del = del->next;
		}
		prev->next = del->next;
	}
	free(del);
	htable->size--;	
	return 1;
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
	hlp_delete(&table, 31);
	hlp_print(&table);

	//검색
	node* cur = hlp_search(&table, 12);
	if (cur == NULL)
		printf("없다\n");
	else
		printf("결과값 : %d\n", cur->key);

	return 0;
}