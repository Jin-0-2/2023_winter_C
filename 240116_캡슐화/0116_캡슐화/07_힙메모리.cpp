// 07_힙메모리.cpp
#include <iostream>
using namespace std;

// C언어의 힙메모리 사용 ( malloc(). free() )
void exam1()
{
	int* p1 = (int*)malloc(sizeof(int));		// 정수 1개
	int* arr = (int*)malloc(sizeof(int) * 5);	// 정수 5개(동적배열)

	*p1 = 1;
	arr[0] = 1;	 arr[1] = 2;	arr[4] = 4;

	free(p1);		p1 = NULL;
	free(arr);		arr = NULL;
}

// C++언어의 힙메모리 사용 ( new, delete 연산자 사용)
void exam2()
{
	int* p1 = new int;		// 힙에 int 1개 저장공간 생성 요청
	int* p2 = new int(5);	// 힙에 int 1개 저장공간 요청 및 5로 초기화
	int* arr = new int[5];	// 힙에 int 5개 저장공간 요청(동적배열)

	*p1 = 10;		cout << *p1 << endl;
	cout << *p2 << endl;
	arr[0] = 10;  arr[4] = 40;

	// 해당 주소에 있는 메모리 소멸 요청 (컴파일러는 타입이 중요)
	delete p1;
	delete p2;
	delete[] arr;		// 배열이 존재하는 주소라는 뜻
}
int main()
{
	exam1();

	return 0;
}