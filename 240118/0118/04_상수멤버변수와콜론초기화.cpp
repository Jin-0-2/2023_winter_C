// 04_상수멤버변수와 생성자콜론초기화.cpp
/*
상수 : const
 - 선언 시 반드시 초기화, 대입연산 불가능!

 생성자 : //선언과 동시 초기화연산
 {
	// 대입연산
 }

 int num1;
 num1 = 10;		// 대입연산

 int num2 = 10;		//선언과 동시에 초기화

 멤버필드 중 상수멤버는 반드시 콜론 초기화 영역을 사용!
 멤버필드 중 변수멤버는 가급적 콜론 초기화 영역을 사용해보자! > 코드 간결
*/
#include <iostream>
using namespace std;

class Sample
{
	//멤버필드(멤버 데이터)
private:
	int num1;				// 변수
	const int c_num1;		// 상수

public:
	Sample(int n1, int n2) : num1(n1 + 10), c_num1(n2 + 20)		// 효율적
	{
		// num1 = n1 + 10;
		// c_num1 = n2 + 20; ERROR
	}
};

int main()
{
	return 0;
}