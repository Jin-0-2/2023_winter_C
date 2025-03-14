// 09_다형성.cpp
/*
OOP 프로그래밍? 객체(캡슐화[데이터+기능]) 중심의 프로그래밍
--------------------------------------------------------------
OOP 1번째 개념 : 캡슐화	데이터와 기능을 하나로 묶어서 관리
OOP 2번째 개념 : 상속	부모와 자식간 관계 구성(is a)
OPP 3번째 개념 : 다형성 동일 기능에 대한 다양한 반응?
				 함수 정의, 함수 호출
				 행위 정의, 메시지발생 : 행위는 메시지 발생을 통해 실행

[다형성]
1) 상속			   : 부모 / 자식관계 구성
					 (부모는 자식들의 공통 멤버를 갖는다)
2) 멤버함수 재정의 : 물려받은 기능을 다시 정의하겠다.
3) 업캐스팅		   : 자식의 주소를 부모의 *에 대입
4) 가생멤버함수	   : 부모의 포인터로 대입한 자식객체의 
					 메서드를 호출가능하게 하는 문법
*/

/*
강아지(소리를 낸다)
고양이(소리를 낸다)
*/
#include <iostream>
using namespace std;

class animal
{
public:
	void sound() { cout << "멍냥" << endl; }
};

class dog : public animal
{
public:
	void sound() { cout << "멍" << endl; }
};

class cat : public animal
{
public:
	void sound() { cout << "냥" << endl; }
};

int main()
{
	dog d1;		d1.sound();
	cat c1;		c1.sound();

	// 만약 동물들을 관리하고 싶다면?
	dog dogs[4];		// 선언과 동시에 정보도 없는 4개의 강아지가 생성
	cat cats[4];

	dog* pdogs[4];	pdogs[0] = new dog; pdogs[1] = new dog;
	cat* pcats[4];	

	return 0;
}