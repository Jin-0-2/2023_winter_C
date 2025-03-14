// 11_this.cpp
/*
자신의 줏를 저장하고 있는 포인터
모든 멤버함수에 자동으로 전달되어 있기 때문에 멤버 함수 내에서 사용가능하다.
(단 인스턴스 멤버에만)
*/
#include <iostream>
using namespace std;

class Sample
{
	int num1;

public:
	Sample(int num1)
	{
		num1 = 10;
	}

public:
	void fun1(int n1) 	// void fun1(Sample * this, int n1)
	{
		num1 = n1;		// this->num1 = n1;
	}

	void fun2()
	{
		cout << this << endl;
	}
};
int main()
{
	Sample s1(10);			s1.fun1(11);		// fun1(&s1, 11);
	Sample s2(20);			s2.fun1(22);		// fun2(&s2, 22);

	cout << &s1 << "\t";			s1.fun2();
	cout << &s2 << "\t";			s2.fun2();

	return 0;
}