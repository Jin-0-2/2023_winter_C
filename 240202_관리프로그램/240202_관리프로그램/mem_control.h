#pragma once
class mem_control
{
private:
	vector<Member*> members;		// 10개(기본값)짜리 배열 생성, wbarray *  array > 주소 전달로서 원하는 개수 생성

public:
	mem_control();
	~mem_control();

public:
	void printall();
	void insert();
	void select();
	void update();
	void remove();

private:
	void id_check(string id);
	Member* findMembers(string id);
	int find_idx(string id);
};