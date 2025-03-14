// 01_¹¬½ÃÀûÇüº¯È¯.cpp
#include <iostream>
using namespace std;

class Sample
{
private:
	string name;
	int age;
public:
	Sample(string _name, int _age) : name(_name), age(_age) {}
public:
	operator string() { return name; }
	operator int() { return age; }
};

int main()
{
	Sample s1("È«±æµ¿", 10);

	string name = s1;		cout << name << endl;
	int age     = s1;		cout << age << endl;
	
	return 0;
}