// wblib.cpp

#include "std.h"

int wblib::input_integer(string msg)
{
	int value;
	cout << msg << " : ";		cin >> value;
	return value;
}

char wblib::input_char(string msg)
{
	char value;
	cout << msg << " : ";		cin >> value;
	return value;
}

float wblib::input_float(string msg)
{
	float value;
	cout << msg << " : ";		cin >> value;
	return value;
}

string wblib::input_string(string msg)
{
	string value;
	cout << msg << " : ";		cin >> value;
	return value;
} 