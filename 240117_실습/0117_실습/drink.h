// drink.h
#pragma once

class drink
{
private:
	string name;
	int price;
	int count;

public:
	drink(string _name, int _price, int _count);
	drink(string _name, int _price);

public:
	string get_name();
	int get_price();
	int get_count();

	void set_price(int _price);
	void set_count(int _count);

public:
	void print();
};