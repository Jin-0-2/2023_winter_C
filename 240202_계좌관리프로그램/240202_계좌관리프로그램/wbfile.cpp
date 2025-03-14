//#include "std.h"
//
//string wbfile::file_name = "members.txt";
//
//void wbfile::save(const vector<Member*>& members)
//{
//    ofstream out(file_name);        // 파일 열기
//
//    int size = (int)members.size();            // 파일 출력 객체
//    out << size << endl;
//
//    for (int i = 0; i < size; i++)
//    {
//        Member* pmem = members[i];
//        out << pmem->get_id() << "\t";
//        out << pmem->get_pw() << "\t";
//        out << pmem->get_name() << "\t";
//        out << pmem->get_phone() << "\t";
//        out << pmem->get_jointime().tm_year << "\t";
//        out << pmem->get_jointime().tm_mon << "\t";
//        out << pmem->get_jointime().tm_mday << "\t";
//        out << pmem->get_jointime().tm_hour << "\t";
//        out << pmem->get_jointime().tm_min << "\t";
//        out << pmem->get_jointime().tm_sec << endl;
//
//    }
//}                                   // 파일 닫기(소멸자 자동)
//
//int wbfile::load(vector<Member*>* members)
//{
//    ifstream in(file_name);         // 파일 읽기
//
//    int size;
//    in >> size;
//
//    for (int i = 0; i < size; i++)
//    {
//        string id, pw, name, phone;
//        tm day;
//
//        in >> id;
//        in >> pw;
//        in >> name;
//        in >> phone;
//        in >> day.tm_year;
//        in >> day.tm_mon;
//        in >> day.tm_wday;
//        in >> day.tm_hour;
//        in >> day.tm_min;
//        in >> day.tm_sec;
//
//
//        Member* pmem = new Member(id, pw, name, phone, day);
//
//        members->push_back(pmem);
//    }
//    return 1;
//
//}