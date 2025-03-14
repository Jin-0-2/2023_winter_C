// 09_기본값(디폴트매개변수).cpp
/*
선언부나 구현부 중 한곳에서만 처리 (보통은 선언부에 처리)

 - 인자전달은 무조건 첫번째 매개변수로부터 시작한다.
 - 기본값은 반드시 마지막 매개변수로부터 역으로 사용한다.
	void fun1(int n1 = 10, int n2)	// 에러
	fun1(1)	// 에러
*/
#include <iostream>
using namespace std;

void fun1(int n1, int n2 = 10, char ch = 'A');

int main()
{
	fun1(10, 20, 'B');		// 10, 20, B
	fun1(10, 20);			// 10, 20, A
	fun1(10);				// 10, 10, A
	return 0;
}

void fun1(int n1, int n2 /*= 10*/, char ch /*= 'A'*/)
{
	cout << n1 << "\t";
	cout << n2 << "\t";
	cout << ch << endl;
}