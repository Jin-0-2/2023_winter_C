// 10_이중연결리스트 클래스화.cpp
#include <iostream>
#include <conio.h>
using namespace std;

// 정수주소 저장 전용 노드;
class Node
{
public:
	int* data;		// 데이터 저장소     ----------------- int -> int*
	Node* next;		// 다음 노드 주소
	Node* prev;		// 이전 노드 주소

public:
	Node(int* _data) : data(_data), next(NULL), prev(NULL)
	{
	}
	~Node()
	{
	}
};

class MyList
{
private:
	Node* head;		// 시작 노드의 주소
	Node* tail;		// 꼬리 노드의 주소
	int size;		// 옵션

public:
	MyList();
	~MyList();

public:
	Node* get_head() { return head; }
	Node* get_tail() { return tail; }
	int   get_size() { return size; }

public:
	// 데이터 반환
	int* get_data(Node* cur) { return cur->data; }

	// 저장
	void push_front(int* data);
	void push_rear(int* data);
	void push(Node* cur, int* data);

	// 삭제
	int* pop_front();
	int* pop_rear();
	int* pop(Node* cur);
};

MyList::MyList() : head(NULL), tail(NULL), size(0)
{
}

MyList::~MyList()
{
}

// ---------- 저장 ------------
// 인자 전달시 : int -> int*
// 내부 코드 수정 없음
void MyList::push_front(int* data)
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

void MyList::push_rear(int* data)
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

// 2번째 인자로 전달된 다음에 넣겠다.
void MyList::push(Node* cur, int* data)
{
	Node* newnode = new Node(data);
	if (newnode == NULL)
		throw "노드 생성 에러";

	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = NULL;

	if (tail != cur)			//끼인상황
	{
		newnode->prev = cur;
		newnode->next = cur->next;
		cur->next->prev = newnode;
		cur->next = newnode;
	}
	else						// 왼쪽에만 노드가 존재 : push_back과 동일 상황
	{
		newnode->prev = tail;
		tail->next = newnode;
		tail = newnode;
	}
	size++;
}

// ----------- 삭제 -----------------
int* MyList::pop_front()
{
	if (head == NULL)
		throw "empty";
	Node* del = head;
	int* pdata = del->data;			//-*******************
	if (head->next == NULL)			// 노드가 하나인 상황
	{
		head = NULL;
		tail = NULL;
	}
	else							// 노드가 여러개인 상황
	{
		head = del->next;
		head->prev = NULL;
	}
	delete del;
	size--;

	return pdata;					//********************
}

int* MyList::pop_rear()
{
	if (head == NULL)
		throw "empty";

	Node* del = head;
	int* pdata = del->data;

	if (head->next == NULL)
	{
		head = NULL;
		tail = NULL;
	}
	else
	{
		tail = del->prev;
		tail->next = NULL;
	}
	delete del;
	size--;

	return pdata;
}

// cur 노드 삭제
int* MyList::pop(Node* cur)
{
	if (cur->prev == NULL)
	{
		return pop_front();
	}
	else if (cur->next == NULL)
	{
		return pop_rear();
	}
	else
	{
		int* pdata = cur->data;

		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
		delete cur;
		size--;

		return pdata;
	}
}

// ----------- 사용클래스 ----------------
class Control
{
private:
	MyList list;		// 객체 생성 has a

public:
	void printall1()
	{
		cout << list.get_size() << " : ";
		for (Node* cur = list.get_head(); cur != NULL; cur = cur->next)
		{
			int* data = cur->data;
			cout << *data << " ";
		}
		cout << endl;
	}

	void printall2()
	{
		cout << list.get_size() << " : ";
		for (Node* cur = list.get_tail(); cur != NULL; cur = cur->prev)
		{
			int* data = cur->data;
			cout << *data << " ";
		}
		cout << endl;
	}

	void insert()
	{
		try
		{
			int num;
			cout << "정수 입력 : "; cin >> num;

			int* pdata = new int(num);

			list.push_front(pdata);

			cout << "저장성공" << endl;
		}
		catch (const char* msg)
		{
			cout << msg << endl;
		}
	}

	void select()
	{
		try
		{
			int num;
			cout << "검색할 정수 입력 : "; cin >> num;

			Node* cur = value_to_Node(num);

			cout << "검색결과" << endl;
			cout << *(cur->data) << endl;
		}
		catch (const char* msg)
		{
			cout << msg << endl;
		}
	}

	void update()
	{
		try
		{
			int num;
			int num1;
			cout << "검색할 정수 입력 : "; cin >> num;
			cout << "수정할 정수 입력 : "; cin >> num1;

			Node* cur = value_to_Node(num);

			int* pdata = cur->data;
			*pdata = num1;

			cout << "수정성공" << endl;
		}
		catch (const char* msg)
		{
			cout << msg << endl;
		}
	}

	void remove()
	{
		try
		{
			int num;
			cout << "삭제할 정수 입력 : "; cin >> num;

			Node* cur = value_to_Node(num);

			int* pdata = list.pop(cur);

			delete pdata;		//**********************************

			cout << "삭제성공" << endl;
		}
		catch (const char* msg)
		{
			cout << msg << endl;
		}
	}

private:
	Node* value_to_Node(int value)
	{
		for (Node* cur = list.get_head(); cur != NULL; cur = cur->next)
		{
			int* data = cur->data;
			if (*data == value)
				return cur;
		}
		throw "없다"; // NULL;
	}
};

int main()
{
	Control con;
	
	while (true)
	{
		system("cls");
		con.printall1();
		cout << "---------------------------------------------------" << endl;
		cout << "[1]insert [2] select [3] update [4] delete [5] exit" << endl;
		cout << "---------------------------------------------------" << endl;
		switch (_getch())
		{
		case '1': con.insert(); break;
		case '2': con.select(); break;
		case '3': con.update(); break;
		case '4': con.remove(); break;
		case '5': return 0;
		}

		system("pause");
	}
	return 0;
}