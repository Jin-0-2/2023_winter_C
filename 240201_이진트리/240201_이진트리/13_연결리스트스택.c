//13_���Ḯ��Ʈ����.cpp
//02_���߿��Ḯ��Ʈ.c
//int�� ����!!!
#include <stdio.h>
#include <malloc.h>

//�ܰ�1) ��屸��ü ����( ��� : ���Ḯ��Ʈ �⺻ ��� )
typedef struct tagNode Node;
struct tagNode
{
	int data;
	struct tagNode* next;
	struct tagNode* prev;
};


//�ܰ�2) ���Ḯ��Ʈ ����ü ����(head, size)
typedef struct tagMyList MyList;
struct tagMyList
{
	Node* head;  //ù ��� ����
	Node* tail;  //������ ��� ����
	int   size;  //���� ����
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

	//����
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

	//����
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

	if (cur == mlist->tail)  //������� (push_back�� �������� �ڵ� ����)
	{
		newnode->prev = mlist->tail;
		mlist->tail->next = newnode;
		mlist->tail = newnode;
	}
	else  //�߰� ���
	{
		newnode->prev = cur;
		newnode->next = cur->next;
		cur->next->prev = newnode;
		cur->next = newnode;
	}
	mlist->size++;
	return 1;
}

//----------------- ��ȸ(printall)[����] print1�� �Ϻ� ����-----------------------
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

//----------------- ��ȸ(select)[����]-------------------------------------------
Node* mylist_select(const MyList* mlist, int value)
{
	Node* cur = mlist->head;

	while (cur != NULL)
	{
		//---------------------------
		int d = cur->data;
		if (d == value)
			return cur;		//ã�� �ּ�
		//---------------------------
		cur = cur->next;
	}
	return cur;				//NULL
}

//----------------- delete ------------------------------------------
int mylist_deletefront(MyList* mlist)
{
	if (mlist->head == NULL) //����ִ�
		return 0;

	Node* del = mlist->head; //ù��° ���
	if (mlist->head->next == NULL) //��尡 �Ѱ�
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
	if (mlist->head == NULL) //����ִ�
		return 0;

	Node* del = mlist->tail; //������ ���
	int temp = del->data;
	if (mlist->head->next == NULL) //��尡 �Ѱ�
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
	if (del == mlist->head) //ù��° ���
	{
		return mylist_deletefront(mlist);
	}
	else if (del == mlist->tail) //������ ���
	{
		return mylist_deleteback(mlist);
	}
	else //�߰� ��� ����
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

	printf("POP 2��\n");
	printf("[POP : %d]\n", mylist_deleteback(&mlist)); //50
	mylist_printall(&mlist);
	printf("[POP : %d]\n", mylist_deleteback(&mlist)); //40
	mylist_printall(&mlist);

	return 0;
}