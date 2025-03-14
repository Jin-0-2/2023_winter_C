//26_����Ž���.cpp
#include <iostream>
using namespace std;

#define EMPTY	-1		// �� ���� ǥ��
#define DELETED  -2		// ������ ���� ǥ�� 

typedef struct _taghtable
{
	int *table;
	int full_max;		//120%�� ũ��
	int user_max;
	int size;		//�ɼ�
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

	//1. �ؽ��� ȹ��
	int hv = hash_func(htable, key);

	//2. �� ���̳� ������ ��
	while (htable->table[hv] != EMPTY && htable->table[hv] != DELETED)
	{
		hv = (hv + 1) % htable->full_max;	// ���� Ž��(���� �̵�)
	}

	//3. ã�� ���� key�� ����
	htable->table[hv] = key;

	//4. �ڷ�� ����
	htable->size++;

	// ������ ���� ����
	return hv;
}

//�ε���
int hlp_search(const htable* htable, int key)
{
	int hv = hash_func(htable, key);
	while (htable->table[hv] != EMPTY)
	{
		if (htable->table[hv] == key)
			return hv;

		// ���� �˻�
		hv = (hv + 1) % htable->full_max;
	}
	return -1;
}

int hlp_delete(htable* htable, int key)
{
	// ������ Ű�� ã��
	int hv = hlp_search(htable, key);
	if (hv == -1)
		return 0;

	// ã�� ���� ������ ǥ��
	htable->table[hv] = DELETED;

	// �ڷ�� ����
	htable->size--;
	return 1;
}

void hlp_print(const htable* htable)
{
	printf("[���尳�� : %d]\n", htable->size);
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

	//����
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

	//����
	hlp_delete(&table, 128);
	hlp_print(&table);

	//�˻�
	int hv = hlp_search(&table, 32);
	printf("����� : %d\n", table.table[hv]);

	hv = hlp_search(&table, 100);
	if (hv == -1)
		printf("����\n");

	return 0;
}