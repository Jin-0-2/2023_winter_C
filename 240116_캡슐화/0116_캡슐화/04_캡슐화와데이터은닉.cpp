// 04_캡슐화와데이터은닉.cpp
/*
[캡슐화 규칙] 데이터는 반드시 은닉한다.
			  데이터의 안정성(무결성) 확보 이유

[get & set 메서드]
은닉된 데이터를 외부에서 간접적으로 접근할 수 있도록 제공해주는 메서드
*/
#include <iostream>
using namespace std;

struct mytime
{
private:
	int hour;
	int min;
	int sec;

	// get & set 메서드
public:
	int get_hour() { return hour; }			// 리턴
	void set_hour(int h)					// 정보 변경
	{
		if (h < 0 || h>24)
			return;

		hour = h;
	}

public:
	void print()
	{
		cout << hour << " : ";
		cout << min << " : ";
		cout << sec << endl;
	}

	void update_time(int h, int m, int s)
	{
		hour = h;
		min = m;
		sec = s;
	}
};

int main()
{
	mytime t1;
	t1.update_time(10, 44, 55);
	t1.print();

	// t1.hour = -1;	// 멤버 변수의 외부 접근 불가! > 안정성 확보
	t1.print();

	// get & set 메서드를 이용한 시간정보 접근
	t1.set_hour(11);
	cout << "시간 : " << t1.get_hour() << endl;


	return 0;
}