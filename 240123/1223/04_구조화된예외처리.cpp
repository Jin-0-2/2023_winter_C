// 04_구조화된예외처리.cpp
/*
[중요한 문법 -> 프로그램이 강제적으로 종료되는 것을 방지]
*/
#include <iostream>
using namespace std;

// try ~catch, throw
void exam1()
{
	try
	{
		int value = 1;
		cout << "문장1" << endl;
		if (value == 1)		
			throw "예외를 던진다;";
		cout << "문장2" << endl;
		cout << "문장3" << endl;
		if (value == 2)		
			throw 2;
		cout << "문장4" << endl;
		if (value == 3)
			throw 2.1f;
		cout << "문장5" << endl;
	}
	catch (const char* msg)
	{
		cout << "예외 발생 : " << msg << endl;
	}
	catch (int value)
	{
		cout << "예외 발생 : " << value << endl;
	}
	catch (...)
	{
		cout << "모든 타입의 예외를 받을 수 있다." << endl;
	}


	cout << "구조화된 예외처리 후 실행" << endl;
}

float my_div(int num1, int num2)
{
	if (num2 == 0)
		return 0.0f;
	return num1 / (float)num2;
}

void exam2()
{
	float result = my_div(10, 20);
	cout << result << endl;
}

float my_div1(int num1, int num2)
{
	if (num2 == 0)
		throw "0으로 나눌 수 없다.";

	return num1 / (float)num2;
}
void exam3()
{
	try
	{
		float result = my_div1(10, 0);
			cout << result << endl;
	}
	catch (const char* msg)
	{
		cout << "에러 : " << msg << endl;
	}
	
}

int main()
{
	exam3();

	return 0;
}