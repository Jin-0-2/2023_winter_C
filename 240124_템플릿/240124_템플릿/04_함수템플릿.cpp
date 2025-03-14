// 04_함수템플릿.cpp
/*
[템플릿 == 일반화]
무언가를 만들었는데 타입에 관계없이 사용된다.
특수화의 반대 : 특별히 누군가만 사용가능
*/
#include <iostream>
using namespace std;

// 알고리즘 함수 구현 방법
// 구간[저장공간의 첫번째 요소 - 저장공간의 마지막 요소의 다음] 

template<typename T1, typename T2>
T1 myfind(T1 start, T1 end, T2 value)
{
	for (; start != end; start++)
	{
		if (*start == value)
			return start;
	}
	return start; // return end;
}

void exam1()
{
	int arr[7] = { 23, 12, 434, 2, -1 , 43, 213 };
	int *ret = myfind(arr, arr + 7, 2);

	if (ret == arr + 7)
		cout << "없다" << endl;
	else
		cout << *ret << endl;
}

void exam2()
{
	double arr[5] = { 23.2, 12.12, 43.1234, 2.23, -1.123 };
	double* ret = myfind(arr, arr + 5, -1.123);

	if (ret == arr +5)
		cout << "없다" << endl;
	else
		cout << *ret << endl;
}

int main()
{
	exam2();

	return 0;
}