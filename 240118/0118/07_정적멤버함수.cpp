// 07_정적멤버함수.cpp
/*
정적 == static

1. 인스턴트 멤버	
   생성된 객체를 이요하여 사용할 수 있는 멤버

2. 클래스 멤버(static)
   객체 없이 클래스 명으로 사용이 가능한 멤버
   클래스 멤버는 클래스 멤버만 사용가능
*/
#include <iostream>
using namespace std;

class Sample
{
	int num;

public:
	void fun() { num++; }

public:
	static void s_fun()
	{
		// fun();    // 에러
		s_fun1();
	}
	static void s_fun1() {}
};

int main()
{
	Sample s1;	// 객체 생성 / 인스턴스 생성
	s1.fun();

	Sample::s_fun();		// 객체 없이 사용 가능

	return 0;
}