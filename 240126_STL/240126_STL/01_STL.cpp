// 01_STL.cpp
/*
STL : standard template libaray (표준 템플릿 기반 라이브러리)
1) container : 저장소   ex) 클래스:vector(배열), list, stack, queue, set, map
2) algorhism : 알고리즘 ex) 멤버함수, 전역함수형태로 제공
3) iterator  : 이터레이터, 저장소를 순회하는 포인터
-------------------------------------------------------------------------------
4) ...etc
*/
#include <iostream>
#include <vector>		// vector 컨테이너
using namespace std;

void vec_printall(const vector<int>& vec)
{
	cout << "저장공간크기(BYTE) : " << vec.max_size() << endl;
	cout << "저장최대크기(max)  : " << vec.capacity() << endl;
	cout << "저장개수(size)     : " << vec.size() << endl;

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << "  ";
	}
	printf("\n");
}

// 생성시 정수를 전달 -> max값 size값이 변경
void exam1()
{
	vector<int> vec1(10);	// 저장 배열, max, size를 멤버필드로 가짐.
	vec_printall(vec1);
}

// 저장
/*
push_back : 0번째 인덱스부터 순차적으로 저장
			max값이 자동으로 증가한다.(관심없다)
			push_front라는 함수는 제공되지 않는다.(비효율)
*/
void exam2()
{
	vector<int> vec1;
	vec_printall(vec1);

	for (int i = 1; i <= 10; i++)
	{
		vec1.push_back(i);
	}

	vec_printall(vec1);
}

/*
insert (저장할 위치의 주소, 저장할 정보)
- 해당 주소는 반드시 존재해야 함
- 배ㅕㅇㄹ은 0번째 인덱스에서 순차적으로 값이 저장되어 있는 구조
*/
void exam3()
{
	vector<int> vec1;
	vec_printall(vec1);

	vec1.insert(vec1.begin(), 10);

	vec_printall(vec1);

	for (int i = 1; i <= 3; i++)	// 10 1 2 3
	{
		vec1.push_back(i);
	}

	// 0~4까지만 가능
	vec1.insert(vec1.begin() +5, 20);	// 10 1 2 3 [20]

	vec_printall(vec1);
}

// 삭제
/*
erase(삭제할주소)
*/
void exam4()
{
	vector<int> vec1;
	for (int i = 1; i <= 5; i++)	//  1 2 3 4 5 
	{
		vec1.push_back(i);
	}
	vec_printall(vec1);

	vec1.erase(vec1.begin() + 1);		// 2번째 값을 삭제	> 1 3 4 5
	vec_printall(vec1);
}

int main()
{
	exam4();

	return 0;
}