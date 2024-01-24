// 02_문자열들 관리
#include <stdio.h>

void exam1();

int main()
{
	exam1();

	return 0;
}

// 배열을 이용하여 여러개의 정보를 관리할 수 있다.
void exam1()
{
	int age[3] = { 10, 20,30 };

	// 3 : 문자열의 개수
	// 10 : 하나의 문자열크기(영문1, 한글2)
	char name[3][10] = { "홍길동", 
						 "김길동", 
						 "이길동" };

	// 첫번째 저장된 정보
	printf("%d\n", age[0]);
	printf("%s\n", name[0]);

	// 두번째 저장된 정보
	printf("%d\n", age[1]);
	printf("%s\n", name[1]);
}