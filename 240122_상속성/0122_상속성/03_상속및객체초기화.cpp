// 03_상속및객체초기화.cpp
/*
생성자는 [자신의 멤버필드]를 초기화한다.

외부에서 바라몰 때는 하나의 클래스로 구송되었는지, 상속구조로 
구성되었는지는 모른다.

자식 생성자는 부모의 어떤 생성자를 통해 생성될지를 결정주어야 한다.
만약, 결정을 안해주면 부모는ㄴ 인자가 없는 생성자를 호출하게된다.
*/
#include <iostream>
using namespace std;

class parent
{
private:
	int num1;
	int num2;
public:
	parent()
	{
		cout << "parent::parent()" << endl;
	}
	parent(int n1, int n2) : num1(n1), num2(n2)
	{
		cout << "parent::parent(int,int)" << endl;
	}
};

class child : public parent
{
private:
	int num3;
	int num4;
public:
	child() : parent(1, 2)
	{
		cout << "child::child()" << endl;
	}
	child(int n1, int n2, int n3, int n4) :parent(n1, n2), num3(n3), num4(n4)	
	{
		cout << "child::child(int,int,int,int)" << endl;
	}

};


int main()
{
	child c2;

	// child가 정수 4개를 받는 생성자가 제공이 되어야한다.
	//child c1(1,2,3,4);		// 16byte짜리 객체, 정수 4개르 가지고 있는 객체

	return 0;
}