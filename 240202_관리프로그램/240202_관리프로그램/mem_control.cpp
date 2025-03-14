#include "std.h"
mem_control::mem_control()
{
	wbfile::load(&members);
}

mem_control::~mem_control()
{
	wbfile::save(members);
}

void mem_control::printall()
{
	cout << "ȸ���� : " << members.size() << "��" << endl;

	for (int i = 0; i < members.size(); i++)
	{
		Member* member = members[i];
		printf("[%2d] ", i);
		member->print();
	}
	printf("\n");
}

void mem_control::insert()
{
	printf("[ȸ�� ����]\n");

	string id = wblib::input_string("���̵�");
	string pw = wblib::input_string("��й�ȣ");
	string name = wblib::input_string("�̸�");
	string phone = wblib::input_string("��ȭ��ȣ");

	Member* pmem = new Member(id, pw, name, phone);
	members.push_back(pmem);
	printf("����Ǿ����ϴ�\n");
}

void mem_control::select()
{
	cout << "[ȸ�� �˻�]" << endl;

	string title = wblib::input_string("���̵�");

	Member* pmem = findMembers(title);

	if (pmem != NULL)
		pmem->println();
	else
		printf("���� ��ǰ �Դϴ�\n");
}

void mem_control::update()
{
	printf("[��ȭ��ȣ ����]\n");

	string id   = wblib::input_string("�� �� �� : ");
	string phone = wblib::input_string("��ȭ��ȣ :");

	Member* pmem = findMembers(id);
	if (pmem != NULL)
	{
		pmem->set_phone(phone);
		printf("����Ǿ����ϴ�\n");
	}
	else
		printf("���� ��ǰ �Դϴ�\n");
}

void mem_control::remove()
{
	printf("[ȸ������ ����]\n");

	string id = wblib::input_string("�� �� �� : ");

	int idx = find_idx(id);
	if (idx != -1)
	{
		members.erase(members.begin() + idx);
		printf("�����Ǿ����ϴ�\n");
	}
	else
		printf("���� ��ǰ �Դϴ�\n");

}

void mem_control::id_check(string id)
{
	for (int i = 0; i < members.size(); i++)
	{
		Member* mem = members[i];
		if (mem->get_id() == id)
			throw "�ߺ� ���̵��Դϴ�.";
	}
}

Member* mem_control::findMembers(string id)
{
	Find_MemberID fmi(id);
	vector<Member*>::iterator itr = find_if(members.begin(), members.end(), fmi);
	if (itr != members.end())
		return *itr;
	else
		throw "ȸ���� ���̵� �������� �ʽ��ϴ�.";
}

int mem_control::find_idx(string id)
{
	for (int i = 0; i < members.size(); i++)
	{
		Member* pmember = members[i];
		if (pmember->get_id() == id)
			return i;
	}
	throw "ȸ���� ���̵� �������� �ʽ��ϴ�.";
}
