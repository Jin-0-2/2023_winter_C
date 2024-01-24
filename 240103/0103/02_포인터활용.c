// 02_포인터활용 c
/*
1) 배열 포인터 : 포인터 주소가 배열의 주소를 저장
				 포인터 변수를 통해 저장공간을 자유롭게 접근
2) 함수 포인터 : 함수의 이름도 주소이다.
				 함수를 저장하는 포인터
3) void 포인터 : 모든 타입의 주소를 저장할 수 있다.
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

// 배열 포인터
void exam1()
{
	int arr[5] = { 1,2,3,4,5 };
	int* p1 = arr;
	int* p2 = arr + 3;

	printf("%d, %d\n", *p1, *p2);		// 1, 4

	int arr1[][3] = { {1,2,3}, 
					  {4,5,6}, 
					  {7,8,9} };
	// int** p3 = arr1;  // int ** = int (*)[3] > 에러
	int(*p3)[3] = arr1;
	int(*p4)[3] = arr1 + 1;

	printf("%d, %d\n", **p3, **p4);		// 1, 4

	int* p5 = arr1[2];

	printf("%d\n", *p5);  // 7
	printf("%d\n", p5[0]);
}

// 함수 포인터 * 중요 *
void test1() { printf("test1()\n"); }

// 함수의 이름은 주소이다.(32비트 환경에서 실행)
void exam2()
{	
	printf("%d\n", (int)test1);			// 주소가 출력된다. > 10228247

	// 배열 포인터
	// int(*f0)[3];

	// 함수 포인터
	void (*f1)() = test1;				

	// 함수 호출[해당 주소로 이동하라]
	test1();
	f1();
}

// [in]int, int [out]int (합의 결과]
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
	int result = fun(n1, n2);		// 함수 호출 발생
	return result;					// 결과 반환
}

// [in]int, int, mycal
int exam4_sample(int n1, int n2, mycal fun)
{
	int result = fun(n1, n2);		// 함수 호출 발생
	return result;					// 결과 반환
}



// 기존 타입의 새로운 이름 정의
typedef unsigned int uint;		// [unsigned int] == [uint]		// 편리성
typedef unsigned int size_t;	// [unsigned int] == [size_t]	// 의미부여

typedef int(*mycal)(int, int);	// [int (*)(int,int) == [mycal]

 
void exam4()
{
	printf("%d\n", exam4_sample(10, 20, add));
	printf("%d\n", exam4_sample(10, 20, sub));

	// 기존방식과 typedef방식의 차이
	int (*fun1)(int, int) = add;
	mycal fun2 = add;

	fun1(10, 20);
	fun2(10, 20);
}

// void 포인터
// 기본적으로 포인터는 동일한 타입의 주소를 저장!
void exam5()
{
	int num = 10;
	int arr1[] = { 1,2,3 };
	char ch = 'A';
	char arr2[] = { 'a','b','c' };

	int* p1;
	p1 = &num;
	p1 = arr1;
	// p1 = &p1;			// int* = char*  에러
	// p1 = arr2;			// int* = char*  에러

	char* p2 = arr2;
	int* p3 = (int*)arr2;			// 강제 형변환

	printf("%c, %c\n", *p2, *p3);
	printf("%c, %c\n", *(p2 + 1), p3[1]);		// b, e
}


// 1) void*는 모든 타입의 주소 저장 가능 [이유 :  타입이 정해지지 않음]
// 2) 사용할 때는 반드시 타입을 결정해 주어야 한다[이유 :  위와 동일]
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