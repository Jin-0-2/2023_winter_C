// 01_포인터.c
/*
1. [주소]를 저장 할 수 있는 공간을 생성
2. 포인터 변수의 저장 공간 크기? > 모두 동일하다.
	32bit -> 4byte, 64bit -> 8byte

	값 저장 공간 : 타입에 따라 크기가 다르다.
	sizeof(int) -> 4byte		sizeof(char) -> 1byte		sizeof(float) -> 4byte
3. 포인터 연산(주소)은 포인터 타입에 따라 이동의 크기가 달라진다.
	int *p1 = 정수배열의 주소;		p1 + 1; > sizeof(int)*1  이동
	char *p2 = 문자배열의 주소;		p2 + 1; > sizeof(char)*1 이동
*/
#include <stdio.h>

void exam1();
void exam2();

void main()
{
	exam1();
}

void exam1()
{
	int num1;
	char ch;
	float f_num2;

	int* p1;
	char* p2;
	float* p3;

	printf("%d, %d\n", (int)sizeof(int), (int)sizeof(num1));
	printf("%d, %d\n", (int)sizeof(char), (int)sizeof(ch));
	printf("%d, %d\n", (int)sizeof(float), (int)sizeof(f_num2));

	// 포인터의 저장공간은 모두 크기가 동일하다.
	printf("%d, %d\n", (int)sizeof(int*), (int)sizeof(p1));
	printf("%d, %d\n", (int)sizeof(char*), (int)sizeof(p2));
	printf("%d, %d\n", (int)sizeof(float*), (int)sizeof(p3));
}

// 주소 이동(32bit환경으로 변경 후 출력
void exam2()
{
	int arr1[10];
	char arr2[10];

	int* p1 = arr1;
	char* p2 = arr2;

	// 포인터 타입별 이동 크기가 다르다.
	printf("%d, %d\n", (int)p1, (int)(p1 + 1)); // 11859716, 11859720 > int 크기만큼
	printf("%d, %d\n", (int)p2, (int)(p2 + 1)); // 11859696, 11859697 > char 크기만큼
}