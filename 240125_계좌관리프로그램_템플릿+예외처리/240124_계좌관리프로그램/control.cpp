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
				Account* acc = accounts[i];		// ������ �������� ȿ��
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
	printf("[���� ����]\n");
	try
	{
		int num = wblib::input_integer("���¹�ȣ");
		string name = wblib::input_string("��   ��");
		int money = wblib::input_integer("�Աݾ�");
		int type = wblib::input_integer("[1]�Ϲ� [2]��� [3]�ſ�");


		Account* acc = NULL;
		switch (type)
		{
		case 1: acc = new Account(num, name, money);	break;
		case 2: acc = new ContriAccount(num, name, money);	break;
		case 3: acc = new FaithAccount(num, name, money);	break;
			accounts.pushback(acc);
			cout << "����Ǿ����ϴ�." << endl;
		}
	}
	catch (const char* msg)
	{
		cout << "���� ���� : " << msg << endl;
	}
}

void control::select()
{
	cout << "[���� �˻�]" << endl;

	try
	{
		int number = wblib::input_integer("���¹�ȣ");
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
	printf("[�Աݱ��(����)]\n");

	try
	{
		int number = wblib::input_integer("���¹�ȣ");
		int money  = wblib::input_integer("�Աݾ�");

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
	printf("[��ݱ��(����)]\n");

	try
	{
		int number = wblib::input_integer("���¹�ȣ");
		int money = wblib::input_integer("��ݾ�");

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
	printf("[�������� ����]\n");

	try
	{
		int number = wblib::input_integer("���¹�ȣ");
		int idx = number_to_idx(number);
		accounts.erase(idx);
		printf("�����Ǿ����ϴ�.\n");
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
	throw "����.";
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
	throw "����."; // return NULL;
}