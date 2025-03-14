//04_이중연결리스트 템플릿.cpp
/*
class Node
{
};
//WbList가 Node를 소유
class WbList
{
  Node * next;
};

//----------------- WbList에서 사용하는 전용 Node 클래스를 구성 -----------------
// 외부 클래스[내부 클래스] 
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
bool MyList<T>::Delete_Back()
{
	if (head == NULL) //비어있다
		throw "비어있는 상태";  //  return false;

	Node* del = tail; //마지막 노드
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

	return true;
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

int main()
{
	MyList<char> mlist;  //생성자 호출 -> 초기화

	//저장(10 20 30 40,50) & 출력
	for (int i = 0; i < 5; i++)
	{
		mlist.Push_Front('A' + i);
		//mlist.Push_Front('A' + i);
	}

	//전체출력
	mylist_printall(mlist);
	mylist_printall1(mlist);

	printf("\nRandom Insert 검증(앞, 중간, 뒤----------------------------------\n");
	printf("[첫번째 노드 다음]\n");
	mlist.Push_Random(mlist.getHead(), 'X');
	mylist_printall(mlist);
	mylist_printall1(mlist);

	printf("[세번째 노드 다음]\n");  // 10 15 20 [25] 30 ....
	mlist.Push_Random(mlist.getHead()->next->next, 'Y');
	mylist_printall(mlist);
	mylist_printall1(mlist);

	printf("[마지막 노드 다음]\n");  // 10 15 20 25 30 40 50 [55]
	mlist.Push_Random(mlist.getTail(), 'Z');
	mylist_printall(mlist);
	mylist_printall1(mlist);

	//검색
	MyList<char>::Node* sel = mylist_select(mlist, 'C');
	if (sel == NULL)
		printf("없다\n");
	else
	{
		char value = sel->data;
		printf("찾은 값 : %c\n", value);
	}

	//삭제
	printf("\n렌덤 삭제-----------------------------------------------\n");
	mylist_printall(mlist);
	mylist_printall1(mlist);
	printf("\n");

	printf("[첫번째 노드 삭제]\n");
	mlist.Delete_Random(mlist.getHead());
	mylist_printall(mlist);
	mylist_printall1(mlist);

	printf("[세번째 노드 다음]\n");  //15 20 [25] 30 40 50 55...
	mlist.Delete_Random(mlist.getHead()->next->next);
	mylist_printall(mlist);
	mylist_printall1(mlist);

	printf("[마지막 노드 다음]\n");  //15 20  30 40 50 [55]
	mlist.Delete_Random(mlist.getTail());
	mylist_printall(mlist);
	mylist_printall1(mlist);

	printf("\n삭제--------------------------------------------------\n");
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
			cout << "삭제 에러 : " << error << endl;
		}
	}

	return 0;
}