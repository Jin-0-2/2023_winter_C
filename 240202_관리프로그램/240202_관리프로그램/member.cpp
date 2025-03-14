#include "std.h"
Member::Member(string _id, string _pw, string _name, string _phone)
	:id(_id), pw(_pw), name(_name), phone(_phone)
{
	jointime = wblib::get_cur_time();
}

Member::Member(string _id, string _pw, string _name, string _phone, tm _jointime)
	:id(_id), pw(_pw), name(_name), phone(_phone), jointime(_jointime)
{

}

Member::~Member()
{
}

string Member::get_id() const { return id; }
string Member::get_pw() const { return pw; }
string Member::get_name() const { return name; }
string Member::get_phone() const { return phone; }
tm Member::get_jointime() const { return jointime; }
void Member::set_pw(string _pw)
{
	pw = _pw;
}
void Member::set_name(string _name)
{
	name = _name;
}
void Member::set_phone(string _phone)
{
	phone = _phone;
}

void Member::print() const
{
	cout << id << " : " << pw << " : " << name << " : " << phone << " : " << wblib::full_stringtime(jointime) << endl;
}

void Member::println() const
{
	cout << "�� �� �� : " << id << endl;
	cout << "��й�ȣ : " << pw << endl;
	cout << "��    �� : " << name << endl;
	cout << "��ȭ��ȣ : " << phone <<  endl;
	cout << "�������� : " << wblib::date_stringtime(jointime) << endl;
	cout << "���Խð� : " << wblib::time_stringtime(jointime) << endl;
}
