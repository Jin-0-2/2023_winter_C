// 02_상속과객체생성.cpp
/*
상속2) 자식객체가 생성되기 전 부모객체가 먼저 생성된다.
	   자식객체가 먼저 소멸되고 부모객체가 소멸된다.
	   - 이런 이유로 부모의 멤버가 자식에게 물려지는 일이 발생한다.
*/
#include <iostream>
using namespace std;

class parent
{
public:
	parent()	{ cout << "parent::parent()" << endl; }
	~parent()	{ cout << "parent::~parent()" << endl; }
};

class child : public parent
{
public:
	child()		{ cout << "child::child()" << endl; }
	~child()	{ cout << "child::~child()" << endl; }
};

	// 부모객체 생성
void exam1()
{
	parent p;					// stack 메모리
	cout << sizeof(p) << endl;	// 1byte

	parent* p1 = new parent;	// heap 메모리
	delete p1;
}

// 자식객체 생성
/*
1. 부모객체 생성(부모객체의 멤버필드를 저장할 메모리 생성 -> 생성자 호출)
2. 자식객체 생성(자식객체의 멤버필드를 저장할 메모리 생성 -> 생성자 호출)
==> 1,2의 결과물을 자식객체라고 한다.

자식객체 소멸 : 생성의 역순이다.
*/

void exam2()
{
	child c1;

	child* c2 = new child;		// heap에 저장
	delete c2;
}

int main()
{
	exam2();

	return 0;
}