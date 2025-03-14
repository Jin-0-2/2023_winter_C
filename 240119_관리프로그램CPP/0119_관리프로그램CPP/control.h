// constrol.h
#pragma once

class control
{
private:
	wbarray array;		// 10개(기본값)짜리 배열 생성, wbarray *  array > 주소 전달로서 원하는 개수 생성

public:
	control();
	~control();

public:
	void printall();
	void insert();
	void select();
	void update();
	void remove();

private:
	int  name_to_idx(string title);			// 이름 > 배열
	drink* name_to_drink(string title);		// 이름 > 음료수 주소
};