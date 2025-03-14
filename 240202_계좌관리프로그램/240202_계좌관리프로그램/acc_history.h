#pragma once
class tran_history
{
private:
	int input_money;
	int output_money;
	int balance;
	tm tran_time;

public:
	tran_history(int _input_money, int _output_money, int _balance, tm _tran_time);
	~tran_history();

public:
	int get_input_money() const;
	int get_output_money() const;
	int get_balance() const;
	tm get_tran_time() const;

	void set_balance(int _balance);
};