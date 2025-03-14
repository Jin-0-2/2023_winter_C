#include "std.h"

Account::Account(int _acc_number, string _id, int _balance, string _make_acc_time, string _using_acc)
	: acc_number(_acc_number), id(_id), balance(_balance), make_acc_time(_make_acc_time), using_acc(_using_acc)
{
}

Account::~Account() {}

int Account::get_acc_number() { return acc_number; }
string Account::get_id() { return id; }
int Account::get_balance() { return balance; }
string Account::get_make_acc_time() { return make_acc_time; }
string Account::get_using_acc() { return using_acc; }

void Account::print() const
{
	cout << acc_number << "\t";
	cout << id << "\t";
	cout << balance << "\t";
	cout << make_acc_time << "\t";
	cout << using_acc << endl;
}
void Account::println() const
{
	cout << "계좌  번호 : " << acc_number << endl;
	cout << "회원아이디 :" << id << endl;
	cout << "잔      액 : " << balance << endl;
	cout << "개설  일시 : " << make_acc_time << endl;
	cout << "거래 내역  : " << using_acc << endl;
}