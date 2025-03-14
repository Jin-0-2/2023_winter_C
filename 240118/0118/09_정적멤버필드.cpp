// 09_정적멤버필드.cpp
/*
인스턴스 멤버들 간 [공유]되는 데이터
*/
#include <iostream>
using namespace std;

/*
200		Sample::s_num	0 -> 1
[전역 정적 메모리]

112		s2.num2		x
108		s2.num1		x
104		s1.nun2		x
100		s1.num1		x
[stack]
*/

class Sample
{
private:
	int num1;
	int num2;
	static int s_num;		// 클래스 멤버		// 객체와 무관

public:
	void fun1()
	{
		s_num++;
		cout << s_num << endl;
	}
};

// 정적멤버변수는 반드시 클래스 외부에서 초기화
// 이 대 메모리 생성 : main 함수 호출 전
int Sample::s_num = 0;		

int main()
{
	cout << sizeof(Sample) << endl;		// 8byte

	Sample s1;			// num1, num2 > 8byte
	Sample s2;			

	s1.fun1();
	s2.fun1();

	return 0;
}