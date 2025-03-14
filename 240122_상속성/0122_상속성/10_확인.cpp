// 10_확인.cpp
/*
일반계좌(계좌번호, 고객명, 잔액)
		 입금 : 입금액을 잔액에 합산
		 출금 : 출금액을 잔액에서 감액
		 출력 : 3개의 정보 출력
기부계좌(계좌번호, 고객명, 잔액, 기부금총액)
		 입금 : 입금액의 1%를 기부금총액게 합산
				입금액 중 1%를 제외한 금액을 잔액에 합산
		 출금 : 출금액을 잔액에서 감액
		 출력 : 4개의 정보를 출력
--------------------------------------------------------
[공통] 
방법1) 새로운 부모를 하나 만들어 일반계좌, 기부계좌를 자식으로 구성
방법2) 둘 중 하나를 부모로 구성  --> 
*/
#include <iostream>
using namespace std;

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

class ContriAccount : public Account
{
private:
	int contribution;
public:
	ContriAccount(int _number, string _name) : Account(_number, _name), contribution(0)
	{

	}

	ContriAccount(int _number, string _name, int _balance) : Account(_number, _name, (int)_balance*0.99), contribution((int)_balance * 0.01)
	{

	}

public:
	int get_contribution() const { return contribution; }

public:
	bool input_money(int money)
	{
		int temp = (int)(money * 0.99);

		if (Account::input_money(temp) == false)
			return false;

		contribution = contribution + (int)(money * 0.01);

		return true;
	}

	void print() const
	{
		Account::print();
		cout << contribution << "원\n";
	}

};

int main()
{
	Account* account[2];

	account[0] = new Account(11111, "홍일반", 1000);
	account[1] = new ContriAccount(2222, "홍기부", 1000);

	for (int i = 0; i < 2; i++)
	{
		// 다형성
		account[i]->print();		cout << endl;
	}

	for (int i = 0; i < 2; i++)
	{
		// 다형성
		account[i]->input_money(5000);		cout << endl;
	}

	for (int i = 0; i < 2; i++)
	{
		// 다형성
		account[i]->print();		cout << endl;
	}
	return 0;
}