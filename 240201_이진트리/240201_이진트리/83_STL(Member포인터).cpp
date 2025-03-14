#include <iostream>
#include <vector>
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

//[전체출력(순회)]
void print_info(const vector<Member*>& vec)
{
    cout << "size: " << vec.size() << endl;
    for (int i = 0; i < (int)vec.size(); i++)
    {
        Member* pmem = vec[i];  //배열처럼 사용 가능
        pmem->Print();
    }
    cout << "----------------------------------------------" << endl;
}

void print_info_itr(vector<Member*>& vec)
{
    cout << "size: " << vec.size() << endl;
    vector<Member*>::iterator begin = vec.begin();
    vector<Member*>::iterator end = vec.end();
    for (; begin != end; begin++)
    {
        Member* pmem = *begin;
        pmem->Print();
    }
    cout << "----------------------------------------------" << endl;
}

//push_back[저장]
void exam1()
{
    vector<Member*> vec;
    print_info(vec);

    Member* pmem = new Member(111, "홍길동");
    vec.push_back(pmem);

    vec.push_back(new Member(222, "이길동"));
    print_info(vec);
}

//erase[삭제](0)
void exam2()
{
    vector<Member*> vec;
    print_info(vec);
    Member* pmem = new Member(111, "홍길동");
    vec.push_back(pmem);
    vec.push_back(new Member(222, "이길동"));
    print_info(vec);

    vec.erase(vec.begin() + 0);  //삭제할 주소
    print_info_itr(vec);
}

//검색(구현방식)
int exam3_select(const vector<Member*>& vec, int number)
{
    for (int i = 0; i < (int)vec.size(); i++)
    {
        Member* pmem = vec[i];  //배열처럼 사용 가능
        if (pmem->getNumber() == number)
            return i;
    }
    return -1;
}

void exam3()
{
    vector<Member*> vec;
    print_info(vec);
    Member* pmem = new Member(111, "홍길동");
    vec.push_back(pmem);
    vec.push_back(new Member(222, "이길동"));
    print_info(vec);

    int idx = exam3_select(vec, 222);
    if (idx == -1)
        cout << "없다" << endl;
    else
    {
        Member* pmem = vec[idx];
        pmem->Print();
    }
}

//검색(find_if() )
//함수 객체
class CompareNumber
{
    int number;
public:
    CompareNumber(int _num) : number(_num) {}
    bool operator()(Member* mem)                 //() 연산자 재정의
    {
        if (mem->getNumber() == number)
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
    bool operator()(Member* mem)                 //() 연산자 재정의
    {
        if (mem->getName() == name)
            return true;
        else
            return false;
    }
};

void exam4()
{
    vector<Member*> vec;
    print_info(vec);
    Member* pmem = new Member(111, "홍길동");
    vec.push_back(pmem);
    vec.push_back(new Member(222, "이길동"));
    print_info(vec);

    vector<Member*>::iterator itr = find_if(vec.begin(), vec.end(), CompareName("홍길동"));
    if (itr == vec.end())
        cout << "없다" << endl;
    else
    {
        Member* mem = *itr;
        mem->Print();
    }
}

//수정
void exam5()
{
    vector<Member*> vec;
    print_info(vec);
    Member* pmem = new Member(111, "홍길동");
    vec.push_back(pmem);
    vec.push_back(new Member(222, "이길동"));
    print_info(vec);

    vector<Member*>::iterator itr = find_if(vec.begin(), vec.end(), CompareNumber(111));
    if (itr == vec.end())
        cout << "없다" << endl;
    else
    {
        Member* pmem = *itr;
        pmem->setName("고길동");
    }
    print_info_itr(vec);
}


//정렬알고리즘
bool SortNumber(Member* s, Member* b)
{
    return s->getNumber() < b->getNumber();
}
bool SortName(Member* s, Member* b)
{
    return s->getName() < b->getName();
}
void exam6()
{
    vector<Member*> vec;
    print_info(vec);
    Member* pmem = new Member(111, "홍길동");
    vec.push_back(pmem);
    vec.push_back(new Member(222, "이길동"));
    print_info(vec);

    sort(vec.begin(), vec.end(), SortName);

    print_info(vec);
}

int main()
{
    exam6();

    return 0;
}