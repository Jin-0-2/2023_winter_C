// 02_복사생성자.cpp
/*
직접 복사생성자를 만들 수 있다.
- 만들 필요가 있을까?
  특별한 상황이 아니면 만들필요 없다.
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
	// 복사생성자
	member(const member& m)		
	{
		cout << "member(const member& m)" << endl;
		//strcpy_s(name, sizeof(name), m.name);
		//age = m.age;

		*this = m;
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

	member mem2(mem1);					// 스택에 메모리 생성

	return 0;
}