// 02_캡슐화.cpp
#include <iostream>
using namespace std;

// C++코드
/*
캡슐화 : 데이터(시간)와 기능(연산함수)을 통합
		 - 함수가 데이터를 갖고 있다!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

struct : 멤버로 변수와 함수를 갖는다.
		 멤버 접근 연산자(.)
*/
struct mytime
{
	int hour;											//데
	int min;											//이
	int sec;											//터

	void print()										//함
	{
		cout << hour << " : ";
		cout << min << " : ";
		cout << sec << endl;
	}

	void update_time(int h, int m, int s)				//수
	{
		hour = h;
		min = m;
		sec = s;
	}
};

int main()
{
	// C언어 : 변수 선언 -> C++ OOP : 객체 생성
	// 생성된 메모리의 크기? 12byte. 함수는 데이터 크키에 영향 X
	mytime t1 = { 9,25,30 };
	mytime t2 = { 0,0,0 };

	t1.print();		// print(&t1);
	t2.print();		// print(&t2);

	t1.update_time(10, 30, 45);			// update_time(&t1, 10, 30, 45);
	t1.print();							// print(&t1);

	return 0;
}