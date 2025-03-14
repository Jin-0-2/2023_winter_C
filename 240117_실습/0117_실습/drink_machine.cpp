// drink_machine.cpp
#include <iostream>
using namespace std;

#include "drink.h"
#include "drink_machine.h"

drink_machine::drink_machine()
{
	drinks[0] = new drink("콜  라", 1000, 2);
	drinks[1] = new drink("사이다", 1200, 4);
	drinks[2] = new drink("환  타", 800, 5);
	drinks[3] = new drink("커  피", 500, 3);
	drinks[4] = new drink("생  수", 400, 6);

	count = 5;
	money = 0;
}

int drink_machine::get_count()
{
	return count;
}

int drink_machine::get_money()
{
	return money;
}

drink* drink_machine::get_drink(int idx)
{
	if (idx < 0 || idx >= count)
	{
		return NULL;
	}
	return drinks[idx];
}

void drink_machine::print()
{
	cout << "-----------------------------" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << "[" << i << "]";
		drink* pdrink = drinks[i];
		pdrink->print();
	}
	cout << "-----------------------------" << endl;
	cout << "투입된 금액 : " << money << "원" << endl;
	cout << "-----------------------------" << endl;
}

// 자판기에 금액 투입
void drink_machine::input_money(int _money)
{
	money = money + _money;
}

// 음료수 선택 -> 선택된 음료수 반환
drink* drink_machine::select_drink(int idx)
{
	drink* pdrink = get_drink(idx);
	if (pdrink == NULL)
		return NULL;

	if (money < pdrink->get_price())
	{
		cout << "잔액이 부족" << endl;
		return NULL;
	}

	money = money - pdrink->get_price();
	return pdrink;
}

// 잔액 회수 -> 잔액 반환
int drink_machine::output_money()
{
	int temp = money;
	money = 0;

	return temp;
}