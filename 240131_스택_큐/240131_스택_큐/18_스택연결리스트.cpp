//18_스택연결리스트.cpp
/*
스택 : 입출구가 동일하다.
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
		T data;		//데이터 저장소 -----------------------
		Node* next;		//다음 노드 주소
		Node* prev;		//이전 노드 주소

	public:
		Node(T _data) :data(_data), next(NULL), prev(NULL)
		{
		}
		~Node()
		{
		}
	};

private:
	Node* head;   //시작 노드의 주소 
	Node* tail;   //꼬리 노드의 주소
	int size;     //개수

public:
	MyList();
	~MyList();

public:
	Node* get_head() { return head; }
	Node* get_tail() { return tail; }
	int   get_size() { return size; }

public:
	//데이터 반환
	T get_data(Node* cur) { return cur->data; }

	//저장
	void push_front(T data);
	void push_rear(T data);
	void push(Node* cur, T data);

	//삭제
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
		throw "노드 생성 에러";

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
		throw "노드 생성 에러";

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
		throw "노드 생성 에러";

	if (tail != cur)  //끼인상황
	{
		newnode->prev = cur;
		newnode->next = cur->next;
		cur->next->prev = newnode;
		cur->next = newnode;
	}
	else //왼쪽에만 노드가 존재:push_back과 동일 상황
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
	if (head->next == NULL) //노드가 하나인 상황
	{
		head = NULL;
		tail = NULL;
	}
	else  //노드가 여러개인 상황
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

	if (head->next == NULL) //노드가 하나인 상황
	{
		head = NULL;
		tail = NULL;
	}
	else  //노드가 여러개인 상황
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
	if (cur->prev == NULL) //제일 앞 노드 
	{
		return pop_front();
	}
	else if (cur->next == NULL) //제일 마지막 노드
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
기존 : MyList<>				<-- exam1()
개선 : MyList<>  MyStack<>  <--- exam2()
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


//기존  MyList를 그대로 활용
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



