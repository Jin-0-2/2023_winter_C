// wbfile.cpp
#include "std.h"

string wbfile::file_name = "account.txt";

void wbfile::save(wbarray<Account *> *parr)
{
    ofstream out(file_name);        // 파일 열기

    int max = parr->get_max();
    int size = parr->get_size();

    out << max << endl;             // 파일 출력 객체
    out << size << endl;

    // 다운캐스팅
    for (int i = 0; i < size; i++)
    {
        Account* pacc = parr->get_data(i);
        // 어떤종류의 계좌인지 추가 저장!(1,2,3)
        out << pacc->get_number() << "\t";
        out << pacc->get_name() << "\t";
        out << pacc->get_balance() << endl;
    }
}                                   // 파일 닫기(소멸자 자동)

int wbfile::load(wbarray<Account*>* parr)
{
    ifstream in(file_name);         // 파일 읽기

    int max, size;
    in >> max;
    in >> size;

    for (int i = 0; i < size; i++)
    {
        int number;
        string name;
        int balance;

        // 계좌의 종류 읽는다.
        in >> number;
        in >> name;
        in >> balance;

        Account* pacc = new Account(number, name, balance);

        parr->pushback(pacc);
    }
    return 1;
}