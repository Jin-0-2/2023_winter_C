// 03_������.cpp
/*
1. �±װ� Ÿ�Ը��̴�. [����ü, ������...]
2. ������ Ÿ�Կ� ������ ���� ���ԺҰ�![C��� ����]
*/
#include <iostream>
using namespace std;

enum subject
{
	COM, IT = 101, GAME, ETC = 200
};

int main()
{
	// 1. enum�� ���ŵ� Ű���� ���
	printf("%d\n", COM);	// 0

	// 2. ���� ����
	enum subject s1 = COM; 
	cout << s1 << endl;

	s1 = GAME;
	cout << s1 << endl;

	enum subject s2 = IT;
	cout << s2 << endl;

	enum subject s3 = GAME;
	cout << s3 << endl;

	enum subject s4 = ETC;
	cout << s4 << endl;




	// 3. C++������ ����
	// s1 = 300;

	printf("%d\n", s1);

	return 0;
}