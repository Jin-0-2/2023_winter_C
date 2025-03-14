//03_���߿��Ḯ��ƮŬ����.cpp
#include <iostream>
using namespace std;

class Node
{	
public:		//-> prive
	int data;
	Node* next;
	Node* prev;

public:
	Node(int _data) : data(_data), next(NULL), prev(NULL)
	{
	}
};

class MyList
{
private:
	Node* head;  //ù ��� ����
	Node* tail;  //������ ��� ����
	int   size;  //���� ����

public:
	MyList();
	~MyList();

public:
	int getSize() const			{ return size;		}
	int getData(Node* cur)		{ return cur->data; }
	Node* getHead()				{ return head;		}
	Node* getTail()				{ return tail;		}

public:
	//insert 
	bool Push_Front(int value);
	bool Push_Back(int value);
	bool Push_Random(Node* cur, int value);

	//Delete
	bool Delete_Front();
	bool Delete_Back();
	bool Delete_Random(Node* del);
};

MyList::MyList() : head(NULL), tail(NULL), size(0)
{
}

MyList::~MyList()
{

}

bool MyList::Push_Front(int value)
{
	Node* newnode = new Node(value);
	if (newnode == NULL)
		throw "�޸� ����";//return false;

	if (head == NULL)
	{
		head = newnode;
		tail = newnode;
	}
	else
	{
		newnode->next = head;
		head->prev = newnode;
		head = newnode;
	}
	size++;
	return true;
}

bool MyList::Push_Back(int value)
{
	Node* newnode = new Node(value);
	if (newnode == NULL)
		throw "�޸� ����";//return false;

	if (head == NULL)
	{
		head = newnode;
		tail = newnode;
	}
	else
	{
		newnode->prev	= tail;
		tail->next		= newnode;
		tail			= newnode;
	}
	size++;
	return true;
}

bool MyList::Push_Random(Node* cur, int value)
{
	Node* newnode = new Node(value);
	if (newnode == NULL)
		throw "�޸� ����";	//return false;

	if (cur == tail)  //������� (push_back�� �������� �ڵ� ����)
	{
		newnode->prev	= tail;
		tail->next		= newnode;
		tail			= newnode;
	}
	else  //�߰� ���
	{
		newnode->prev = cur;
		newnode->next = cur->next;
		cur->next->prev = newnode;
		cur->next = newnode;
	}
	size++;
	return true;
}

bool MyList::Delete_Front()
{
	if (head == NULL) //����ִ�
		throw "����ִ� ����";  //  return false;

	Node* del = head; //ù��° ���
	if (head->next == NULL) //��尡 �Ѱ�
	{
		head = NULL;
		tail = NULL;
	}
	else
	{
		head = head->next;
		head->prev = NULL;
	}
	delete del;
	size--;

	return true;
}

bool MyList::Delete_Back()
{
	if (head == NULL) //����ִ�
		throw "����ִ� ����";  //  return false;

	Node* del = tail; //������ ���
	if (head->next == NULL) //��尡 �Ѱ�
	{
		head = NULL;
		tail = NULL;
	}
	else
	{
		tail = tail->prev;
		tail->next = NULL;
	}
	delete del;
	size--;

	return true;
}

bool MyList::Delete_Random(Node* del)
{
	if (del == head) //ù��° ���
	{
		return Delete_Front();
	}
	else if (del == tail) //������ ���
	{
		return Delete_Back();
	}
	else //�߰� ��� ����
	{
		del->prev->next = del->next;
		del->next->prev = del->prev;
		delete del;
		size--;
	}
	return true;
}

//------------------------------------------------------------------------------------
void mylist_printall(MyList& mlist)
{
	printf("[%2d] ", mlist.getSize());

	Node* cur = mlist.getHead();

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

void mylist_printall1(MyList& mlist)
{
	printf("[%2d] ", mlist.getSize());

	Node* cur = mlist.getTail();

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

Node* mylist_select(MyList& mlist, int value)
{
	Node* cur = mlist.getHead();

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

int main()
{
	MyList mlist;  //������ ȣ�� -> �ʱ�ȭ

	//����(10 20 30 40,50) & ���
	for (int i = 0; i < 5; i++)
	{
		//mlist.Push_Front((i + 1) * 10);
		mlist.Push_Front((i + 1) * 10);		//10 20 30 40		
	}

	//��ü���
	mylist_printall(mlist);	
	mylist_printall1(mlist);

	printf("\nRandom Insert ����(��, �߰�, ��----------------------------------\n");
	printf("[ù��° ��� ����]\n");
	mlist.Push_Random(mlist.getHead(), 15);
	mylist_printall(mlist);
	mylist_printall1(mlist);

	printf("[����° ��� ����]\n");  // 10 15 20 [25] 30 ....
	mlist.Push_Random(mlist.getHead()->next->next, 25);
	mylist_printall(mlist);
	mylist_printall1(mlist);

	printf("[������ ��� ����]\n");  // 10 15 20 25 30 40 50 [55]
	mlist.Push_Random(mlist.getTail(), 55);
	mylist_printall(mlist);
	mylist_printall1(mlist);

	//�˻�
	Node* sel = mylist_select(mlist, 55);
	if (sel == NULL)
		printf("����\n");
	else
	{
		int value = sel->data;
		printf("ã�� �� : %d\n", value);
	}

	//����
	printf("\n���� ����-----------------------------------------------\n");
	mylist_printall(mlist);
	mylist_printall1(mlist);
	printf("\n");

	printf("[ù��° ��� ����]\n");
	mlist.Delete_Random(mlist.getHead());
	mylist_printall(mlist);
	mylist_printall1(mlist);

	printf("[����° ��� ����]\n");  //15 20 [25] 30 40 50 55...
	mlist.Delete_Random(mlist.getHead()->next->next);
	mylist_printall(mlist);
	mylist_printall1(mlist);

	printf("[������ ��� ����]\n");  //15 20  30 40 50 [55]
	mlist.Delete_Random(mlist.getTail());
	mylist_printall(mlist);
	mylist_printall1(mlist);

	printf("\n����--------------------------------------------------\n");
	mylist_printall(mlist);
	mylist_printall1(mlist);
	printf("\n");
	for (int i = 0; i < 8; i++)
	{
		try
		{
			//mlist.Delete_Front();
			mlist.Delete_Back();
			mylist_printall(mlist);
			mylist_printall1(mlist);
			printf("\n");
		}
		catch (const char* error)
		{
			cout << "���� ���� : " << error << endl; 
		}				
	}

	return 0;
}