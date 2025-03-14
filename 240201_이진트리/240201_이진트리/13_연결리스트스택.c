//13_연결리스트스택.cpp
//02_이중연결리스트.c
//int를 저장!!!
#include <stdio.h>
#include <malloc.h>

//단계1) 노드구조체 정의( 노드 : 연결리스트 기본 모듈 )
typedef struct tagNode Node;
struct tagNode
{
	int data;
	struct tagNode* next;
	struct tagNode* prev;
};


//단계2) 연결리스트 구조체 정의(head, size)
typedef struct tagMyList MyList;
struct tagMyList
{
	Node* head;  //첫 노드 저장
	Node* tail;  //마지막 노드 저장
	int   size;  //저장 개수
};

//----------------- init -----------------------------------------------
void mylist_init(MyList* mlist)
{
	mlist->head = NULL;
	mlist->tail = NULL;
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
	newnode->prev = NULL;

	//연결
	if (mlist->head == NULL)
	{
		mlist->head = newnode;
		mlist->tail = newnode;
	}
	else
	{
		newnode->next = mlist->head;
		mlist->head->prev = newnode;
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
	newnode->prev = NULL;

	//연결
	if (mlist->head == NULL)
	{
		mlist->head = newnode;
		mlist->tail = newnode;
	}
	else
	{
		newnode->prev = mlist->tail;
		mlist->tail->next = newnode;
		mlist->tail = newnode;
	}
	mlist->size++;
	return 1;
}

int mylist_pushramdom(MyList* mlist, Node* cur, int value)
{
	Node* newnode = (Node*)malloc(sizeof(Node)); //#include <malloc.h>
	if (newnode == NULL)
		return 0;
	newnode->data = value;
	newnode->next = NULL;
	newnode->prev = NULL;

	if (cur == mlist->tail)  //꼬리노드 (push_back의 꼬리연결 코드 복사)
	{
		newnode->prev = mlist->tail;
		mlist->tail->next = newnode;
		mlist->tail = newnode;
	}
	else  //중간 노드
	{
		newnode->prev = cur;
		newnode->next = cur->next;
		cur->next->prev = newnode;
		cur->next = newnode;
	}
	mlist->size++;
	return 1;
}

//----------------- 순회(printall)[재사용] print1은 일부 변경-----------------------
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

void mylist_printall1(const MyList* mlist)
{
	printf("[%2d] ", mlist->size);

	Node* cur = mlist->tail;

	while (cur != NULL)
	{
		//---------------------------
		int value = cur->data;
		printf("%4d", value);
		//---------------------------
		cur = cur->prev;
	}
	printf("\n");
}

//----------------- 순회(select)[재사용]-------------------------------------------
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

	Node* del = mlist->head; //첫번째 노드
	if (mlist->head->next == NULL) //노드가 한개
	{
		mlist->head = NULL;
		mlist->tail = NULL;
	}
	else
	{
		mlist->head = mlist->head->next;
		mlist->head->prev = NULL;
	}
	free(del);
	mlist->size--;

	return 1;
}

int mylist_deleteback(MyList* mlist)
{
	if (mlist->head == NULL) //비어있다
		return 0;

	Node* del = mlist->tail; //마지막 노드
	int temp = del->data;
	if (mlist->head->next == NULL) //노드가 한개
	{
		mlist->head = NULL;
		mlist->tail = NULL;
	}
	else
	{
		mlist->tail = mlist->tail->prev;
		mlist->tail->next = NULL;
	}
	free(del);
	mlist->size--;

	return temp;
}

int mylist_deleterandom(MyList* mlist, Node* del)
{
	if (del == mlist->head) //첫번째 노드
	{
		return mylist_deletefront(mlist);
	}
	else if (del == mlist->tail) //마지막 노드
	{
		return mylist_deleteback(mlist);
	}
	else //중간 노드 삭제
	{
		del->prev->next = del->next;
		del->next->prev = del->prev;
		free(del);
		mlist->size--;
	}
	return 1;
}


int main()
{
	MyList mlist;
	mylist_init(&mlist);

	printf("10, 20, 30, 40, 50\n");
	for (int i = 0; i < 5; i++)
		mylist_pushback(&mlist, (i + 1) * 10);	

	mylist_printall(&mlist);

	printf("POP 2번\n");
	printf("[POP : %d]\n", mylist_deleteback(&mlist)); //50
	mylist_printall(&mlist);
	printf("[POP : %d]\n", mylist_deleteback(&mlist)); //40
	mylist_printall(&mlist);

	return 0;
}