// 05_�Լ��� ��ȯ(����Ÿ��)
/*
�Լ��� ���� ���
1) ��� �ڵ� ���� + ' } '
2) return Ű����
*/
#include <stdio.h>

void fun1();		// ��ȯ X
int fun2();			// int
char fun3();		// char

void main()
{
	fun1();
	// ��ȯ�� �������̴�..!
	fun2();							// 10
	int num = fun2();				// int num = 10;
	printf("%d\n", num);
	
	fun3();
	char ch = fun3();
	printf("%c\n", ch);
}

void fun1()
{
	printf("1\n");
	return;
	printf("2\n");
	printf("3\n");
}

int fun2()
{
	return 10 + 20 + 30;
}

char fun3()
{
	char ch = 'A';
	return ch + 1;
}