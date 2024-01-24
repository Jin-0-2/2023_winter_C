// 02_������Ȱ�� c
/*
1) �迭 ������ : ������ �ּҰ� �迭�� �ּҸ� ����
				 ������ ������ ���� ��������� �����Ӱ� ����
2) �Լ� ������ : �Լ��� �̸��� �ּ��̴�.
				 �Լ��� �����ϴ� ������
3) void ������ : ��� Ÿ���� �ּҸ� ������ �� �ִ�.
*/
#include <stdio.h>

void exam1();
void exam2();
void exam3();
void exam4();
void exam5();
void exam6();


void main()
{
	exam6();
}

// �迭 ������
void exam1()
{
	int arr[5] = { 1,2,3,4,5 };
	int* p1 = arr;
	int* p2 = arr + 3;

	printf("%d, %d\n", *p1, *p2);		// 1, 4

	int arr1[][3] = { {1,2,3}, 
					  {4,5,6}, 
					  {7,8,9} };
	// int** p3 = arr1;  // int ** = int (*)[3] > ����
	int(*p3)[3] = arr1;
	int(*p4)[3] = arr1 + 1;

	printf("%d, %d\n", **p3, **p4);		// 1, 4

	int* p5 = arr1[2];

	printf("%d\n", *p5);  // 7
	printf("%d\n", p5[0]);
}

// �Լ� ������ * �߿� *
void test1() { printf("test1()\n"); }

// �Լ��� �̸��� �ּ��̴�.(32��Ʈ ȯ�濡�� ����)
void exam2()
{	
	printf("%d\n", (int)test1);			// �ּҰ� ��µȴ�. > 10228247

	// �迭 ������
	// int(*f0)[3];

	// �Լ� ������
	void (*f1)() = test1;				

	// �Լ� ȣ��[�ش� �ּҷ� �̵��϶�]
	test1();
	f1();
}

// [in]int, int [out]int (���� ���]
int add(int n1, int n2) { return n1 + n2; }
int sub(int n1, int n2) { return n1 - n2; }
void exam3()
{
	int (*f1)(int, int)= add;

	printf("%d\n", add(10, 20)); // 10, 20 > 30 
	printf("%d\n", f1(10, 20));

	f1 = sub;
	printf("%d\n", f1(10, 20));	
}

// [in]int, [in]int, int(*)(int, int)
int exam4_sample(int n1, int n2, int(*fun)(int, int))		
{
	int result = fun(n1, n2);		// �Լ� ȣ�� �߻�
	return result;					// ��� ��ȯ
}

// [in]int, int, mycal
int exam4_sample(int n1, int n2, mycal fun)
{
	int result = fun(n1, n2);		// �Լ� ȣ�� �߻�
	return result;					// ��� ��ȯ
}



// ���� Ÿ���� ���ο� �̸� ����
typedef unsigned int uint;		// [unsigned int] == [uint]		// ����
typedef unsigned int size_t;	// [unsigned int] == [size_t]	// �ǹ̺ο�

typedef int(*mycal)(int, int);	// [int (*)(int,int) == [mycal]

 
void exam4()
{
	printf("%d\n", exam4_sample(10, 20, add));
	printf("%d\n", exam4_sample(10, 20, sub));

	// ������İ� typedef����� ����
	int (*fun1)(int, int) = add;
	mycal fun2 = add;

	fun1(10, 20);
	fun2(10, 20);
}

// void ������
// �⺻������ �����ʹ� ������ Ÿ���� �ּҸ� ����!
void exam5()
{
	int num = 10;
	int arr1[] = { 1,2,3 };
	char ch = 'A';
	char arr2[] = { 'a','b','c' };

	int* p1;
	p1 = &num;
	p1 = arr1;
	// p1 = &p1;			// int* = char*  ����
	// p1 = arr2;			// int* = char*  ����

	char* p2 = arr2;
	int* p3 = (int*)arr2;			// ���� ����ȯ

	printf("%c, %c\n", *p2, *p3);
	printf("%c, %c\n", *(p2 + 1), p3[1]);		// b, e
}


// 1) void*�� ��� Ÿ���� �ּ� ���� ���� [���� :  Ÿ���� �������� ����]
// 2) ����� ���� �ݵ�� Ÿ���� ������ �־�� �Ѵ�[���� :  ���� ����]
void exam6()
{
	int num = 10;
	int arr1[] = { 1,2,3 };
	char ch = 'A';
	char arr2[] = { 'a','b','c' };

	void* p1;		
	p1 = &num;			printf("%d\n", *(int*)p1);			//10
	p1 = arr1;			printf("%d\n", *((int*)p1 + 2));		//3
	p1 = &p1;			printf("%c\n", *(char*)p1);
	p1 = arr2;			printf("%c\n", *((char*)p1 + 2));