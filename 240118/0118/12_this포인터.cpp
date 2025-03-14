// 12_this포인터.cpp
#include <iostream>
using namespace std;

class Sample
{
	int num1;

public:
	Sample(int num1) : num1(num1)				// 멤버변수(매개변수) 위치가 고정이라 this 사용 X
	{
		this->num1 = num1;
	}

public:

};

int main()
{
	return 0;
}