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

tm wblib::get_cur_time()
{
	time_t timer = time(NULL);
	struct tm t;
	localtime_s(&t, &timer);

	return t;
}

string wblib::full_stringtime(tm t)
{
	char buf[256];
	sprintf_s(buf, "%04d-%02d-%02d %02d:%02d:%02d",
		t.tm_year + 1900, t.tm_mon + 1, t.tm_mday,
		t.tm_hour, t.tm_min, t.tm_sec);
	string str(buf);

	return str;
}

string wblib::date_stringtime(tm t)
{
	char buf[256];
	sprintf_s(buf, "%04d-%02d-%02d",
		t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
	string str(buf);

	return str;
}

string wblib::time_stringtime(tm t)
{
	char buf[256];
	sprintf_s(buf, "%02d:%02d:%02d",
		t.tm_hour, t.tm_min, t.tm_sec);
	string str(buf);

	return str;
}
