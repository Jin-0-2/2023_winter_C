// 01_추상클래스와순수가상함수.cpp
/*
추상 == 미완성

순수가상함수(추상메서드) : 가상함수 + 구현부 X
  virtual void fun() = 0;

추상클래스
  멤버 중 하나 이상이 순수가상함수
  특징 1) 객체 생성이 불가능하다.
  특징 2) 반드시 누군가의 부모의 형태로만 사용가능하다.
		  자식은 물려받은 순수가상함수를 재정의해야 한다.
		  만약, 재정의 안하면 자식도 추상클래스가 된다.
*/

#include <iostream>
using namespace std;

/*
animal을 만들 생각이 없었다 -> 문법적으로 animal 객체도 생성이 가능해졌다.
animal::sound함수의 기능 구현 -> 해당 기능은 사용되지 않는다.
*/
class animal
{
public:
	virtual void sound() = 0;		// 약속 ) 자식은 재정의를 반드시 해야한다.
};

class dog : public animal
{
public:
	void sound() { cout << "멍멍" << endl; }
};

class cat : public animal
{
public:
	void sound() { cout << "야옹" << endl; }
};

int main()
{
	// animal ani;  객체 생성 불가

	animal* anis[2];
	anis[0] = new dog;
	anis[1] = new cat;

	for (int i = 0; i < 2; i++)
	{
		anis[i]->sound();
	}
	return 0;
}