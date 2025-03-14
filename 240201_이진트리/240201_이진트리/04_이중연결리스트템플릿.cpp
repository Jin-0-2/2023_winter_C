//04_���߿��Ḯ��Ʈ ���ø�.cpp
/*
class Node
{
};
//WbList�� Node�� ����
class WbList
{
  Node * next;
};

//----------------- WbList���� ����ϴ� ���� Node Ŭ������ ���� -----------------
// �ܺ� Ŭ����[���� Ŭ����] 
class WbList
{
public:
	class Node
	{
	};

private:
	Node *next;
};

///---
WbList list;
WbList::Node node;

*/

#include <iostream>
using namespace std;

template <typename T>
class MyList
{
public:
	class Node
	{
	public:		//-> prive
		T data;				//<-------------------------------------------(����)
		Node* next;
		Node* prev;

	public:
		Node(T _data) : data(_data), next(NULL), prev(NULL)//<-----------(����)
		{
		}
	};

private:
	Node* head;  //ù ��� ����
	Node* tail;  //������ ��� ����
	int   size;  //���� ����

public:
	MyList();
	~MyList();

public:
	int getSize() const { return size; }
	T getData(Node* cur) { return cur->data; }  //<-------------------����
	Node* getHead() { return head; }
	Node* getTail() { return tail; }

public:
	//insert 
	bool Push_Front(T value);					//<--------------------����
	bool Push_Back(T value);					//<--------------------����
	bool Push_Random(Node* cur, T value);		//<--------------------����

	//Delete
	bool Delete_Front();
	bool Delete_Back();
	bool Delete_Random(Node* del);
};

template <typename T>
MyList<T>::MyList() : head(NULL), tail(NULL), size(0)
{
}

template <typename T>
MyList<T>::~MyList()
{
}

template <typename T>
bool MyList<T>::Push_Front(T value)
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

template <typename T>
bool MyList<T>::Push_Back(T value)
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
		newnode->prev = tail;
		tail->next = newnode;
		tail = newnode;
	}
	size++;
	return true;
}

template <typename T>
bool MyList<T>::Push_Random(Node* cur, T value)
{
	Node* newnode = new Node(value);
	if (newnode == NULL)
		throw "�޸� ����";	//return false;

	if (cur == tail)  //������� (push_back�� �������� �ڵ� ����)
	{
		newnode->prev = tail;
		tail->next = newnode;
		tail = newnode;
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

template <typename T>
bool MyList<T>::Delete_Front()
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

template <typename T>
bool MyList<T>::Delete_Back()
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

template <typename T>
bool MyList<T>::Delete_Random(Node* del)
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


void mylist_printall(MyList<char>& mlist)
{
	printf("[%2d] ", mlist.getSize());

	MyList<char>::Node* cur = mlist.getHead();

	while (cur != NULL)
	{
		//---------------------------
		char value = cur->data;
		printf("%4c", value);
		//---------------------------
		cur = cur->next;
	}
	printf("\n");
}

void mylist_printall1(MyList<char>& mlist)
{
	printf("[%2d] ", mlist.getSize());

	MyList<char>::Node* cur = mlist.getTail();

	while (cur != NULL)
	{
		//---------------------------
		char value = cur->data;
		printf("%4c", value);
		//---------------------------
		cur = cur->prev;
	}
	printf("\n");
}

MyList<char>::Node* mylist_select(MyList<char>& mlist, int value)
{
	MyList<char>::Node* cur = mlist.getHead();

	while (cur != NULL)
	{
		//---------------------------
		char d = cur->data;
		if (d == value)
			return cur;		//ã�� �ּ�
		//---------------------------
		cur = cur->next;
	}
	return cur;				//NULL
}

int main()
{
	MyList<char> mlist;  //������ ȣ�� -> �ʱ�ȭ

	//����(10 20 30 40,50) & ���
	for (int i = 0; i < 5; i++)
	{
		mlist.Push_Front('A' + i);
		//mlist.Push_Front('A' + i);
	}

	//��ü���
	mylist_printall(mlist);
	mylist_printall1(mlist);

	printf("\nRandom Insert ����(��, �߰�, ��----------------------------------\n");
	printf("[ù��° ��� ����]\n");
	mlist.Push_Random(mlist.getHead(), 'X');
	mylist_printall(mlist);
	mylist_printall1(mlist);

	printf("[����° ��� ����]\n");  // 10 15 20 [25] 30 ....
	mlist.Push_Random(mlist.getHead()->next->next, 'Y');
	mylist_printall(mlist);
	mylist_printall1(mlist);

	printf("[������ ��� ����]\n");  // 10 15 20 25 30 40 50 [55]
	mlist.Push_Random(mlist.getTail(), 'Z');
	mylist_printall(mlist);
	mylist_printall1(mlist);

	//�˻�
	MyList<char>::Node* sel = mylist_select(mlist, 'C');
	if (sel == NULL)
		printf("����\n");
	else
	{
		char value = sel->data;
		printf("ã�� �� : %c\n", value);
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