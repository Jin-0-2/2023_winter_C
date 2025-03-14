//01_단일연결리스트.c
//int를 저장!!!
#include <stdio.h>
#include <malloc.h>

//단계1) 노드구조체 정의( 노드 : 연결리스트 기본 모듈 )
typedef struct tagNode Node;
struct tagNode
{
	int data;
	struct tagNode* next;
};

//단계2) 연결리스트 구조체 정의(head, size)
typedef struct tagMyList MyList;
struct tagMyList
{
	Node* head;  //연결리스트 시작점
	int   size;  //저장 개수
};

//----------------- init -----------------------------------------------
void mylist_init(MyList *mlist)
{
	//(*mlist).head;  (*mlist).size;
	mlist->head = NULL;
	mlist->size = 0;
}

//----------------- insert ---------------------------------------------
int mylist_pushfront(MyList* mlist, int value)
{
	Node* newnode = (Node*)malloc(sizeof(Node)); //#include <malloc.h>
	if (newnode == NULL)
		return 0;
	newnode->data = value;
	newnode->next = NULL;

	//연결
	if (mlist->head == NULL)
	{
		mlist->head = newnode;
	}
	else
	{
		newnode->next = mlist->head;
		mlist->head = newnode;
	}
	mlist->size++;
	return 1;
}

int mylist_pushback(MyList* mlist, int value)
{
	Node* newnode = (Node*)malloc(sizeof(Node)); //#include <malloc.h>
	if (newnode == NULL)
		return 0;
	newnode->data = value;
	newnode->next = NULL;

	//연결
	if (mlist->head == NULL)
	{
		mlist->head = newnode;
	}
	else
	{
		//꼬리찾기
		Node* cur = mlist->head;
		while ( cur->next  != NULL)
		{
			cur = cur->next;
		}
		cur->next = newnode;
	}
	mlist->size++;
	return 1;
}

//----------------- 순회(printall)----------------------------------------
void mylist_printall(const MyList* mlist)
{
	printf("[%2d] ", mlist->size);

	Node* cur = mlist->head;

	while (cur != NULL)
	{
		//---------------------------
		int value = cur->data;
		printf("%4d", value);
		//---------------------------
		cur = cur->next;
	}
	printf("\n");
}

//----------------- 순회(select)-------------------------------------------
Node* mylist_select(const MyList* mlist, int value)
{
	Node* cur = mlist->head;

	while (cur != NULL)
	{
		//---------------------------
		int d = cur->data;
		if (d == value)
			return cur;		//찾은 주소
		//---------------------------
		cur = cur->next;
	}
	return cur;				//NULL
}

//----------------- delete ------------------------------------------
int mylist_deletefront(MyList* mlist)
{
	if (mlist->head == NULL) //비어있다
		return 0;

	Node* del = mlist->head;
	mlist->head = del->next;
	free(del);
	mlist->size--;

	return 1;
}

int mylist_deleteback(MyList* mlist)
{
	if (mlist->head == NULL) //비어있다
		return 0;


	Node* del	= mlist->head;
	Node* prev	= mlist->head;

	if (mlist->head->next == NULL) //노드가 하나일때
	{
		mlist->head = NULL;
	}
	else	//노드가 2개 이상일 때 
	{
		while (del->next != NULL)
		{
			prev = del;
			del = del->next;
		}
		prev->next = NULL;
	}
	free(del);
	mlist->size--;

	return 1;
}

int main()
{
	MyList mlist;

	mylist_init(&mlist);
	
	//저장(10 20 30 40) & 출력
	for (int i = 0; i < 5; i++)
	{
		//mylist_pushfront(&mlist, (i + 1) * 10);	//40 30 20 10
		mylist_pushback(&mlist, (i + 1) * 10);		//10 20 30 40
		mylist_printall(&mlist);
	}

	//검색
	Node* sel = mylist_select(&mlist, 30);
	if (sel == NULL)
		printf("없다\n");
	else
	{
		int value = sel->data;
		printf("찾은 값 : %d\n", value);
	}

	//삭제
	printf("\n삭제--------------------------------------------------\n");
	mylist_printall(&mlist);
	for (int i = 0; i < 5; i++)
	{
		//mylist_deletefront(&mlist);
		mylist_deleteback(&mlist);
		mylist_printall(&mlist);
	}

	return 0;
}