// 08_출력연산재재정의.cpp
#include <iostream>
using namespace std;

class Complex		// 복소수 클래스
{
	int real;
	int image;
public:
	Complex(int _real, int _image) : real(_real), image(_image)
	{}

public:
	void print() const
	{
		cout << real << " + " << image << "i" << endl;
	}
	// private 정보를 볼 수 있게 한다.
	friend ostream& operator<<(ostream& cout, const Complex& c1)
	{
		cout << c1.real << "+" << c1.image << "i";
		return cout;
	}
};

int main()
{
	Complex c1(10, 20);			
	c1.print();

	cout << c1 << endl;		// cout.operator<<(c1);
							// operator<<(cout, c1);
	return 0;
}