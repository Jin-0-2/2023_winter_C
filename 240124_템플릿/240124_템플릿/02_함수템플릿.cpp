// 02_함수템플릿.cpp
/*
함수나 클래스를 만들 수 있는 툴
- 함수 템플릿	: 타입에 관계없이 연산
- 클래스 템플릿	: 보통 저장소 역할
*/
#include <iostream>
using namespace std;

template<typename T>
T mymax(T n1, T n2)
{
	if (n1 > n2) return n1;
	else	     return n2;

}

int main()
{
	cout << mymax(10, 20) << endl;			// T -> int 함수 생성
	cout << mymax(20.1f, 22.3f) << endl;	// T -> float
	cout << mymax('C', 'A') << endl;		// T -> char
	cout << mymax("ABC", "ABCDE") << endl;	// T -> const char*
	return 0;
}