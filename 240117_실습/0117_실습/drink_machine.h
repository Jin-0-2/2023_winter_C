// drink_machine.h
#pragma once
class drink_machine
{
private:
	drink* drinks[5];		// 음료수들
	int count;				// 음료수 개수
	int money;				// 투입된 금액

public:
	drink_machine();

public:
	int get_count();
	int get_money();
	
public:
	drink* get_drink(int idx);
	void print();						// 자판기 화면 출력
	void input_money(int _money);		// 자판기에 금액 투입
	drink* select_drink(int idx);		// 음료수 선택 -> 선택된 음료수 반환
	int output_money();					// 잔액회수 -> 잔액반환
};