// 03_按眉积己.cpp
#include <iostream>
using namespace std;

class Sample
{
public:
	Sample() { cout << "积己磊" << endl; }
	~Sample() { cout << "家戈磊" << endl; }
};

/*
Sample
*/

void exam1()
{
	Sample s1;				// 按眉 1俺 积己(main 胶琶)

	Sample* ps1;			// 按眉 积己苞 公包
	ps1 = new Sample;		// 按眉 1俺 积己(赛)

	delete ps1;				//按眉 家戈

}

void exam2()
{
	Sample arr[5];		// 按眉 积己 5俺
}

void exam3()
{
	Sample* arr[5];		// Sample 按俊疢 林家甫 5俺 历厘

	arr[0] = new Sample;		// 按眉 积己

	delete arr[0];
}

int main()
{
	exam3();
	return 0;
}