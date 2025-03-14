// 08_함수오버로딩(overloading).cpp
/*
리턴타입 함수명 (매개변수 리스트);
[식별자]
C언어   : 함수명   -> 동일한 이름의 함수 정의 X
C++언어 : 메서드명(함수 + 매개변수 리스트) 
				   -> 이름이 동일해도 매개변수 리스트 다르면 가능

함수의 오버로딩 : 이름은 같지만 매개변수가 다른 함수의 관계들
*/
#include <iostream>
using namespace std;

// float my_add(int n1, int n2) {}
int my_add(int n1, int n2) { return n1 + n2; }
int my_add(int n1, int n2, int n3) { return n1 + n2 + n3; }		// 위 아래 my_add의 관계는 함수의 오버로딩 관계
float my_add(float n1, float n2) { return n1 + n2; }			// 리턴은 오버로딩과 관련 X

int main()
{
	cout << my_add(10, 20) << endl;		// 30
	cout << my_add(10, 20, 30) << endl;	// 60
	cout << my_add(10.123f, 29.2f) << endl; //39.323

	return 0;
}