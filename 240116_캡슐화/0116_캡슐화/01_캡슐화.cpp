// 01_캡슐화.cpp
#include <iostream>
using namespace std;

// C코드
/*
데이터(시간)와 기능(연산함수)이 분리되어있다.
*/
typedef struct tagmytime mytime;
struct tagmytime
{
	int hour;
	int min;
	int sec;
};

void print(const mytime* t)
{
	cout << t->hour << " : ";
	cout << t->min << " : ";
	cout << t->sec << endl;
}

void update_time(mytime* p, int h, int m, int s)
{
	p->hour = h;
	p->min = m;
	p->sec = s;
}

int main()
{
	mytime t1 = { 9,25,30 };
	mytime t2 = { 0,0,0 };

	print(&t2);

	print(&t1);

	update_time(&t1, 10, 30, 45);
	print(&t1);

	return 0;
}