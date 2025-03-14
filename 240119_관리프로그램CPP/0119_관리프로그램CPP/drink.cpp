// drink.cpp
#include "std.h"

int drink::s_number = 1000;

drink::drink(string _title, int _price, int _count) : number(s_number), title(_title), price(_price), count(_count)
{
	s_number = s_number + 10;
}

drink::~drink()
{

}

string drink::get_title() const
{
	return title;
}

int drink::get_price() const
{
	return price;
}

int drink::get_count() const
{
	return count;
}

int drink::get_number() const
{
	return number;
}

void drink::set_price(int _price)
{
	price = _price;
}

void  drink::print() const
{
	cout << number << " : " << title << " : " << price << " : " << count << endl;
}

void  drink::println() const
{
	cout << "번  호 : " << number << endl;
	cout << "제품명 : " << title << endl;
	cout << "가  격 : " << price << "원" << endl;
	cout << "수  량 : " << count << "개" << endl;
}

void  drink::add_count(int _count)
{
	count = count + count;
}
