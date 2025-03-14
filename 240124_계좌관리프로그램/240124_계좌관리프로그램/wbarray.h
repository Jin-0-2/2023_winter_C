// wbarray.h
#pragma once

class wbarray
{
private:
	Account** accounts; // 동적배열을 이용 -> Account* 저장
	int size;			// 저장 개수 == 저장 위치 
	int max;			 // 저장할 최대 개수 

public:
	wbarray(int _max = 10);
	~wbarray();

public:
	int get_size() const;
	int get_max() const;

public:
	Account* get_account(int idx);		// 인덱스 전달 > 주소
	Account* operator[](int idx);
	bool pushback(Account* drink);		// 주소전달 > 저장 > return 성공실패
	bool erase(int idx);				// 인덱스 > 삭제 > return 성공실패
};