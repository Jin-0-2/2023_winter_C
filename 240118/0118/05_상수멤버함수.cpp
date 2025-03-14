// 05_상수멤버함수.cpp
/*
멤버변수를 변경하지 않겠다.
- 상수멤버함수는 상수멤버함수만 호출가능하다.
  일반멤버함수가 호출되면 일반멤버함수 내부에서 값변경이 가능

상수멤버함수는 멤버 변수의 값을 변경할 목적이 없을 때 사용 가능
*/
#include <iostream>
using namespace std;

class Sample
{
private:
	int num;

public:
	void fun(int n) const { }
	void fun2() { num++; }

	void fun1(int n) const	// 상수멤버함수
	{
		// num++	 //ERR
		n++;		 //ok

		fun(10);	 // ok
		//fun2();		 //ERR -> 값 변경이 될 수있음.
	}
};

int main()
{
	return 0;
}