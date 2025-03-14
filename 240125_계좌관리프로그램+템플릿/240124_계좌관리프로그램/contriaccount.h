// contriaccount.h
#pragma once
/*
* 기부계좌(계좌번호,고객명,잔액, *기부금총액)
         *입금 : 입금액의 1%를 기부금총액에 합산
                입금액 중 1%를 제외한 금액을 잔액에 합산
         출금 : 출금액을 잔액에서 감액
         *출력 : 4개의 정보 출력

*/
class ContriAccount : public Account
{
private:
	int contribution;
public:
	ContriAccount(int _number, string _name) : Account(_number, _name), contribution(0)
	{
	}

	ContriAccount(int _number, string _name, int _balance) : Account(_number, _name, (int)(_balance * 0.99)), contribution((int)(_balance * 0.01))
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