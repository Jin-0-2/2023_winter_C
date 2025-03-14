//03_접근지정자.cpp
/*
외부에서 멤버에 접근 허용/금지여부를 결정
- private   : 은닉(금지)
- protected :
- public    : 공개(허용)

struct : 기본 접근 지정자 : public
*/
#include <iostream>
using namespace std;

struct mytime
{
private:
	int hour;
	int min;
public:
	int sec;										

	void print()
	{
		cout << hour << " : ";
		cout << min << " : ";
		cout << sec << endl;
	}

private:
	void update_time(int h, int m, int s)				//수
	{
		hour = h;
		min = m;
		sec = s;
	}
};

int main()
{
	mytime t1;
	t1.sec = 10;
	t1.print();

	return 0;
}