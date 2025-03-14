// 12_이중연결리스트 member* 회원정보.cpp
/*
데이터 : member
저장   : MyList<> : 일반화
관리   : Control
*/
#include <iostream>
using namespace std;
#include <conio.h>		// _getch();

class Member
{
private:
	string name;
	string phone;

public:
	Member(string _name, string _phone) : name(_name), phone(_phone)
	{
	}

public:
	string get_name() { return name; }
	string get_phone() { return phone; }
	void set_phone(string _phone) { phone = _phone; }
public:
	void print() const
	{
		cout << name << " : " << phone << endl;
	}
	void println() const
	{
		cout << "이    름 : " << name << endl;
		cout << "전화번호 :" << phone << endl;
	}
};

template<typename T>
class MyList
{
public:
	class Node
	{
	public:
		T data;		// 데이터 저장소     ----------------- 
		Node* next;		// 다음 노드 주소
		Node* prev;		// 이전 노드 주소

	public:
		Node(T _data) : data(_data), next(NULL), prev(NULL)
		{
		}
		~Node()
		{
		}
	};

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
	T get_data(Node* cur) { return cur->data; }

	// 저장
	void push_front(T data);
	void push_rear(T data);
	void push(Node* cur, T data);

	// 삭제
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

// ---------- 저장 ------------
// 인자 전달시 : int -> int*
// 내부 코드 수정 없음
template<typename T>
void MyList<T>::push_front(T data)
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

// 2번째 인자로 전달된 다음에 넣겠다.
template<typename T>
void MyList<T>::push(Node* cur, T data)
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
template<typename T>
T MyList<T>::pop_front()
{
	if (head == NULL)
		throw "empty";
	Node* del = head;
	T pdata = del->data;			//-*******************
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

template<typename T>
T MyList<T>::pop_rear()
{
	if (head == NULL)
		throw "empty";

	Node* del = head;
	T pdata = del->data;

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
template<typename T>
T MyList<T>::pop(Node* cur)
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
		T pdata = cur->data;

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
	MyList<Member*> list;	// 객체 생성 has a

public:
	void printall1()
	{
		cout << list.get_size() << " : " << endl;
		for (MyList<Member*>::Node* cur = list.get_head(); cur != NULL; cur = cur->next)
		{
			Member* data = cur->data;
			data->print();
		}
		cout << endl;
	}

	void printall2()
	{
		cout << list.get_size() << " : ";
		for (MyList<Member*>::Node* cur = list.get_tail(); cur != NULL; cur = cur->prev)
		{
			Member* data = cur->data;
			data->print();
		}
		cout << endl;
	}

	void insert()
	{
		try
		{
			string name, phone;
			cout << "이    름 : "; cin >> name;
			cout << "전화번호 : "; cin >> phone;

			Member* pdata = new Member(name, phone);

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
			string name;
			cout << "검색할 이름 입력 : "; cin >> name;

			MyList<Member*>::Node* cur = value_to_Node(name);

			cout << "검색결과" << endl;
			cur->data->println();
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
			string name;
			string phone;
			cout << "검색할 이    름 : "; cin >> name;
			cout << "수정할 전화번호 : "; cin >> phone;

			MyList<Member*>::Node* cur = value_to_Node(name);

			Member* pdata = cur->data;
			pdata->set_phone(phone);

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
			string name;
			cout << "삭제할 이름 : "; cin >> name;

			MyList<Member*>::Node* cur = value_to_Node(name);

			Member* pdata = list.pop(cur);

			delete pdata;		//**********************************

			cout << "삭제성공" << endl;
		}
		catch (const char* msg)
		{
			cout << msg << endl;
		}
	}

private:
	MyList<Member*>::Node* value_to_Node(string value)
	{
		for (MyList<Member*>::Node* cur = list.get_head(); cur != NULL; cur = cur->next)
		{
			Member* data = cur->data;
			if (data->get_name()  == value)
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