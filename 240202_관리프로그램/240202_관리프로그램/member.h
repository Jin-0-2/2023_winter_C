#pragma once

class Member
{
private:
	string id;
	string pw;
	string name;
	string phone;
	tm jointime;

public:
	Member(string _id, string _pw, string _name, string _phone);
	Member(string _id, string _pw, string _name, string _phone, tm _jointime);
	~Member();

public:
	string get_id() const;
	string get_pw() const;
	string get_name() const;
	string get_phone() const;
	tm get_jointime() const;

	void set_pw(string _pw);
	void set_name(string _name);
	void set_phone(string _phone);

public:
	void print() const;
	void println() const;
};

class Find_MemberID
{
	string id;
public:
	Find_MemberID(string _id) : id(_id) {}
public:
	bool operator()(Member* pmember)
	{
		if (pmember->get_id() == id)
			return true;
		else
			return false;
	}
};
