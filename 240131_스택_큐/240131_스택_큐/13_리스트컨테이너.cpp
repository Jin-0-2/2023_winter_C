//13_리스트컨테이너.cpp
/*
 STL : vector : 배열(스스로 공간을 늘려나감)
	   list   : 이중연결리스트
*/
//데이터 : Member
//저장   : list<> : STL
//관리   : Control 
#include <iostream>
#include <list>
using namespace std;
#include <conio.h>

class Member
{
private:
	string name;
	string phone;

public:
	Member(string _name, string _phone)
		: name(_name), phone(_phone)
	{
	}
public:
	string get_name() const { return name; }
	string get_phone() const { return phone; }
	void set_phone(string _phone) { phone = _phone; }

public:
	void print() const
	{
		cout << name << " : " << phone << endl;
	}

	void println() const
	{
		cout << "이    름 : " << name << endl;
		cout << "전화번호 : " << phone << endl;
	}
};

class Control
{
private:
	list<Member*> mems;  //객체 생성 has a

public:
	void printall1()
	{
		cout << mems.size() << " : " << endl;

		list<Member*>::iterator b = mems.begin();
		list<Member*>::iterator e = mems.end();

		for (; b != e; b++)
		{
			Member* data = *b;
			data->print();
		}
	}

	void insert()
	{
		try
		{
			string name, phone;
			cout << "이    름 : ";		cin >> name;
			cout << "전화번호 : ";		cin >> phone;

			Member* pdata = new Member(name, phone);

			mems.push_back(pdata); // push_front 지원된다.

			cout << "저장성공" << endl;
		}
		catch (const char* msg)
		{
			cout << msg << endl;
		}
	}

	void select()
	{
		try
		{
			string name;
			cout << "검색할 이름 입력 : ";		cin >> name;

			list<Member*>::iterator cur = value_to_Node(name);

			Member* pmem = *cur;
			pmem->println();
		}
		catch (const char* msg)
		{
			cout << msg << endl;
		}
	}

	void update()
	{
		try
		{
			string name, phone;
			cout << "검색할 이름 : ";		cin >> name;
			cout << "수정할 전화번호 : ";	cin >> phone;

			list<Member*>::iterator cur = value_to_Node(name);

			Member* pdata = *cur;
			pdata->set_phone(phone);

			cout << "수정성공" << endl;
		}
		catch (const char* msg)
		{
			cout << msg << endl;
		}
	}

	void remove()
	{
		try
		{
			string name;
			cout << "삭제할 이름 : ";		cin >> name;

			list<Member*>::iterator cur = value_to_Node(name);
			Member* pmem = *cur;
			mems.erase(cur);

			delete pmem;	//*********************

			cout << "삭제성공" << endl;
		}
		catch (const char* msg)
		{
			cout << msg << endl;
		}
	}

private:
	list<Member*>::iterator value_to_Node(string value)
	{
		list<Member*>::iterator b = mems.begin();
		list<Member*>::iterator e = mems.end();

		for (; b != e; b++)
		{
			Member* data = *b;
			if (data->get_name() == value)
				return b;
		}
		throw "없다";
	}
};

int main()
{
	Control con;

	while (true)
	{
		system("cls");
		con.printall1();
		cout << "---------------------------------------" << endl;
		cout << "[1]insert [2]select [3]update [4]delete  [5]exit" << endl;
		cout << "---------------------------------------" << endl;
		switch (_getch())	//#include <conio.h>
		{
		case '1': con.insert(); break;
		case '2': con.select(); break;
		case '3': con.update(); break;
		case '4': con.remove(); break;
		case '5': return 0;
		}
		system("pause");
	}

	return 0;
}
