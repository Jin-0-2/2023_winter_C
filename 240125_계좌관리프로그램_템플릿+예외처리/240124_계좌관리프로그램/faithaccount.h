// faithaccount.h
#pragma once
/*
신용계좌(계좌번호, 고객명, 잔액)
			*입금: 입금액에 1%의 이자를 붙여서 입금
			출금 : 출금액을 잔액에서감액
			출력 : 3개의 정보 출력
*/
class FaithAccount : public Account
{
public:
	FaithAccount(int _number, string _name)
		:Account(_number, _name)
	{

	}
	FaithAccount(int _number, string _name, int _balance)
		: Account(_number, _name, _balance)
	{

	}

public:
	void input_money(int money)
	{
		int temp = money + (int)(money * 0.01);
		Account::input_money(temp);
	}
};