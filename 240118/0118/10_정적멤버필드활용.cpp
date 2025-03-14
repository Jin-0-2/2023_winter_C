// 10_정적멤버필드활용.cpp
#include <iostream>
using namespace std;

class Card
{
private:
	int number;		// 1~10. 11(J), 12(Q), 13(K)
	char shape;		// S, C, H, D
	static int width;
	static int height;

public:
	Card(int _number, char _shape) : number(_number), shape(_shape)
	{
		width = 150;
	}

public:
	void print() const
	{
		cout << number << "\t";
		cout << shape << "\t";
		cout << width << "\t";
		cout << height << endl;
	}
};

int Card::width = 100;
int Card::height = 50;

int main()
{
	Card c1(1, 'H');		c1.print();
	Card c2(2, 'D');		c2.print();
	return 0;
}