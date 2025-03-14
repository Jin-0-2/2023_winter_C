#pragma once
class wbarray
{
private:
	drink* *drinks; // 동적배열을 이용 -> drink* 저장
	int size;		  // 저장 개수 == 저장 위치 
	int max;		  // 저장할 최대 개수 

public:
	wbarray(int _max = 10);
	~wbarray();

public:
	int get_size() const;
	int get_max() const;

public:
	drink* get_drink(int idx);		// 인덱스 전달 > 주소
	bool pushback(drink* drink);		// 주소전달 > 저장 > return 성공실패
	bool erase(int idx);				// 인덱스 > 삭제 > return 성공실패
};