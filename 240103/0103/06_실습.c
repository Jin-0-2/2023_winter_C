// 06_실습.c
#include <stdio.h>

int myadd(int n1, int n2, int n3);

int main()
{
	int result = myadd(10, 20, 30);		// 호출문장
	printf("%d\n", result);

	return 0;
}

int myadd(int n1, int n2, int n3)
{
	int result = n1 + n2 + n3;
	return result;
}