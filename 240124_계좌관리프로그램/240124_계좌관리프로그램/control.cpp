// control.cpp
#include "std.h"
control::control()
{
	wbfile::load(&array);
}

control::~control()
{
	wbfile::save(&array);
}

void control::printall()
{
	printf("[max : %d] \t [size : %d]\n", array.get_max(), array.get_size());
	for (int i = 0; i < array.get_size(); i++)
	{
		// Account* acc = array.get_account(i);
		Account* acc = array[i];		// 연산자 재정의의 효과
		printf("[%2d] ", i);
		acc->print();
		cout << endl;
	}
	printf("\n");
}

void control::insert()
{
	printf("[계좌 저장]\n");

	int num     = wblib::input_integer("계좌번호");
	string name = wblib::input_string("이   름");
	int money   = wblib::input_integer("입금액");
	int type    = wblib::input_integer("[1]일반 [2]기부 [3]신용");


	Account* acc = NULL;
	switch (type)
	{
	case 1: acc = new Account(num, name, money);	break;
	case 2: acc = new ContriAccount(num, name, money);	break;
	case 3: acc = new FaithAccount(num, name, money);	break;
	}

	if (array.pushback(acc) == true)
		printf("저장되었습니다\n");
	else
		printf("저장 실패\n");
}

void control::select()
{
	cout << "[계좌 검색]" << endl;

	int number = wblib::input_integer("계좌번호");

	Account* pacc = number_to_account(number);

	if (pacc != NULL)
	{
		pacc->print();
		cout << endl;
	}
	else
		printf("없는 제품 입니다\n");
}

void control::update1()
{
	printf("[입금기능(변경)]\n");

	int number = wblib::input_integer("계좌번호");
	int money  = wblib::input_integer("입금액");

	Account* pacc = number_to_account(number);
	if (pacc != NULL)
	{
		if (pacc->input_money(money) == true)
			cout << "입금성공" << endl;
		else
			cout << "입금실패" << endl;
	}
	else
		printf("없는 계좌 입니다\n");
}

void control::update2()
{
	printf("[출금기능(변경)]\n");

	int number = wblib::input_integer("계좌번호");
	int money = wblib::input_integer("출금액");

	Account* pacc = number_to_account(number);
	if (pacc != NULL)
	{
		if (pacc->output_money(money) == true)
			cout << "출금성공" << endl;
		else
			cout << "출금실패" << endl;
	}
	else
		printf("없는 계좌 입니다\n");
}

void control::remove()
{
	printf("[계좌정보 삭제]\n");

	int number = wblib::input_integer("계좌번호");

	int idx = number_to_idx(number);
	if (idx != -1)
	{
		array.erase(idx);
		printf("삭제되었습니다\n");
	}
	else
		printf("없는 제품 입니다\n");

}

int  control::number_to_idx(int number)
{
	for (int i = 0; i < array.get_size(); i++)
	{
		Account*  acc = array[i];
		if (acc->get_number() == number)
		{
			return i;
		}
	}
	return -1;
}

Account* control::number_to_account(int number)
{
	for (int i = 0; i < array.get_size(); i++)
	{
		Account* acc = array[i];
		if (acc->get_number() == number)
		{
			return acc;
		}
	}
	return NULL;
}