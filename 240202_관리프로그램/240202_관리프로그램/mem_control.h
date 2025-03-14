#pragma once
class mem_control
{
private:
	vector<Member*> members;		// 10��(�⺻��)¥�� �迭 ����, wbarray *  array > �ּ� ���޷μ� ���ϴ� ���� ����

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