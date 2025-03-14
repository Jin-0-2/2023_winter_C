//84_2 STL_list (Member).cpp

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class Member
{
private:
    int number;
    string name;
public:
    Member(int _number, string _name) : number(_number), name(_name) {}

public:
    int getNumber() const { return number; }
    string getName() const { return name; }
    void setName(string value) { name = value; }

public:
    void Print() const
    {
        cout << number << ", " << name << endl;
    }
};

//[��ü���(��ȸ)]
void print_info_itr(list<Member>& vec)
{
    cout << "size: " << vec.size() << endl;
    list<Member>::iterator begin = vec.begin();
    list<Member>::iterator end = vec.end();
    for (; begin != end; begin++)
    {
        Member mem = *begin;
        mem.Print();
    }
    cout << "----------------------------------------------" << endl;
}

//push_back[����]
void exam1()
{
    list<Member> vec;
    print_info_itr(vec);

    Member mem(111, "ȫ�浿");
    vec.push_back(mem);

    vec.push_back(Member(222, "�̱浿"));
    print_info_itr(vec);
}

//erase[����](0)
void exam2()
{
    list<Member> vec;
    Member mem(111, "ȫ�浿");
    vec.push_back(mem);
    vec.push_back(Member(222, "�̱浿"));
    print_info_itr(vec);

    list<Member>::iterator itr = vec.begin();
    itr++;

    vec.erase(itr);  //������ �ּ�
    print_info_itr(vec);
}


//�˻�(�������)
list<Member>::iterator exam3_select(list<Member>& vec, int number)
{
    list<Member>::iterator begin = vec.begin();
    list<Member>::iterator end = vec.end();
    for (; begin != end; begin++)
    {
        Member mem = *begin;  
        if (mem.getNumber() == number)
            return begin;
    }
    return begin;
}

void exam3()
{
    list<Member> vec;
    Member mem(111, "ȫ�浿");
    vec.push_back(mem);
    vec.push_back(Member(222, "�̱浿"));
    print_info_itr(vec);

    list<Member>::iterator itr = exam3_select(vec, 222);
    if (itr == vec.end())
        cout << "����" << endl;
    else
    {
        Member mem = *itr;
        mem.Print();
    }
}

//�˻�(find_if() )
//�Լ� ��ü
class CompareNumber
{
    int number;
public:
    CompareNumber(int _num) : number(_num) {}
    bool operator()(Member& mem)                 //() ������ ������
    {
        if (mem.getNumber() == number)
            return true;
        else
            return false;
    }
};

class CompareName
{
    string name;
public:
    CompareName(string _name) : name(_name) {}
    bool operator()(Member& mem)                 //() ������ ������
    {
        if (mem.getName() == name)
            return true;
        else
            return false;
    }
};

void exam4()
{
    list<Member> vec;
    Member mem(111, "ȫ�浿");
    vec.push_back(mem);
    vec.push_back(Member(222, "�̱浿"));
    print_info_itr(vec);

    list<Member>::iterator itr = find_if(vec.begin(), vec.end(), CompareName("ȫ�浿"));
    if (itr == vec.end())
        cout << "����" << endl;
    else
    {
        Member mem = *itr;
        mem.Print();
    }
}

//����
void exam5()
{
    list<Member> vec;
    Member mem(111, "ȫ�浿");
    vec.push_back(mem);
    vec.push_back(Member(222, "�̱浿"));
    print_info_itr(vec);

    list<Member>::iterator itr = find_if(vec.begin(), vec.end(), CompareNumber(111));
    if (itr == vec.end())
        cout << "����" << endl;
    else
    {
        //���� ����
        itr->setName("��浿");
    }
    print_info_itr(vec);
}


//���ľ˰���
bool SortNumber(Member& s, Member& b)
{
    return s.getNumber() < b.getNumber();
}
bool SortName(Member& s, Member& b)
{
    return s.getName() < b.getName();
}

void exam6()
{
    list<Member> vec;
    Member mem(222, "ȫ�浿");
    vec.push_back(mem);
    vec.push_back(Member(111, "�̱浿"));
    print_info_itr(vec);

    vec.sort(SortName);

    print_info_itr(vec);
}

int main()
{
    exam6();

    return 0;
}