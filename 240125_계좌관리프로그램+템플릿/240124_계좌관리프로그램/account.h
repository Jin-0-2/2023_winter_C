// account.h
#pragma once
/*
일반계좌(계좌번호, 고객명, 잔액)
		입금 : 입금액을 잔액에 합산
		출금 : 출금액을 잔액에서 감액
		출력 : 3개의 정보 출력
*/

class Account
{
private:
	int number;
	string name;
	int balance;
public:
	Account(int _number, string _name)
		:number(_number), name(_name), balance(0)
	{
	}
	Account(int _number, string _name, int _balance)
		:number(_number), name(_name), balance(_balance)
	{
	}
public:
	int get_number() const { return number; }
	string get_name() const { return name; }
	int get_balance() const { return balance; }

public:
	virtual bool input_money(int money)
	{
		if (money <= 0)
		{
			cout << "잘못된 금액이 전달됨" << endl;
			return false;
		}
		balance = balance + money;
		return true;
	}

	bool output_money(int money)
	{
		if (money < 0)
		{
			cout << "잘못된 금액이 전달됨" << endl;
			return false;

		}

		if (balance < money)
		{
			cout << "잔액 부족" << endl;
			return false;
		}

		balance = balance - money;
		return true;
	}

	virtual void print() const
	{
		cout << number << "\t";
		cout << name << "\t";
		cout << balance << "원\t";
	}
};