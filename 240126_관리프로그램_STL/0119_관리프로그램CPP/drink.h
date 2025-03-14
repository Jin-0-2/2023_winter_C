// drink.h
#pragma once

// 음료수 번호를 1000번부터 자동증가(1000... 10단위로)
// 정적멤버변수
class drink
{
private:
	string title;
	int	 price;
	int  count;
	int number;

	static int s_number;	// 공유(정적멤버변수)

public:
	drink(string _title, int _price, int _count);
	~drink();

public:
	string get_title() const;
	int get_price() const;
	int get_count() const;
	int get_number() const;
	void set_price(int _price);

public:
	void print() const;
	void println() const;
	void add_count(int _count);

};