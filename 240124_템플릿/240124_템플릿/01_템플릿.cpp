// 01_템플릿.cpp
/*
함수나 클래스를 만들 수 있는 툴
- 함수 템플릿	: 타입에 관계없이 연산
- 클래스 템플릿	: 보통 저장소 역할
*/
#include <iostream>
using namespace std;

// 큰 값을 반환하는 함수(정수, 문자, 실수, 문자열)
// 방법1) 오버로딩	 : 필요한 함수를 내가 직접 구현
// 방법2) 함수템플릿 : 함수를 만드는 방법을 제시
//					   컴파일러가 자동으로 함수를 만들어 준다.

int mymax(int n1, int n2)
{
	if (n1 > n2) return n1;
	else	     return n2;

}

int mymax(float n1, float n2)
{
	if (n1 > n2) return n1;
	else	     return n2;
}

char mymax(char n1, char n2)
{
	if (n1 > n2) return n1;
	else	     return n2;
}

string mymax(string n1, string n2)
{
	if (n1 > n2) return n1;
	else	     return n2;
}

int main()
{
	cout << mymax(10, 20) << endl;
	cout << mymax(20.1f, 22.3f) << endl;
	cout << mymax('C', 'A') << endl;
	cout << mymax("ABC", "ABCDE") << endl;
	return 0;
}