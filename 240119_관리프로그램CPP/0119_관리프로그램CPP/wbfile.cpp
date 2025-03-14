// wbfile.cpp
#include "std.h"

string wbfile::file_name = "drinks.txt";

void wbfile::save(wbarray* parr)
{
    ofstream out(file_name);        // 파일 열기

    int max = parr->get_max();
    int size = parr->get_size();
   
    out << max << endl;             // 파일 출력 객체
    out << size << endl;

    for (int i = 0; i < size; i++)
    {
        drink* temp = parr->get_drink(i);
        out << temp->get_title() << "\t";
        out << temp->get_price() << "\t";
        out << temp->get_count() << endl;
    }                               
}                                   // 파일 닫기(소멸자 자동)

int wbfile::load(wbarray* parr)
{
    ifstream in(file_name);         // 파일 읽기
  
    int max, size;
    in >> max;
    in >> size;

    for (int i = 0; i < size; i++)
    {
        string title;
        int price;
        int count;

        in >> title;
        in >> price;
        in >> count;

        drink* pdrink = new drink(title, price, count);

        parr->pushback(pdrink);
    }
    return 1;
}