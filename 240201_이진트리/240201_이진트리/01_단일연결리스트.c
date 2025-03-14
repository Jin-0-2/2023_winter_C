//01_���Ͽ��Ḯ��Ʈ.c
//int�� ����!!!
#include <stdio.h>
#include <malloc.h>

//�ܰ�1) ��屸��ü ����( ��� : ���Ḯ��Ʈ �⺻ ��� )
typedef struct tagNode Node;
struct tagNode
{
	int data;
	struct tagNode* next;
};

//�ܰ�2) ���Ḯ��Ʈ ����ü ����(head, size)
typedef struct tagMyList MyList;
struct tagMyList
{
	Node* head;  //���Ḯ��Ʈ ������
	int   size;  //���� ����
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

	//����
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

	//����
	if (mlist->head == NULL)
	{
		mlist->head = newnode;
	}
	else
	{
		//����ã��
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

//----------------- ��ȸ(printall)----------------------------------------
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

//----------------- ��ȸ(select)-------------------------------------------
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

	Node* del = mlist->head;
	mlist->head = del->next;
	free(del);
	mlist->size--;

	return 1;
}

int mylist_deleteback(MyList* mlist)
{
	if (mlist->head == NULL) //����ִ�
		return 0;


	Node* del	= mlist->head;
	Node* prev	= mlist->head;

	if (mlist->head->next == NULL) //��尡 �ϳ��϶�
	{
		mlist->head = NULL;
	}
	else	//��尡 2�� �̻��� �� 
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
	
	//����(10 20 30 40) & ���
	for (int i = 0; i < 5; i++)
	{
		//mylist_pushfront(&mlist, (i + 1) * 10);	//40 30 20 10
		mylist_pushback(&mlist, (i + 1) * 10);		//10 20 30 40
		mylist_printall(&mlist);
	}

	//�˻�
	Node* sel = mylist_select(&mlist, 30);
	if (sel == NULL)
		printf("����\n");
	else
	{
		int value = sel->data;
		printf("ã�� �� : %d\n", value);
	}

	//����
	printf("\n����--------------------------------------------------\n");
	mylist_printall(&mlist);
	for (int i = 0; i < 5; i++)
	{
		//mylist_deletefront(&mlist);
		mylist_deleteback(&mlist);
		mylist_printall(&mlist);
	}

	return 0;
}