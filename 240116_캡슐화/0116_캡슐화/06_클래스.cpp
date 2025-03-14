//06_클래스.cpp
/*
1) C언어의 struct	 : 데이터만 캡슐화 가능
2) C++언어의 struct  : 데이터 + 함수 캡슐화 가능
					   기본 접근지정자 : public
3) C++언어의 class   : 객체를 정의하기 위한 목적의 키워드
					   C++언어의 struct와 대부분 동일하다.
					   단, 기본 접근지정자 : private
*/
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
	mytime t1;
	mytime t2(11, 23, 22);

	t1.set_hour(11);
	t1.set_min(16);
	t1.set_sec(55);

	t1.print();
	t2.print();

	return 0;
}