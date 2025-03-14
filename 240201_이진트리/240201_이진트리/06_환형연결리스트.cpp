//06_환형연결리스트.cpp
// Sample 1) 요셉의 문제 
// 10명의 사람이 시계 방향으로 순서대로 원을 지어 앉아 있다고 가정..
// 이 때 A로 부터 시작해서 4명 간격으로 사람을 그 원에서 뽑아냄

#include <stdio.h>	
#include <malloc.h>

//typedef
//구조체 정의
typedef struct tagNode Node;
struct tagNode
{
};

//구조체 정의 + typedef 동시에 
//타입식별자 : struct _node,    node
typedef struct _node
{
	int key;
	struct _node* next;
}node;

node* head = NULL;

// 1부터 k의 값을 갖는 환형 연결리스트 구성 
void insert_nodes(int k)   
{
	//첫번째 노드 생성 & 초기화
	node* t = (node*)malloc(sizeof(node));
	t->key	= 1;
	t->next = NULL;

	//첫번째 노드를 head에 연결
	head = t;

	for (int i = 2; i <= k; i++)
	{
		node *newnode = (node*)malloc(sizeof(node));
		newnode->key = i;
		newnode->next = NULL;

		//연결
		t->next = newnode;
		t = t->next;
	}
	// 마지막을 처음으로 물림, 환형 생성
	t->next = head;
}

// 다음 노드를 삭제 
void delete_after(node* t)
{
	// del는 현재 삭제하고자 하는 위치
	node* del = t->next;

	//연결에서 제외
	t->next = del->next;

	//힙 제거
	free(del);
}

// 요셉의 문제 '  n개의 노드를 m간격으로 
void josephus(int n, int m)
{
	printf("\nAnswer :");

	// 1. 환형 연결리스트 구성 
	insert_nodes(n);

	node *t = head;	
	while (t != t->next)	// 연결리스트 노드가 남아있는 동안 
	{
		//삭제할 노드의 이전노드 
		for (int i = 0; i < m - 1; i++)
			t = t->next;

		// 삭제하고자 하는 node의 key값 출력
		printf("%d  ", t->next->key);

		// 노드 삭제 
		delete_after(t);
	}
	printf("%d\n", t->key); // 마지막 노드 출력 	
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

