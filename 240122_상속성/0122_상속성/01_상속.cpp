// 01_상속.cpp
/*
OOP 프로그래밍? 객체(캡슐화[데이터+기능]) 중심의 프로그래밍
--------------------------------------------------------------
OOP 1번째 개념 : 캡슐화	데이터와 기능을 하나로 묶어서 관리
OOP 2번째 개념 : 상속	부모와 자식간 관계 구성(is a)
*/

// 상속 1) 부모의 멤버 필드와 멤버 메서드는 자식에게 물려진다.
//		   자식은 필요에 의해 멤버 필드, 멤버 메서드를 추가한다. (확장)
#include <iostream>
using namespace std;
	
class parent					// 부모, 기반
{	
private:
	int num1;
	int num2;
public:
	void fun1() { cout << "parent::fun1()" << endl; }
	void fun2() { cout << "parent::fun2()" << endl; }
};

class child : public parent		// 자식, 파생
{
private:
	int num3;
public:
	void fun3() { cout << "child::fun3()" << endl; }
};

int main()
{
	parent p1;
	cout << sizeof(p1) << endl;		// 8byte
	p1.fun1();
	p1.fun2();

	cout << "\n\n자식" << endl;
	child c1;
	cout << sizeof(c1) << endl;		// 12byte

	c1.fun1();
	c1.fun2();
	c1.fun3();


	return 0;
}