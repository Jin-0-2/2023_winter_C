// wbarray.cpp
#include "std.h"

wbarray::wbarray(int _max /*= 10*/) : size(0), max(_max)
{
	drinks = new drink*[_max];
}

wbarray::~wbarray()
{
	delete[] drinks;
	drinks = NULL;
}

int wbarray::get_size() const
{
	return size;
}

int wbarray::get_max() const
{
	return max;
}

drink* wbarray::get_drink(int idx)
{
	if (idx < 0 || idx >= size)
		return NULL;

	return drinks[idx];
}

bool wbarray::pushback(drink* drink)
{
	if (max <= size)
	{
		cout << "Overflow" << endl;
		return false;
	}

	drinks[size] = drink;
	size++;
	return true;

}

bool wbarray::erase(int idx)
{
	if (idx < 0 || idx >= size)
		return NULL;

	for (int i = idx; i <= size - 1; i++)
	{
		drinks[i] = drinks[i + 1];
	}
	size--;
	return true;
}