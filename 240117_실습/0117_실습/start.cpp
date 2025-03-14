// start.cpp
#include <iostream>
using namespace std;;
#include <conio.h>		// _getch();

#include "start.h"
#include "drink.h"
#include "drink_machine.h"

drink_machine ma;

void my_input_money()
{
	int money;
	cout << "금액입력 : ";	cin >> money;
	
	ma.input_money(money);
}

void my_selet_drink()
{
	int select;
	cout << "음료수 선택 : ";	 cin >> select;

	drink* pdrink = ma.select_drink(select);
	if (pdrink == NULL)
		cout << "오류" << endl;
	else
	{
		cout << pdrink->get_name() << "음료수 획득" << endl;
	}
}

void my_output_money()
{
	int money = ma.output_money();
	cout << "반환된 금액 : " << money << "원" << endl;
}

void run()
{
	while (true)
	{
		system("cls");
		ma.print();
		cout << "---------------------------------------------" << endl;
		cout << "[1]금액투입 [2]음료수선택 [3]금액반환 [4]종료" << endl;
		cout << "---------------------------------------------" << endl;
		char sel = _getch();
		switch (sel)
		{
		case '1': my_input_money(); break;
		case '2': my_selet_drink(); break;
		case '3': my_output_money(); break;
		case '4': return;
		}
		system("pause");
	}
}

int main()
{
	run();

	return 0;
}