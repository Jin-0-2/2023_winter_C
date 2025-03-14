//06_ȯ�����Ḯ��Ʈ.cpp
// Sample 1) ����� ���� 
// 10���� ����� �ð� �������� ������� ���� ���� �ɾ� �ִٰ� ����..
// �� �� A�� ���� �����ؼ� 4�� �������� ����� �� ������ �̾Ƴ�

#include <stdio.h>	
#include <malloc.h>

//typedef
//����ü ����
typedef struct tagNode Node;
struct tagNode
{
};

//����ü ���� + typedef ���ÿ� 
//Ÿ�Խĺ��� : struct _node,    node
typedef struct _node
{
	int key;
	struct _node* next;
}node;

node* head = NULL;

// 1���� k�� ���� ���� ȯ�� ���Ḯ��Ʈ ���� 
void insert_nodes(int k)   
{
	//ù��° ��� ���� & �ʱ�ȭ
	node* t = (node*)malloc(sizeof(node));
	t->key	= 1;
	t->next = NULL;

	//ù��° ��带 head�� ����
	head = t;

	for (int i = 2; i <= k; i++)
	{
		node *newnode = (node*)malloc(sizeof(node));
		newnode->key = i;
		newnode->next = NULL;

		//����
		t->next = newnode;
		t = t->next;
	}
	// �������� ó������ ����, ȯ�� ����
	t->next = head;
}

// ���� ��带 ���� 
void delete_after(node* t)
{
	// del�� ���� �����ϰ��� �ϴ� ��ġ
	node* del = t->next;

	//���ῡ�� ����
	t->next = del->next;

	//�� ����
	free(del);
}

// ����� ���� '  n���� ��带 m�������� 
void josephus(int n, int m)
{
	printf("\nAnswer :");

	// 1. ȯ�� ���Ḯ��Ʈ ���� 
	insert_nodes(n);

	node *t = head;	
	while (t != t->next)	// ���Ḯ��Ʈ ��尡 �����ִ� ���� 
	{
		//������ ����� ������� 
		for (int i = 0; i < m - 1; i++)
			t = t->next;

		// �����ϰ��� �ϴ� node�� key�� ���
		printf("%d  ", t->next->key);

		// ��� ���� 
		delete_after(t);
	}
	printf("%d\n", t->key); // ������ ��� ��� 	
}

int main()
{
	int n, m;
	while (1)
	{
		printf("Enter N and M ->");
		scanf_s("%d %d", &n, &m);
		if (n <= 0 || m <= 0)
			return 0;
		josephus(n, m);
	}
	return 0;
}

