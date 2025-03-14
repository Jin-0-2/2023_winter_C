#pragma once
class wblib
{
public:
	static int input_integer(string msg);
	static char input_char(string msg);
	static float input_float(string msg);
	static string input_string(string msg);

public:
	static tm get_cur_time();
	static string full_stringtime(tm t);
	static string date_stringtime(tm t);
	static string time_stringtime(tm t);

};