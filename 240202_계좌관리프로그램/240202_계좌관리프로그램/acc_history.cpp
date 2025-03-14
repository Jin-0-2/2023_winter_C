#include "std.h"
tran_history::tran_history(int _input_money, int _output_money, int _balance, tm _tran_time)
	: input_money(_input_money), output_money(_output_money), balance(_balance), tran_time(_tran_time)
{

}

tran_history::~tran_history()
{

}

int tran_history::get_input_money() const { return int_moeny; }
int tran_history::get_output_money() const { return output_moeny; }
int tran_history::get_balance() const { return balance; }
tm tran_history::get_tran_time() const { return tran_time; }

void tran_history::set_balance(int _balance)
{
	balance = _balance;
}