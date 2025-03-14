//18_���ÿ��Ḯ��Ʈ.cpp
/*
���� : ���ⱸ�� �����ϴ�.
push_front()  <--> pop_front()
push_rear() <--> pop_rear()
*/
#include <iostream>
using namespace std;

template<typename T>
class MyList
{
public:
	class Node
	{
	public:
		T data;		//������ ����� -----------------------
		Node* next;		//���� ��� �ּ�
		Node* prev;		//���� ��� �ּ�

	public:
		Node(T _data) :data(_data), next(NULL), prev(NULL)
		{
		}
		~Node()
		{
		}
	};

private:
	Node* head;   //���� ����� �ּ� 
	Node* tail;   //���� ����� �ּ�
	int size;     //����

public:
	MyList();
	~MyList();

public:
	Node* get_head() { return head; }
	Node* get_tail() { return tail; }
	int   get_size() { return size; }

public:
	//������ ��ȯ
	T get_data(Node* cur) { return cur->data; }

	//����
	void push_front(T data);
	void push_rear(T data);
	void push(Node* cur, T data);

	//����
	T pop_front();
	T pop_rear();
	T pop(Node* cur);
};

template<typename T>
MyList<T>::MyList() : head(NULL), tail(NULL), size(0)
{
}

template<typename T>
MyList<T>::~MyList()
{

}

template<typename T>
void MyList<T>::push_front(T data) //---------
{
	Node* newnode = new Node(data);
	if (newnode == NULL)
		throw "��� ���� ����";

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
}

template<typename T>
void MyList<T>::push_rear(T data)
{
	Node* newnode = new Node(data);
	if (newnode == NULL)
		throw "��� ���� ����";

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
}

template<typename T>
void MyList<T>::push(Node* cur, T data)
{
	Node* newnode = new Node(data);
	if (newnode == NULL)
		throw "��� ���� ����";

	if (tail != cur)  //���λ�Ȳ
	{
		newnode->prev = cur;
		newnode->next = cur->next;
		cur->next->prev = newnode;
		cur->next = newnode;
	}
	else //���ʿ��� ��尡 ����:push_back�� ���� ��Ȳ
	{
		newnode->prev = tail;
		tail->next = newnode;
		tail = newnode;
	}
	size++;
}

template<typename T>
T MyList<T>::pop_front()
{
	if (head == NULL)
		throw "empty";

	Node* del = head;
	T pdata = del->data;	//***************************
	if (head->next == NULL) //��尡 �ϳ��� ��Ȳ
	{
		head = NULL;
		tail = NULL;
	}
	else  //��尡 �������� ��Ȳ
	{
		head = del->next;
		head->prev = NULL;
	}
	delete del;
	size--;

	return pdata;	//*****************************
}

template<typename T>
T MyList<T>::pop_rear()
{
	if (head == NULL)
		throw "empty";

	Node* del = tail;
	T pdata = del->data;

	if (head->next == NULL) //��尡 �ϳ��� ��Ȳ
	{
		head = NULL;
		tail = NULL;
	}
	else  //��尡 �������� ��Ȳ
	{
		tail = del->prev;
		tail->next = NULL;
	}

	delete del;
	size--;

	return pdata;
}

template<typename T>
T MyList<T>::pop(Node* cur)
{
	if (cur->prev == NULL) //���� �� ��� 
	{
		return pop_front();
	}
	else if (cur->next == NULL) //���� ������ ���
	{
		return pop_rear();
	}
	else
	{
		T pdata = cur->data;

		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
		delete cur;
		size--;

		return pdata;
	}
}

/*
���� : MyList<>				<-- exam1()
���� : MyList<>  MyStack<>  <--- exam2()
*/

template<typename T>
class MyStack
{
private:
	MyList<T> list;

public:
	void push(T value)
	{
		list.push_front(value);
	}

	T pop()
	{
		return list.pop_front();
	}
};


//����  MyList�� �״�� Ȱ��
void exam1()
{
	MyList<int> stack;

	stack.push_front(10);
	stack.push_front(20);
	stack.push_front(30);

	cout << stack.pop_front() << endl;	//30 
	cout << stack.pop_front() << endl;	//20
	cout << stack.pop_front() << endl;	//10
}

void exam2()
{
	MyStack<int> stack;

	stack.push(10);
	stack.push(20);
	stack.push(30);

	cout << stack.pop() << endl;	//30 
	cout << stack.pop() << endl;	//20
	cout << stack.pop() << endl;	//10
}

int main()
{
	exam2();

	return 0;
}



