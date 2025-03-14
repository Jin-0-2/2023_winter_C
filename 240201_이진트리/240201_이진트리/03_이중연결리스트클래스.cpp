//03_이중연결리스트클래스.cpp
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
	Node* head;  //첫 노드 저장
	Node* tail;  //마지막 노드 저장
	int   size;  //저장 개수

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

bool MyList::Push_Back(int value)
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
		throw "메모리 부족";	//return false;

	if (cur == tail)  //꼬리노드 (push_back의 꼬리연결 코드 복사)
	{
		newnode->prev	= tail;
		tail->next		= newnode;
		tail			= newnode;
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

bool MyList::Delete_Front()
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

bool MyList::Delete_Back()
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

bool MyList::Delete_Random(Node* del)
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
			return cur;		//찾은 주소
		//---------------------------
		cur = cur->next;
	}
	return cur;				//NULL
}

int main()
{
	MyList mlist;  //생성자 호출 -> 초기화

	//저장(10 20 30 40,50) & 출력
	for (int i = 0; i < 5; i++)
	{
		//mlist.Push_Front((i + 1) * 10);
		mlist.Push_Front((i + 1) * 10);		//10 20 30 40		
	}

	//전체출력
	mylist_printall(mlist);	
	mylist_printall1(mlist);

	printf("\nRandom Insert 검증(앞, 중간, 뒤----------------------------------\n");
	printf("[첫번째 노드 다음]\n");
	mlist.Push_Random(mlist.getHead(), 15);
	mylist_printall(mlist);
	mylist_printall1(mlist);

	printf("[세번째 노드 다음]\n");  // 10 15 20 [25] 30 ....
	mlist.Push_Random(mlist.getHead()->next->next, 25);
	mylist_printall(mlist);
	mylist_printall1(mlist);

	printf("[마지막 노드 다음]\n");  // 10 15 20 25 30 40 50 [55]
	mlist.Push_Random(mlist.getTail(), 55);
	mylist_printall(mlist);
	mylist_printall1(mlist);

	//검색
	Node* sel = mylist_select(mlist, 55);
	if (sel == NULL)
		printf("없다\n");
	else
	{
		int value = sel->data;
		printf("찾은 값 : %d\n", value);
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