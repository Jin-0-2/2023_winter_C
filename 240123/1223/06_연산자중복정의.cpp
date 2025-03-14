// 06_연산자중복정의.cpp
/*
객체도 연산자를 사용할 수 있게 하겠다.
방법1) 멤버함수 형태 operator
방법2) 전역함수 형태 : 멤버함수로 만들 수 없을 경우
	   friend 문법(친구를 사귀는 문법 -OOP파괴-)
*/
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
	
	Complex add(const Complex& c)
	{
		int _real = real + c.real;
		int _image = image + c.image;

		//Complex temp(_real, _image);
		//return temp;
		return Complex(_real, _image);
	}
	Complex operator+(const Complex& c)
	{
		int _real = real + c.real;
		int _image = image + c.image;

		return Complex(_real, _image);
	}

	friend Complex operator-(const Complex& c1, const Complex& c2);		// private 정보를 볼 수 있게 한다.
};

Complex operator-(const Complex& c1, const Complex& c2)
{
	return Complex(c1.real - c1.real, c1.image - c2.image);
}

int main()
{
	int num1 = 10;
	int num2 = 20;
	int result = num1 + num2;		// 30

	Complex c1(10, 20);			c1.print();
	Complex c2(30, 40);			c2.print();
	Complex c3 = c1.add(c2);	c3.print();

	Complex c4 = c1 + c2;			// c1.operator+(c2)
									// operator+(c1, c2)
	c4.print();

	Complex c5 = c1 - c2;			// c1.operator-(c2)
									// operator-(c1, c2)

	return 0;
}