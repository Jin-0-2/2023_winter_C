// 09_이중연결리스트 주소저장.cpp
#include <iostream>
using namespace std;

// 정수주소 저장 전용 노드;
struct Node
{
	int* data;		// 데이터 저장소      int -> int*
	Node* next;		// 다음 노드 주소
	Node* prev;
};

struct MyList
{
	Node* head;		// 시작 노드의 주소
	Node* tail;		// 꼬리 노드의 주소
	int size;		// 옵션
};

// --------- 초기화 ------------
void mylist_init(MyList* plist)
{
	plist->head = NULL;
	plist->tail = NULL;
	plist->size = 0;
}

// ---------- 저장 ------------
// 인자 전달시 : int -> int*
// 내부 코드 수정 없음
void mylist_push_front(MyList* plist, int* data)	// ************
{
	Node* newnode = new Node;
	if (newnode == NULL)
		return;

	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = NULL;

	if (plist->head == NULL)
	{
		plist->head = newnode;
		plist->tail = newnode;
	}
	else
	{
		newnode->next = plist->head;
		plist->head->prev = newnode;
		plist->head = newnode;
	}
	plist->size++;
}

void mylist_push_back(MyList* plist, int* data)
{
	Node* newnode = new Node;
	if (newnode == NULL)
		return;

	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = NULL;

	if (plist->head == NULL)
	{
		plist->head = newnode;
		plist->tail = newnode;
	}
	else
	{
		newnode->prev = plist->tail;
		plist->tail->next = newnode;
		plist->tail = newnode;
	}
	plist->size++;
}

// 2번째 인자로 전달된 다음에 넣겠다.
void mylist_push(MyList* plist, Node* cur, int* data)
{
	Node* newnode = new Node;
	if (newnode == NULL)
		return;

	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = NULL;

	if (plist->tail != cur)		//끼인상황
	{
		newnode->prev = cur;
		newnode->next = cur->next;
		cur->next->prev = newnode;
		cur->next = newnode;
	}
	else						// 왼쪽에만 노드가 존재 : push_back과 동일 상황
	{
		newnode->prev = plist->tail;
		plist->tail->next = newnode;
		plist->tail = newnode;
	}
	plist->size++;
}

// ----------- 삭제 -----------------
void mylist_pop_front(MyList* plist)
{
	if (plist->head == NULL)
	{
		cout << "empty" << endl;
		return;
	}

	if (plist->head->next == NULL)			// 노드가 하나인 상황
	{
		Node* del = plist->head;
		plist->head = NULL;
		plist->tail = NULL;

		delete del;
		plist->size--;
	}
	else									// 노드가 둘 이상인 경우
	{
		Node* del = plist->head;
		plist->head = del->next;
		plist->head->prev = NULL;

		delete del;
		plist->size--;
	}
}

void mylist_pop_back(MyList* plist)
{
	if (plist->head == NULL)
	{
		cout << "empty" << endl;
		return;
	}

	if (plist->head->next == NULL)			// 노드가 하나인 상황
	{
		Node* del = plist->head;
		plist->head = NULL;
		plist->tail = NULL;

		delete del;
		plist->size--;
	}
	else									// 노드가 둘 이상인 경우
	{
		Node* del = plist->tail;
		plist->tail = del->prev;
		plist->tail->next = NULL;

		delete del;
		plist->size--;
	}
}

// cur 노드 삭제
void mylist_pop(MyList* plist, Node* cur)
{
	if (cur->prev == NULL)		// 제일 앞 노드
	{
		mylist_pop_front(plist);
	}
	else if (cur->next == NULL)	// 제일 마지막 노드
	{
		mylist_pop_back(plist);
	}
	else						// 중잔에 낄 노드
	{
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
		delete cur;
		plist->size--;
	}
}

// ----------- 전체출력 -------------
// head->next
// 노드의 저장 타입이 변경되면 전체 출력 코드는 변경될 수 밖에 없다.
// 이유) 데이터 접근 코드를 갖고 있다.
void mylist_printall1(MyList* plist)
{
	cout << plist->size << " : ";
	for (Node* cur = plist->head; cur != NULL; cur = cur->next)
	{
		int* data = cur->data;
		cout << *data << " ";
	}
	cout << endl;
}

// tail->prev
void mylist_printall2(MyList* plist)
{
	cout << plist->size << " : ";
	for (Node* cur = plist->tail; cur != NULL; cur = cur->prev)
	{
		int* data = cur->data;
		cout << *data << " ";
	}
	cout << endl;
}

int main()
{
	MyList list;
	mylist_init(&list);

	for (int i = 10; i <= 50; i = i + 10)
		mylist_push_back(&list, new int(i));					// --------
	mylist_printall1(&list);
	mylist_printall2(&list);

	cout << "\n10 20 30 [35] 40 50" << endl;
	mylist_push(&list, list.head->next->next, new int(35));		// --------
	mylist_printall1(&list);
	mylist_printall2(&list);

	cout << "\n10 20 30 35 40 50 [55]" << endl;
	mylist_push(&list, list.tail, new int(55));					// --------
	mylist_printall1(&list);
	mylist_printall2(&list);

	// mylist_pop(&list, list.head);
	// mylist_pop(&list, list.tail);
	mylist_pop(&list, list.head->next->next);
	mylist_printall1(&list);
	mylist_printall2(&list);


	/*for (int i = 0; i < 8; i++)
	{
		mylist_pop_back(&list);
		mylist_printall1(&list);
		mylist_printall2(&list);
	}*/


	return 0;
}