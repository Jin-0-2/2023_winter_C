//15_연결리스트스택.cpp
#include <iostream>
using namespace std;

template <typename T>
class MyList
{
public:
	class Node
	{
	public:		//-> prive
		T data;				//<-------------------------------------------(수정)
		Node* next;
		Node* prev;

	public:
		Node(T _data) : data(_data), next(NULL), prev(NULL)//<-----------(수정)
		{
		}
	};

private:
	Node* head;  //첫 노드 저장
	Node* tail;  //마지막 노드 저장
	int   size;  //저장 개수

public:
	MyList();
	~MyList();

public:
	int getSize() const { return size; }
	T getData(Node* cur) { return cur->data; }  //<-------------------수정
	Node* getHead() { return head; }
	Node* getTail() { return tail; }

public:
	//insert 
	bool Push_Front(T value);					//<--------------------수정
	bool Push_Back(T value);					//<--------------------수정
	bool Push_Random(Node* cur, T value);		//<--------------------수정

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
		throw "메모리 부족";//return false;

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
		throw "메모리 부족";//return false;

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
		throw "메모리 부족";	//return false;

	if (cur == tail)  //꼬리노드 (push_back의 꼬리연결 코드 복사)
	{
		newnode->prev = tail;
		tail->next = newnode;
		tail = newnode;
	}
	else  //중간 노드
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
	if (head == NULL) //비어있다
		throw "비어있는 상태";  //  return false;

	Node* del = head; //첫번째 노드
	if (head->next == NULL) //노드가 한개
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
	if (head == NULL) //비어있다
		throw "비어있는 상태";  //  return false;

	Node* del = tail; //마지막 노드
	T temp = del->data;
	if (head->next == NULL) //노드가 한개
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
	if (del == head) //첫번째 노드
	{
		return Delete_Front();
	}
	else if (del == tail) //마지막 노드
	{
		return Delete_Back();
	}
	else //중간 노드 삭제
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
			return cur;		//찾은 주소
		//---------------------------
		cur = cur->next;
	}
	return cur;				//NULL
}

//-------------------------------------------------------------------------------------
template<typename T>
class MyStack
{
	MyList<T> mlist;  //has a 소유...

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
	MyStack<char> mlist;  //생성자 호출 -> 초기화

	cout << "PUSH : A, B, C, D" << endl;
	for(int i='A'; i<= 'D'; i++)
		mlist.Push(i);

	mlist.Print();

	cout << "POP : " << mlist.Pop() << endl;
	mlist.Print();	

	return 0;
}