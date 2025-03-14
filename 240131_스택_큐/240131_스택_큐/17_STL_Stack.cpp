// 17_STL_Stack.cpp
// 13번 코드를 변경처리
#include <iostream>
#include <stack>		// STL stack
#include <conio.h>
using namespace std;

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
	stack<Member*> mems;  //객체 생성 has a
	
public:
	void printall1()
	{
		cout << mems.size() << " : " << endl;

		if (mems.size() > 0)
		{
			Member* pmem = mems.top();	// peek
			pmem->print();
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

			mems.push(pdata);

			cout << "저장성공" << endl;
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
			Member* peme = mems.top();
			mems.pop();

			delete peme;

			cout << "삭제성공" << endl;
		}
		catch (const char* msg)
		{
			cout << msg << endl;
		}
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
		cout << "[1]push [2]pop [5]exit" << endl;
		cout << "---------------------------------------" << endl;
		switch (_getch())	//#include <conio.h>
		{
		case '1': con.insert(); break;
		case '2': con.remove(); break;
		case '3': return 0;
		}
		system("pause");
	}

	return 0;
}