//81_STL(int).cpp
/*
Container (데이터 저장소)  자료구조(배열, 연결리스트, 스택, 큐, 덱, 그래프, 힙, 해쉬테이블, 트리)
      템플릿기반 클래스             vector,  list
      #include <vector> //클래스명과 h파일명이 동일..
Algorithm [첫번째, 두번째 인자로 구간]
      템플릿기반 맴버함수, 템플릿기반 전역함수
Iterator
      컨테이너를 순회할 수 있는 포인터 
*/

/*
* [vector컨테이너]
*  저장 : push_back() : 배열의 저장공간을 자동으로 적절하게 늘려나간다, size를 1증가시킨다.
*  삭제 : erase()     : 삭제할 주소를 전달, size를 1감소시킨다.
*  위치 얻기 : begin() : 배열의 첫번째 인덱스의 주소(iterator)
*             end()   : 배열의 마지막 저장 인덱스의 다음 주소(iterator)
*  전체출력(순회)-기존 방식 :  size(), [i]
*  전체출력(순회)-iterator방식
*  검색 : 직접 검색
*         find 알고리즘 함수를 활용
*  수정 : 검색 후 값을 변경
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_info(const vector<int>& vec)
{
    cout << "max_size : " << vec.max_size() << endl;
    cout << "max : " << vec.capacity() << endl;
    cout << "size: " << vec.size() << endl;        
    for (int i = 0; i < (int)vec.size(); i++)
    {
        int value = vec[i];  //배열처럼 사용 가능
        cout << value << " ";
    }
    cout << endl;    
    cout << "----------------------------------------------" << endl;
}

//push_back[저장](0)
void exam1()
{
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 }; //배열 -> 컨테이너

    vector<int> vec;    //배열, 최대크기(0), 저장개수(0)
    print_info(vec);

    for (int i = 1; i <= 1000; i++)
        vec.push_back(i);   //저장함수
    print_info(vec);    //배열, 최대크기(1066), 저장개수(1000)
}

//배열연산자[저장] : 미리 저장공간이 만들어져 있을때만 가능
void exam2()
{
    vector<int> vec(10);    //객체생성시 10을 전달  max : 10, size : 10
    print_info(vec);

    vec[1] = 1;
    print_info(vec);
}

//insert : 공간의 인덱스 안에서 사용 가능(max : 10, 0~10)
void exam3()
{
    vector<int> vec(10);    //객체생성시 10을 전달  max : 10, size : 10
    print_info(vec);

    vec.insert(vec.begin()+1, 1);     //원하는 위치에 값을 저장(max증가, size증가)
    print_info(vec);                //max :15   size : 11 
}

//erase[삭제](0)
void exam4()
{
    vector<int> vec;    

    for (int i = 1; i <= 10; i++)
        vec.push_back(i);  
    print_info(vec);    

    vec.erase(vec.begin()+5);  //삭제할 주소
    print_info(vec);
}

//전체출력(순회)-기존 방식
//size(), [i]
void exam5()
{
    vector<int> vec;

    for (int i = 1; i <= 10; i++)
        vec.push_back(i);

    for (int i = 0; i < (int)vec.size(); i++)
    {
        int value = vec[i];  //배열처럼 사용 가능
        cout << value << " ";
    }
}

//전체출력(순회) - iterator방식
void exam6()
{
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    int* begin = arr;
    int* end = arr + 10;

    vector<int> vec;
    for (int i = 1; i <= 10; i++)
        vec.push_back(i);

    vector<int>::iterator begin1 = vec.begin();
    vector<int>::iterator end1  = vec.end();
    for(; begin1 != end1; begin1++)
    {
        int value = *begin1;
        cout << value << " ";
    }
    cout << endl; 
}

//검색(구현방식)
int exam7_select(const vector<int>& vec, int value1)
{
    for (int i = 0; i < (int)vec.size(); i++)
    {
        int value = vec[i];  //배열처럼 사용 가능
        if (value == value1)
            return i;
    }
    return -1;
}

void exam7()
{
    vector<int> vec;
    for (int i = 1; i <= 10; i++)
        vec.push_back(i);

    int idx = exam7_select(vec, 5);
    if (idx == -1)
        cout << "없다" << endl;
    else
        cout << vec[idx] << endl; 
}

//검색(find() )
void exam8()
{
    vector<int> vec;
    for (int i = 1; i <= 10; i++)
        vec.push_back(i);

    vector<int>::iterator itr = find(vec.begin(), vec.end(), 5);
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
    vector<int> vec;
    for (int i = 1; i <= 10; i++)
        vec.push_back(i);

    vector<int>::iterator itr = find(vec.begin(), vec.end(), 5);
    if (itr == vec.end())
        cout << "없다" << endl;
    else
    {
        *itr = 55;      //<--------- 수정
    }

    for (int i = 0; i < (int)vec.size(); i++)
    {
        int value = vec[i];  //배열처럼 사용 가능
        cout << value << " ";
    }
}

//정렬알고리즘
void exam10()
{
    srand((unsigned int)time(NULL));

    vector<int> vec;
    for (int i = 1; i <= 20; i++)
    {
        int value = rand() %100; //0~99
        vec.push_back(value);
    }
    print_info(vec);

    sort(vec.begin(), vec.end());

    print_info(vec);
}

int main()
{
    exam10();

    return 0;
}