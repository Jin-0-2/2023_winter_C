// 03_다운캐스팅.cpp
#include <iostream>
using namespace std;

class animal
{
public:
	virtual void sound() = 0;		// 약속 ) 자식은 재정의를 반드시 해야한다.
};

class dog : public animal
{
public:
	void sound() { cout << "멍멍" << endl; }
	void swimm() { cout << "수영을한다." << endl; }
};

class cat : public animal
{
public:
	void sound() { cout << "야옹" << endl; }
};

int main()
{
	animal* anis[4];
	anis[0] = new dog;	anis[1] = new cat;
	anis[2] = new dog;	anis[3] = new cat;

	cout << "동물 전체가 소리를 낸다." << endl;
	for (int i = 0; i < 4; i++)
	{
		anis[i]->sound();
	}

	cout << "\n\n고양이만 소리를 낸다." << endl;
	for (int i = 0; i < 4; i++)
	{
		if (dynamic_cast<cat*>(anis[i]) != NULL)
			anis[i]->sound();
	}

	return 0;
}