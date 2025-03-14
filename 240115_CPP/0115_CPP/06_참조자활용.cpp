// 06_참조자활용.cpp
/*
[함수의 인자 전달]
1) 값	  : 값을 복사
2) 주소	  : 원본 주소 전달
---------------------------
3) 참조자 : 원본을 접근할 수 있는 동일한 식별자(메모리 생성X)
*/ 
#include <iostream>
using namespace std;

/*
204		n2		100
200		n1		11		--> 13
[fun1 stack]
n3 : 메모리가 생성되지 않고 fun1이 사용할 수 있는 식별자이다.
*/
void fun1(int n1, int* n2, int& n3)
{
	n1 = 11;
	*n2 = 12;
	n3 = 13;
}
/*
100		num1	10		--> 12	--> 13
[main stack]
*/
int main()
{
	int num1 = 10;

	fun1(num1, &num1, num1);

	printf("%d\n", num1);		// 13

	return 0;
}

