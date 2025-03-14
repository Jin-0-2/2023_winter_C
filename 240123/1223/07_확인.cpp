//07_확인.cpp
#include <stdio.h>

//-------------------------- 라이브러리--------------
namespace mystd
{
	class myostream
	{
	public:
		myostream& operator<<(int value)
		{
			printf("%d", value);
			return *this;
		}
		myostream& operator<<(const char* value)
		{
			printf("%s", value);
			return *this;
		}
		myostream& operator<<(myostream& (*fun)(myostream& os))
		{
			return fun(*this);
		}
	};

	myostream& endl(myostream& os)
	{
		fflush(stdout);
		printf("\n");
		return os;
	}

	myostream mycout;
}
//-------------------------- 라이브러리--------------

using namespace mystd;

#include <iostream>
using namespace std;

ostream& mytab(ostream& os)
{
	cout << "\t";
	return os;
}


int main()
{
	mycout << 10;		//mycout.operator<<(10);
	mycout << "문자열";	//mycout.operator<<("문자열");
	mycout << 10 << "문자열" << endl;

	//-------------------------------
	cout << 10;
	cout << 10 << mytab << "문자열" << endl;

	return 0;
}
