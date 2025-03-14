// 09_멤버함수의 외부정의.cpp
/*
				C
헤더파일[정보]	함수선언, 구조체 정의, #define
소스파일		함수정의

				C++
헤더파일[정보]			  클래스정의(객체정의) - 함수선언
소스파일				  멤버함수정의
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
	int get_hour();
	int get_min();
	int get_sec();
	void set_hour(int h);
	void set_min(int m);
	void set_sec(int s);

public:
	void print();
};

int mytime::get_hour() { return hour; }
int mytime::get_min() { return min; }
int mytime::get_sec() { return sec; }
void mytime::set_hour(int h) { hour = h; }
void mytime::set_min(int m) { min = m; }
void mytime::set_sec(int s) { sec = s; }

void mytime::print()
{
	cout << hour << " : ";
	cout << min << " : ";
	cout << sec << endl;
}

int main()
{
	// 객체를 main 스택에 생성
	mytime t1(11, 33, 55);
	mytime t2();

	// 객체를 heap에 생성, 그 주소를 stack에 저장
	mytime* p1 = new mytime(11, 33, 50);
	mytime* p2 = new mytime;

	delete p1;
	delete p2;
	p1->print();

	return 0;
}