// 14_소유.cpp
/*
 강력한 소유 관계 :  생과 사를 같이한다.
  - 생성자 & 소멸자에서 소유하는 객체의 생성 소멸처리
*/
#include <iostream>
using namespace std;

class pen
{
private:
	string color;
	int width;

public:
	pen(string _color, int _width) : color(_color), width(_width)
	{

	}
	~pen()
	{

	}

public:
	string get_color() const { return color; }
	int get_width() const { return width; }

public:
	void write(string msg)
	{
		printf("[%s:%d]", color.c_str(), width);
		cout << msg << endl;
	}
};

// pen과 생사를 같이 하겠다.
class student
{
private:
	pen* pen1;		// pen의 주소;

public:
	student(string color, int width)
	{
		pen1 = new pen(color, width);
	}
	~student()
	{
		delete pen1;
	}

public:
	void write()
	{
		string msg;
		cout << ">> ";		cin >> msg;

		if (pen1 != NULL)
			pen1->write(msg);		// 펜의 기능을 사용한다.	
	}
};

int main()
{
	student stu("red", 2);

	stu.write();
	stu.write();

	return 0;
}