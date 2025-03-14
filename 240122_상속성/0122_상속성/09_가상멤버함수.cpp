// 09_가상멤버함수.cpp
/*
부모의 포인터로 대입한 자식객체의
메서드를 호출하는 기능
*/
#include <iostream>
using namespace std;

class animal
{
	// 가상(virtual)멤버 함수 --> 재정의가 되어지 않으면 자신것을 사용
public:
	virtual void sound() { cout << "멍냥" << endl; }		// 자식에의해서 재정의가 될 수 있는 함수
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

// [컴파일러는] 호출하는 타입이 중요하다.
// 어떤 타입의 주소가 저장되었는지 중요하지 않다.
int main()
{
	dog dog1;
	animal* ani1;
	ani1 = &dog1;				//up casting
	ani1->sound();				// 멍냥

	animal* ani2 = new cat;		// up casting
	ani2->sound();				// 멍냥

	// 만약 동물들을 관리하고 싶다면?
	// 업캐스팅을 이용하면 통합 관리가 가능하다.
	animal* woori[4];
	woori[0] = new dog;
	woori[1] = new cat;
	woori[2] = new dog;
	woori[3] = new cat;

	// 모든 동물들이 소리를 낸다.
	for (int i = 0; i < 4; i++)
	{
		//woori[i]의 주소를 반환->sound();
		woori[i]->sound();

		// animal* ani = woori[i];
		// ani->sound;
	}
	return 0;
}