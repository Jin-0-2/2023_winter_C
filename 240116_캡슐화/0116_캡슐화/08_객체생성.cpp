// 08_按眉积己.cpp
#include <iostream>
using namespace std;

class mytime
{
private:
	int hour;
	int min;
	int sec;

public:
	mytime(int h, int m, int s)
	{
		hour = h;
		min = m;
		sec = s;
	}
	mytime()
	{
		hour = 0;	min = 0;  sec = 0;
	}

public:
	int get_hour() { return hour; }
	int get_min() { return min; }
	int get_sec() { return sec; }
	void set_hour(int h) { hour = h; }
	void set_min(int m) { min = m; }
	void set_sec(int s) { sec = s; }

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
	// 按眉甫 main 胶琶俊 积己
	mytime t1(11, 33, 55);
	mytime t2();

	// 按眉甫 heap俊 积己, 弊 林家甫 stack俊 历厘
	mytime* p1 = new mytime(11, 33, 50);
	mytime* p2 = new mytime;

	delete p1;
	delete p2;
	p1->print();

	return 0;
}