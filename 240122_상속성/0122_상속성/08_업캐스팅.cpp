// 09_업(up)캐스팅.cpp
/*
캐스팅(형변환)
상속관계에서 자식의 주소를 부모의 *에 대입할 수 있다.
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

// [컴파일러는] 호출하는 타입이 중요하다.
// 어떤 타입의 주소가 저장되었는지 중요하지 않다.
int main()
{
	dog dog1;
	animal* ani1;
	ani1 = &dog1;				//up casting
	ani1->sound();				// 멍ㄴ야
			
	animal*	ani2 = new cat;		// up casting
	ani2->sound();				// ?멍냥

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