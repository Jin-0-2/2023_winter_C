// 01_배열.c
/*
[변수 선언]
int num;		// 정수 1개 저장 공간 생성
int arr[2];		// 정수 2개 저장 공간 생성		arr : 생성된 저장공간의 시작 주소 : 100번지 > 값 수정 불가.(저장공간을 가지지 않음.)
*/
#include <stdio.h>

void exam1();
void exam2();
void exam3();

void main()
{
	exam1();
}

// int 5개 저장하는 배열 선언
// int 5개 저장하는 배열, 1,2,3,4,5로 초기화
// 배열의 순회 : 배열과 반복문
// 순회 : 저장된 모든 값들을 모두 한번씩 접근
void exam1()
{
    int arr1[5];						// X ,X, X, X, X
	int arr2[5] = { 1,2,3,4,5 };		// 1, 2, 3, 4, 5
	int arr3[5] = { 1,2 };				// 1, 2, 0, 0, 0
	int arr4[5] = { 0 };				// 0, 0, 0, 0, 0

	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", arr4[i]);
	}
}

// 배열 선언시 초기화를 할 경우 배열의 크기 지정 생략 가능
void exam2()
{
//  char arr[];						// 에러
	char arr[] = { 'A','B','C' };	// 정상
	
	for (int i = 0; i < 3; i++)
	{
		printf("%c\n", arr[i]);
	}
}

// 배열의 사용
void exam3()
{
	// 1. 정수 1개를 저장하는 변수 선언 및 50으로 초기화
	int num = 50;

	// 정수 10개를 저장하는 배열 선언
	int arr[10];

	// 배열에 1~10까지 값을 순차적으로 저장
	// (반복문 목적: 배열의 인덱스!)
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 1;
	}

	// 배열 전체 출력
	for (int i = 0; i < 10; i++)
	{
		printf("%3d", arr[i]);
	}
	printf("\n");

	// 배열의 2인덱스의 값을 22로 변경
	arr[2] = 22;

	// 1번에 있는 변수의 값을 배열 3인덱스에 저장
	arr[3] = num;

	// 배열의 5인덱스의 값을 배열의 4인덱스에 저장
	arr[4] = arr[5];

	//배열 전체 출력
	for (int i = 0; i < 10; i++)
	{
		printf("%3d", arr[i]);
	}
	printf("\n");

	// 배열에 저장된 모든 값의 합을 출력
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum = sum + arr[i];
	}
	printf("합의 결과 : %d\n", sum);
}