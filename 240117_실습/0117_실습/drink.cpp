// drink.cpp
#include <iostream>
using namespace std;

#include "drink.h"
#include "drink_machine.h"

drink::drink(string _name, int _price, int _count)
{
	name = _name;
	price = _price;
	count = _count;
}

drink::drink(string _name, int _price)
{
	name = _name;
	price = _price;
	count = 5;
}

string drink::get_name()
{
	return name;
}

int drink::get_price()
{
	return price;
}

int drink::get_count()
{
	return count;
}

void drink::set_price(int _price)
{
	price = _price;
}
void drink::set_count(int _count)
{
	count = _count;
}
void drink::print()
{
	cout << name << "\t";
	cout << price << "¿ø\t";
	cout << count << "°³" << endl;
}