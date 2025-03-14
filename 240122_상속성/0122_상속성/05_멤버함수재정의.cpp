// 05_멤버함수재정의.cpp
/*
오버라이드(override) == 멤버함수 재정의
상속관계에서 자시은 부모로부터 물려받은 멤버함수를 다시 정의할 수 있다.
*/
#include <iostream>
using namespace std;

class parent
{
public:
	void fun1(int n1, int n2) { cout << "parent::fun1()" << endl; }
	void fun2(int n1, int n2) { cout << "parent::fun2()" << endl; }
};

// child 객체가 사용할 수 있는 멤버 함수의 개수는 3개
// 재정의 : 기존함수를 유지한 생테에서 새로 정의하는 것
//			단, 부모로부터 물려받은 함수는 은닉된다.
class child : public parent
{
public:
	void fun2(int n1, int n2) const { cout << "child::fun2" << endl; }
};

int main()
{
	parent p1;
	p1.fun1(1, 2);
	p1.fun2(1, 2);

	child c1;
	c1.fun1(1, 2);
	c1.fun2(1, 2);
	c1.parent::fun2(1, 2);


	return 0;
}