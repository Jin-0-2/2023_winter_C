// constrol.h
#pragma once

// 계좌들을 관리
class control
{
private:
	wbarray array;

public:
	control();
	~control();

public:
	void printall();
	void insert();
	void select();
	void update1();
	void update2();
	void remove();

private:
	int  number_to_idx(int number);			// 이름 > 배열
	Account* number_to_account(int number);		// 이름 > 계좌 주소
};