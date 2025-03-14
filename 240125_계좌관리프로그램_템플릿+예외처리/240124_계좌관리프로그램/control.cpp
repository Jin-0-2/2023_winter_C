// control.cpp
#include "std.h"
control::control()
{
	wbfile::load(&accounts);
}

control::~control()
{
	wbfile::save(&accounts);
}

void control::printall()
{
	try
	{
		printf("[max : %d] \t [size : %d]\n", accounts.get_max(), accounts.get_size());
		for (int i = 0; i < accounts.get_size(); i++)
			{
				// Account* acc = array.get_account(i);
				Account* acc = accounts[i];		// 연산자 재정의의 효과
				printf("[%2d] ", i);
				acc->print();
				cout << endl;
			}
			printf("\n");
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
}

void control::insert()
{
	printf("[계좌 저장]\n");
	try
	{
		int num = wblib::input_integer("계좌번호");
		string name = wblib::input_string("이   름");
		int money = wblib::input_integer("입금액");
		int type = wblib::input_integer("[1]일반 [2]기부 [3]신용");


		Account* acc = NULL;
		switch (type)
		{
		case 1: acc = new Account(num, name, money);	break;
		case 2: acc = new ContriAccount(num, name, money);	break;
		case 3: acc = new FaithAccount(num, name, money);	break;
			accounts.pushback(acc);
			cout << "저장되었습니다." << endl;
		}
	}
	catch (const char* msg)
	{
		cout << "저장 실패 : " << msg << endl;
	}
}

void control::select()
{
	cout << "[계좌 검색]" << endl;

	try
	{
		int number = wblib::input_integer("계좌번호");
		Account* pacc = number_to_account(number);
		pacc->print();
		cout << endl;
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
}

void control::update1()
{
	printf("[입금기능(변경)]\n");

	try
	{
		int number = wblib::input_integer("계좌번호");
		int money  = wblib::input_integer("입금액");

		Account* pacc = number_to_account(number);
		pacc->input_money(money);
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}

	
}

void control::update2()
{
	printf("[출금기능(변경)]\n");

	try
	{
		int number = wblib::input_integer("계좌번호");
		int money = wblib::input_integer("출금액");

		Account* pacc = number_to_account(number);
		pacc->output_money(money);
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}

	
}

void control::remove()
{
	printf("[계좌정보 삭제]\n");

	try
	{
		int number = wblib::input_integer("계좌번호");
		int idx = number_to_idx(number);
		accounts.erase(idx);
		printf("삭제되었습니다.\n");
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
}

int  control::number_to_idx(int number)
{
	for (int i = 0; i < accounts.get_size(); i++)
	{
		Account*  acc = accounts[i];
		if (acc->get_number() == number)
		{
			return i;
		}
	}
	throw "없다.";
}

Account* control::number_to_account(int number)
{
	for (int i = 0; i < accounts.get_size(); i++)
	{
		Account* acc = accounts[i];
		if (acc->get_number() == number)
		{
			return acc;
		}
	}
	throw "없다."; // return NULL;
}