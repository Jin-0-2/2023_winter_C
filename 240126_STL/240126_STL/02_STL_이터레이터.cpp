// 02_STL_이터레이터.cpp
// [구간] - 저장소의 시작위치 ~ 마지막 저장소의 다음위치
/*
iterator : 저장소를 순회할 수 있는 포인터
		   내포 클래스(외부 클래스 전용 클래스)
template<typename T>
class vector		// 클래스 이름이 변경.
{
public:
	class iterator
	{
	}
};

vector<int*> v1;
vector<int*>::iterator it;

*/
#include <iostream>
#include <vector>
#include <algorithm>		// STL의 알고리즘 사용
using namespace std;

void exam1()
{
	int arr[5] = { 1,2,3,4,5 };
	int *p = find(arr, arr + 5, 5);
	if (p != arr + 5)
		cout << *p << endl;
	else
		cout << "없다" << endl;
}

// vector 구간 획득
/*
[시작]			 vec.begin();
[종료 다음 위치] vec.end();  종료된 마지막 데이터의 다음 위치
*/
void exam2()
{
	vector<int> vec;
	for (int i = 1; i <= 10; i++)		// 1,2...10
	{
		vec.push_back(i);
	}

	/*vector<int>::iterator b = vec.begin();
	vector<int>::iterator c = vec.end();
	find(b, c, 5);*/
	vector<int>::iterator p = find(vec.begin(), vec.end(), 5);
	if (p != vec.end())
		cout << *p << endl;
	else
		cout << "없다" << endl;
}

void exam3()
{
	vector<int> vec;
	for (int i = 1; i <= 10; i++)		// 1,2...10
		vec.push_back(rand() % 1000);

	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;

	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}

int main()
{
	exam3();

	return 0;
}