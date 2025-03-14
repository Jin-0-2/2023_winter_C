//15_���Ḯ��Ʈ����.cpp
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
	T Delete_Back();
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
T MyList<T>::Delete_Back()
{
	if (head == NULL) //����ִ�
		throw "����ִ� ����";  //  return false;

	Node* del = tail; //������ ���
	T temp = del->data;
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

	return temp;
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

//-------------------------------------------------------------------------------------
template<typename T>
class MyStack
{
	MyList<T> mlist;  //has a ����...

public:
	bool Push(T value)
	{
		return mlist.Push_Back(value);
	}

	void Print() 
	{
		::mylist_printall(mlist);
		//Push(10);
	}

	T Pop()
	{
		return mlist.Delete_Back();
	}
};


int main()
{
	MyStack<char> mlist;  //������ ȣ�� -> �ʱ�ȭ

	cout << "PUSH : A, B, C, D" << endl;
	for(int i='A'; i<= 'D'; i++)
		mlist.Push(i);

	mlist.Print();

	cout << "POP : " << mlist.Pop() << endl;
	mlist.Print();	

	return 0;
}