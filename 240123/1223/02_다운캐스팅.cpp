// 02_다운캐스팅.cpp
/*
업캐스팅 : 부모* p = new 자식;

다운 캐스팅 : 자식 *c = (자식*) p;		//p는 부모타입임, 강제형변환(자식)
*/
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
	// 업캐스팅 : 강아지의 확장 기능 사용 불가
	animal* ani = new dog;
	ani->sound();
	
	// 다시 다운캐스팅을 해야 한다.
	// 방법1) 강제적 형변환
	dog* pdog = (dog*)ani;
	pdog->sound();
	pdog->swimm();

	// 강제적 형변환은 무조건 성공하기 때문에 문제를 발생시킨다.
	cat* pcat = (cat*)ani;

	// 방법2) 다운캐스팅 전용 연산자를 제공(이것을 사용)
	// ani가 갖고있는 주소가 dog*인가?
	dog* pdog1 = dynamic_cast<dog*>(ani);
	if (pdog1 != NULL)
		pdog1->swimm();
	cat* pcat1 = dynamic_cast<cat*>(ani);
	if (pcat1 == NULL)
		cout << "고양이가 아니다" << endl;

	return 0;
}