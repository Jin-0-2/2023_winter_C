// 03_find_if.cpp
#include <iostream>
#include <vector>
#include <algorithm>		// STL의 알고리즘 사용
using namespace std;

// 값
void exam1()
{
	int arr[5] = { 1,2,3,4,5 };
	int* p = find(arr, arr + 5, 5);
	if (p != arr + 5)
		cout << *p << endl;
	else
		cout << "없다" << endl;
}

// 주소
bool test_find(int* p)
{
	if (*p == 5)	return true;
	else            return false;
}

class findclass
{
private:
	int findnum;
public:
	findclass(int _findnum) : findnum(_findnum) {}
public:
	bool operator()(int* p)	// 함수객체
	{
		if (*p == findnum)
			return true;
		else
			return false;
	}
};

int* myfind(int* p1, int* p2, int value)
{
	for (; p1 != p2; p1++)
	{
		if (*p1 == value)
			return p1;
	}
}

int* myfind_if(int* p1, int* p2, bool (*fun)(int*))
{
	for (; p1 != p2; p1++)
	{
		if (fun(*p1) == true)
			return p1;
	}
}

void exam2()
{
	vector<int*> vec;
	for (int i = 1; i <= 10; i++)		// 1,2...10
	{
		vec.push_back(new int(i));
	}

	vector<int>::iterator p = find_if(vec.begin(), vec.end(), test_find);
	if (p != vec.end())
		cout << **p << endl;
	else
		cout << "없다" << endl;
}

int main()
{
	exam2();

	return 0;
}