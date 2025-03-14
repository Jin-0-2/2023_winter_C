// 02_시작점.cpp
// 정수를 관리(배열, 단일연결리스트)
/*
배      열 : 저장공간이 이미 생성이 된다.
연결리스트 : 저장공간은 0인 상태
*/
#include <iostream>
using namespace std;

struct Myarr
{
	int* arr;
	int max;
	int size;
};

void myarr_init(Myarr* parr, int _max)
{
	parr->max = _max;
	parr->size = 0;
	parr->arr = new int[_max];
}

struct Node
{
	int data;		// 데이터 저장소

	Node* next;		// 다음 노드 주소
};

struct MyList
{
    Node* head;		// 첫번째 노드의 주소
	int size;		// 옵션
};


void mylist_init(MyList* plist)
{
	plist->head = NULL;
	plist->size = 0;
}

int main()
{
	Myarr arr;
	myarr_init(&arr, 10);

	MyList list;
	mylist_init(&list);

	return 0;
}