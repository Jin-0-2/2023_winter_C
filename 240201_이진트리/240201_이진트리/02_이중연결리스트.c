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
		newnode->next		= mlist->head;
		mlist->head->prev	= newnode;
		mlist->head			= newnode;
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
		newnode->prev		= mlist->tail;
		mlist->tail->next	= newnode;
		mlist->tail			= newnode;
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
		newnode->prev	= cur;
		newnode->next	= cur->next;
		cur->next->prev = newnode;
		cur->next		= newnode;
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
	if (mlist->head->next == NULL) //노드가 한개
	{
		mlist->head = NULL;
		mlist->tail = NULL;
	}
	else
	{
		mlist->tail			= mlist->tail->prev;
		mlist->tail->next	= NULL;
	}
	free(del);
	mlist->size--;

	return 1;
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

	//저장(10 20 30 40,50) & 출력
	for (int i = 0; i < 5; i++)
	{
		//mylist_pushfront(&mlist, (i + 1) * 10);			//40 30 20 10
		mylist_pushback(&mlist, (i + 1) * 10);		//10 20 30 40		
	}

	//전체출력
	mylist_printall(&mlist);
	mylist_printall1(&mlist);

	printf("\nRandom Insert 검증(앞, 중간, 뒤----------------------------------\n");
	printf("[첫번째 노드 다음]\n");
	mylist_pushramdom(&mlist, mlist.head, 15);
	mylist_printall(&mlist);
	mylist_printall1(&mlist);

	printf("[세번째 노드 다음]\n");  // 10 15 20 [25] 30 ....
	mylist_pushramdom(&mlist, mlist.head->next->next, 25);
	mylist_printall(&mlist);
	mylist_printall1(&mlist);

	printf("[마지막 노드 다음]\n");  // 10 15 20 25 30 40 50 [55]
	mylist_pushramdom(&mlist, mlist.tail, 55);
	mylist_printall(&mlist);
	mylist_printall1(&mlist);

	//검색
	Node* sel = mylist_select(&mlist, 55);
	if (sel == NULL)
		printf("없다\n");
	else
	{
		int value = sel->data;
		printf("찾은 값 : %d\n", value);
	}

	//삭제
	printf("\n렌덤 삭제-----------------------------------------------\n");
	mylist_printall(&mlist);	// 10 15 20 25 30 40 50 55
	mylist_printall1(&mlist);
	printf("\n");

	printf("[첫번째 노드 삭제]\n");
	mylist_deleterandom(&mlist, mlist.head);	
	mylist_printall(&mlist);					//15 20 25 30 40 50 55
	mylist_printall1(&mlist);

	printf("[세번째 노드 다음]\n");  //15 20 [25] 30 40 50 55...
	mylist_deleterandom(&mlist, mlist.head->next->next);
	mylist_printall(&mlist);
	mylist_printall1(&mlist);

	printf("[마지막 노드 다음]\n");  //15 20  30 40 50 [55]
	mylist_deleterandom(&mlist, mlist.tail);
	mylist_printall(&mlist);
	mylist_printall1(&mlist);



	printf("\n삭제--------------------------------------------------\n");
	mylist_printall(&mlist);
	mylist_printall1(&mlist);
	printf("\n");
	for (int i = 0; i < 8; i++)
	{
		//mylist_deletefront(&mlist);
		mylist_deleteback(&mlist);

		mylist_printall(&mlist);
		mylist_printall1(&mlist);
		printf("\n");
	}

	return 0;
}