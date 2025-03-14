#pragma once
class Account
{
private:
	int acc_number;
	string id;
	int balance;


public:
	Account(int _acc_number, string _id, int _balance, string _make_acc_time, string _using_acc);
	~Account();

public:
	int get_acc_number();
	string get_id();
	int get_balance();
	string get_make_acc_time();
	string get_using_acc();

public:
	void print() const;
	void println() const;
};