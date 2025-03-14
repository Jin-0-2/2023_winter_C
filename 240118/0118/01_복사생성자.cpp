// 01_복사생성자.cpp
/*
컴파일러에 의해 복사 생성자가 제공된다.
복사 생성자는 멤버필드를 복사해 준다.

객체 생성
1. 메모리 생성
2. 생성자 호출(자동) : 생성자 -> 객체초기화 코드 작성

객체 소멸
1. 소멸자 호출(자동) : 객체 종료될 때 필요한 부분을 처리
2. 객체 메모리 소멸
*/
#include <iostream>
using namespace std;

class member
{
private:
	char name[20];
	int age;
	
public:
	member(const char* _name, int _age)
	{
		cout << "member(const char * , int)" << endl;
		strcpy_s(name, sizeof(name), _name);
		age = _age;
	}
	~member()
	{
		cout << "~member()" << endl;
	}

public:
	void print()
	{
		cout << name << ", " << age << endl;
	}
};

int main()
{
	member mem1("고길도", 10);			// 스택에 메모리 생성
	mem1.print();

	// mem1이라는 객체를 전달해서 mem2라는 객체를 생성
	// meme2의 멤버필드가 그대로 mem1에 복사되었다.
	// -> 자신과 동일한 객체를 전달하여 객체를 생성할 때
	//	  복사 생성자가 호출(컴파일러가 무조건 생성)
	member mem2(mem1);					// 스택에 메모리 생성

	return 0;
}