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
	cout << "회원수 : " << members.size() << "명" << endl;

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
	printf("[회원 저장]\n");

	string id = wblib::input_string("아이디");
	string pw = wblib::input_string("비밀번호");
	string name = wblib::input_string("이름");
	string phone = wblib::input_string("전화번호");

	Member* pmem = new Member(id, pw, name, phone);
	members.push_back(pmem);
	printf("저장되었습니다\n");
}

void mem_control::select()
{
	cout << "[회원 검색]" << endl;

	string title = wblib::input_string("아이디");

	Member* pmem = findMembers(title);

	if (pmem != NULL)
		pmem->println();
	else
		printf("없는 제품 입니다\n");
}

void mem_control::update()
{
	printf("[전화번호 변경]\n");

	string id   = wblib::input_string("아 이 디 : ");
	string phone = wblib::input_string("전화번호 :");

	Member* pmem = findMembers(id);
	if (pmem != NULL)
	{
		pmem->set_phone(phone);
		printf("변경되었습니다\n");
	}
	else
		printf("없는 제품 입니다\n");
}

void mem_control::remove()
{
	printf("[회원정보 삭제]\n");

	string id = wblib::input_string("아 이 디 : ");

	int idx = find_idx(id);
	if (idx != -1)
	{
		members.erase(members.begin() + idx);
		printf("삭제되었습니다\n");
	}
	else
		printf("없는 제품 입니다\n");

}

void mem_control::id_check(string id)
{
	for (int i = 0; i < members.size(); i++)
	{
		Member* mem = members[i];
		if (mem->get_id() == id)
			throw "중복 아이디입니다.";
	}
}

Member* mem_control::findMembers(string id)
{
	Find_MemberID fmi(id);
	vector<Member*>::iterator itr = find_if(members.begin(), members.end(), fmi);
	if (itr != members.end())
		return *itr;
	else
		throw "회원의 아이디가 존재하지 않습니다.";
}

int mem_control::find_idx(string id)
{
	for (int i = 0; i < members.size(); i++)
	{
		Member* pmember = members[i];
		if (pmember->get_id() == id)
			return i;
	}
	throw "회원의 아이디가 존재하지 않습니다.";
}
