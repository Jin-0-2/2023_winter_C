// 06_이중연결리스트시작점.cpp
#include <iostream>
using namespace std;

// 정수 저장 전용 노드;
struct Node
{
	int data;		// 데이터 저장소
	Node* next;		// 다음 노드 주소
	Node* prev;
};

struct MyList
{
	Node* head;		// 시작 노드의 주소
	Node* tail;		// 꼬리 노드의 주소
	int size;		// 옵션
};

void mylist_init(MyList* plist)
{
	plist->head = NULL;
	plist->tail = NULL;
	plist->size = 0;
}

int main()
{
	MyList list;
	mylist_init(&list);

	return 0;
}