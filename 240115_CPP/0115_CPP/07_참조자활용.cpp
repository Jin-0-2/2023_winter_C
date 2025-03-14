// 07_참조자활용.cpp
/*
참조자 반환
 : 참조자를 반환하는 함수는 대입연산의 L value에 사용 가능하다.
*/
#include <iostream>
using namespace std;

int g_arr[5] = { 1,2,3,4,5 };

int get_data(int idx) { return g_arr[idx]; };

// 참조자 반환
int& get_data1(int idx) { return g_arr[idx]; };

int main()
{
	int value = get_data(2);		// int value = 3;
	// get_data(2) = value;			// 3 = 3; // 상수 = xx; ERR

	int value1 = get_data1(2);		// int value1 = g_arr[2];
	get_data1(2) = value1+10;			// g_arr[2] = 3+10;

	cout << g_arr[2] << endl;

	return 0;
}