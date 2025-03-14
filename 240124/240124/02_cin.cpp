// 02_cin.cpp
#include <iostream>
using namespace std;

// cin은 내부적으로 scanf를 사용한다. (공백, 탭, 엔터)
// test1) abc 엔터 def 엔터
// test2) abc공백def엔터
void exam1()
{
	string str1, str2;
	cout << "문자열 입력 : ";	cin >> str1;
	cout << "문자열 입력 : ";	cin >> str2;

	cout << "\n결과 : " << str1 << "\t" << str2 << endl;
}

// cin.getline()은 내부적으로 gets를 사용한다. (엔터)		// 공백을 입력받아 쓰고 싶을 때 getline 사용
// test1) abc 엔터 def 엔터
// test2) abc공백def엔터
void exam2()
{
	char str1[20], str2[20];
	cout << "문자열 입력 : ";	cin.getline(str1, sizeof(str1));
	cout << "문자열 입력 : ";	cin.getline(str2, sizeof(str2));
	cout << "\n결과 : " << str1 << "\t" << str2 << endl;
}

// cin.ignore() -> char dummy = getchar() 대신 사용
void exam3()
{
	int num1, qnum2;
	string str1;
	char str2[20];
	
	cout << "정수 : ";		cin >> num1;
	cout << "문자열 : ";	cin >> str1;
	cout << "\n결과 : " << num1 << "\t" << str1 << endl;

	cout << "정수 : ";		cin >> num1;
	cin.ignore();		//char dymmy = getchar(); 입력버퍼의 문자 1개를 빼버림.
	cout << "문자열 : ";	cin.getline(str2, sizeof(str2));
	cout << "\n결과 : " << num1 << "\t" << str2 << endl;
}

// cin : 원하는 타입이 입력되지 않을 때 고장난다.
int input_number(string msg)
{
	int value;

	while (true)
	{
		cout << msg << " : ";
		cin >> value;
		if (cin)
			return value;
		

		cin.clear();	// cin객체 초기화(고장 -> 회복)
		cin.ignore();	// 버퍼의 기존 문자를 제거
	}

}

void exam4()
{
	int num = input_number("정수");
	cout << num << endl;
}

int main()
{
	exam4();

	return 0;
}