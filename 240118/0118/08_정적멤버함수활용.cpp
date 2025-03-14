// 08_정적멤버함수활용.cpp
/*
객체 생성이 필요없는 경우
- 멤버 필드ㅏ 없는 객체.
- C언어의 전역함수를 대신할 수 있다.
  OPP는 전역이라는 개념이 없다.
*/
#include <iostream>
using namespace std;

class g_class
{
public:
	static int add(int n1, int n2) { return n1 + n2; }
	static int input_number(const char* msg)
	{
		int num;
		cout << msg << " : ";
		cin >> num;
		return num;
	}
};

int main()
{
	cout << g_class::add(10, 20) << endl;
	int num = g_class::input_number("정수 입력");
	cout << num << endl;
	return 0;
}