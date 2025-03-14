//  06_확인3.cpp
/*
출력함수를 제공하고자 한다.	void print() {}
부모로부터 물려받은 print는 이름과 나이만 출력
자식은 이름, 나이, 학교, 학과를 출력할 수있는 print가 필요
따라서, 재정의가 필요해진다.

방법3_고수) 재정의 대사의 함수를 활용하자.
			이미 내가 원하는 기능은 부모가 갖고 있다.
*/
#include <iostream>
using namespace std;

class person
{
	//private:				// 자신만 접근
protected:				// 자식까지 접근 허용
	string name;
	int age;
public:
	person(string _name, int _age) : name(_name), age(_age) {}
public:
	string get_name() { return name; }
	int get_age() { return age; }
public:
	void print()
	{
		cout << name << "\t";
		cout << age << "\t";
	}
};

class student : public person
{
private:
	string univer;
	string major;
public:
	student(string _name, int _age, string _uni, string _ma) : person(_name, _age), univer(_uni), major(_ma)
	{
	}
	string get_univer() { return univer; }
	string get_major() { return major; }
public:
	// 방법 3)
	void print()
	{
		person::print();			//*************** 중요! ************
		cout << univer << "\t";
		cout << major << endl;
	}
};

int main()
{
	student stu("홍길동", 10, "우송", "컴정");
	stu.print();

	return 0;
}