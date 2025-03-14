// wbarray.cpp
#include "std.h"
// wbarray.cpp
#include "std.h"

wbarray::wbarray(int _max /*= 10*/) 
	: size(0), max(_max)
{
	accounts = new Account * [_max];
}

wbarray::~wbarray()
{
	delete[] accounts;
	accounts = NULL;
}

int wbarray::get_size() const
{
	return size;
}

int wbarray::get_max() const
{
	return max;
}

Account* wbarray::get_account(int idx)
{
	if (idx < 0 || idx >= size)
		return NULL;

	return accounts[idx];
}

Account* wbarray::operator[](int idx)
{
	if (idx < 0 || idx >= size)
		return NULL;

	return accounts[idx];
}

bool wbarray::pushback(Account* account)
{
	if (max <= size)
	{
		cout << "Overflow" << endl;
		return false;
	}

	accounts[size] = account;
	size++;
	return true;

}

bool wbarray::erase(int idx)
{
	if (idx < 0 || idx >= size)
		return NULL;

	for (int i = idx; i <= size - 1; i++)
	{
		accounts[i] = accounts[i + 1];
	}
	size--;
	return true;
}