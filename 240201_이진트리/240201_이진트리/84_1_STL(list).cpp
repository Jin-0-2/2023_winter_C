//84_1_List 컨테이너

/*
* STL에서 제공하는 List 컨테이너 : 이중연결리스트를 템플릿 클래스화
*/

/*
*           [vector컨테이너      list 컨테이너]
*
* 데이터 :    vec.capacity()          X
* 연산자 :    vec[0]                  X
*            vec.begin()+1           X
==============================================================
*/
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void print_info(list<int>& vec)
{
    cout << "max_size : " << vec.max_size() << endl;    //강의실크기
    cout << "size: " << vec.size() << endl;             //학생수

    //---------------------------------------------------------
   /* list<int>::iterator head = vec.begin();
    list<int>::iterator tail = vec.end();
    while( head != tail)
    {
        int value = *head;
        cout << value << " ";
        head++;
    }
    cout << endl;*/

    list<int>::iterator head = vec.begin();
    list<int>::iterator tail = vec.end();
    for (head; head != tail; head++)
    {
        int value = *head;
        cout << value << " ";
    }
    cout << endl;
    cout << "----------------------------------------------" << endl;
}

//push_back[저장](0)
void exam1()
{
    list<int> vec;    //배열, 최대크기(0), 저장개수(0)
    print_info(vec);

    for (int i = 1; i <= 10; i++)
        vec.push_back(i);   //저장함수
    print_info(vec);    //배열, 최대크기(1066), 저장개수(1000)
}

void exam2()
{
    list<int> vec;    //배열, 최대크기(0), 저장개수(0)
    print_info(vec);

    for (int i = 1; i <= 10; i++)
        vec.push_front(i);  //배열과의 차이점
    print_info(vec);    //배열, 최대크기(1066), 저장개수(1000)
}

//insert : 공간의 인덱스 안에서 사용 가능(max : 10, 0~10)
void exam3()
{
    list<int> vec(10);    //객체생성시 10을 전달  max : 10, size : 10
    print_info(vec);

    vec.insert(vec.begin()++, 1);     //원하는 위치에 값을 저장(max증가, size증가)
    print_info(vec);                //max :15   size : 11 
}

//erase[삭제](0)
void exam4()
{
    list<int> vec;

    for (int i = 1; i <= 10; i++)
        vec.push_back(i);
    print_info(vec);

    list<int>::iterator cur = vec.begin();
    for (int i = 0; i < 3; i++)
        cur++;     //cur = cur->next;

    vec.erase(cur);  //삭제할 주소    
    print_info(vec);
}

//전체출력(순회) - iterator방식
void exam6()
{
    list<int> vec;
    for (int i = 1; i <= 10; i++)
        vec.push_back(i);

    list<int>::iterator begin = vec.begin();
    list<int>::iterator end = vec.end();
    for (; begin != end; begin++)
    {
        int value = *begin;
        cout << value << " ";
    }
    cout << endl;
}

//검색(구현방식)
list<int>::iterator exam7_select(list<int>& vec, int value1)
{
    list<int>::iterator begin = vec.begin();
    list<int>::iterator end = vec.end();
    for (; begin != end; begin++)
    {
        int value = *begin;
        if (value == value1)
            return begin;
    }
    return begin;  //end랑 동일!
}

void exam7()
{
    list<int> vec;
    for (int i = 1; i <= 10; i++)
        vec.push_back(i);

    list<int>::iterator itr = exam7_select(vec, 51);
    if (itr == vec.end())
        cout << "없다" << endl;
    else
        cout << *itr << endl;
}

//검색(find() )
void exam8()
{
    list<int> vec;
    for (int i = 1; i <= 10; i++)
        vec.push_back(i);

    list<int>::iterator itr = find(vec.begin(), vec.end(), 51);
    if (itr == vec.end())
        cout << "없다" << endl;
    else
    {
        int value = *itr;
        cout << value << endl;
    }
}

//수정( 5를 찾아서 55로 변경)
void exam9()
{
    list<int> vec;
    for (int i = 1; i <= 10; i++)
        vec.push_back(i);

    print_info(vec);

    list<int>::iterator itr = find(vec.begin(), vec.end(), 5);
    if (itr == vec.end())
        cout << "없다" << endl;
    else
    {
        *itr = 55;      //<--------- 수정
    }

    print_info(vec);
}

//정렬알고리즘
void exam10()
{
    srand((unsigned int)time(NULL));

    list<int> vec;
    for (int i = 1; i <= 20; i++)
    {
        int value = rand() % 100; //0~99
        vec.push_back(value);
    }
    print_info(vec);

    //전역함수
    //sort(vec.begin(), vec.end());

    //리스트컨테이너 맴버 함수
    vec.sort();

    print_info(vec);
}

int main()
{
    exam10();

    return 0;
}