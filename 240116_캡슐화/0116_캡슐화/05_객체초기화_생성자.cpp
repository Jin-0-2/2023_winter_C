// 05_객체초기화와 생성자.cpp
/*
객체 생성과 동시에 초기화하는 것은 중요한 일이다.
- 데이터를 은닉하게 되면 기존 초기화 문법을 사용 X
- [대안] 생성자
		 목적 : 객체 초기화를 위한 특수한 형태의 멤버함수
		 반환타입이 X
		 함수명 : 약속되어있다.(타입명과 일치)
		 매개변수리스트 : 객체 초기화를 위한 목적으로 사용

		 객체 생성시 자동으로 호출된다.(직접 호출 불가)
*/
#include <iostream>
using namespace std;

struct mytime
{
private:
	int hour;
	int min;
	int sec;

	// 생성자
public:
	mytime(int h, int m, int s)
	{
		hour = h;
		min = m;
		sec = s;
	}

public:
	void print()
	{
		cout << hour << " : ";
		cout << min << " : ";
		cout << sec << endl;
	}
};

int main()
{
	//mytime t1 = { 9,30,43 };
	mytime t1(9,25,30);		// 생성자의 형태와 맵핑

	t1.print();

	return 0;
}