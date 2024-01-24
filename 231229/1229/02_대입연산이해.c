// 02_대입연산이해.c
/*
[차수 공식?]
---------------------------
1) 변수 선언
	*, [ ] : 차수 1 증가
2) 변수 사용
	*, [ ] : 차수 1 감소
	&	   : 차수 1 증가
---------------------------
0차		   : 값 반환
1차 이상   : 주소 반환
---------------------------

int num = 1;  100번지	num		1
			  num  -> 1				(int)  > 0차
			  &num -> 100번지		(int*) > int의 1차라는 뜻

int arr[3] = {1,2,3};							108		arr[2]		3
		> 변수 선언에 [ ] 사용 > 1차			104		arr[1]		2
												100		arr[0]		1

												arr[0]		1		(int) > 1차변수 사용에 [ ]사용 > 0차 
												&arr[0]		100		(int*)
												arr			100		(int*) > arr라는 건물의 시작점. > 100번지
*/
#include <stdio.h>

void exam1();
void exam2();
void exam3();

void main()
{
	exam2();
}

// 배열과 주소
// [프로젝트] -> [속성] -> (구성속성 -> 링커 -> 고급): 
// 임의 주소(no), 고정주소(yes)
/*
432	arr[3]	40
428 arr[2]	30	
424 arr[1]	20
420 arr[0]	10
*/

void exam1()
{
	int arr[4] = { 10,20,30,40 };

	printf("%d\n", (int)arr);		 // int* -> 주소 : 1703420
	printf("%d\n", (int)&arr[1]);	 // int* -> 주소 : 1703424

	// + 연산의 차이점
	printf("%d\n", arr[0] + 3); // 10(값) + 3     = 13
	printf("%d\n", (int)(arr + 3));	// 420(주소) + 3 = 417(x) > 420 주소에 + 3은 다음 주소가 무엇인가. > 432

	// * : 역참조 : 내가 갖고 있는 주소로 이동
	// arr를 + 2 만큼 이동한 역참조
	printf("%d\n", arr[2]);			// 값 30 (int)
	printf("%d\n", *(arr + 2));		// 값 30 (int)
}

/*
108		ppnum	104			ppnnum : 104			&ppnum : 108		*ppnum : 100		**ppnum: 10
104		pnum	100			pnu	   : 100			&pnum  : 104		*pnum  : 10
100		num		10			num    : 10				&num   :100
*/
void exam2()
{
	int num = 10;			// 0차
	int* pnum;				// 변수 선언에 * 씀 > 1차 업! > 1차
	int** ppnum;			// 변수 선언에 * 씀 > 1차 업! > 2차

	pnum = &num;			// int*(int의 1차) = int > 타입이 다름 >>> int* = int*
	ppnum = &pnum;;		// int**(int의 2차) = int > 타입이 다름 >> num에 &&사용 불가  // int** = int**

	printf("num, pnum, ppnum의 주소를 알아보자\n");
	printf("num   주소 : %d\n", (int)&num);					// 1703432
	printf("pnum  주소 : %d\n", (int)&pnum);				// 1703420
	printf("ppnum 주소 : %d\n", (int)&ppnum);				// 1703408
	printf("num값: %d, pnum값: %d, ppnum값: %d\n", num, (int)pnum, (int)ppnum); // 10, 1703432, 1703420
	printf("%d, %d, %d\n", num, *pnum, (int)*ppnum);  // 10, 10, 10

	// *ppnum = &num;		//int* = int*
}

void exam3()
{
	int arr[5] = { 10, 20, 30, 40, 50 };		// arr를 100번지 가정.
	int* p1 = arr;			// int* = int*
	int* p2 = arr + 2;		// int* = int*

	printf("%d\n", *(p1 + 2));		// 30
	printf("%d\n", p1[2]);			// 30
	printf("%d, %d\n", *(arr + 2), arr[2]); // 30, 30

	printf("%d\n", *p2);			// 30
	printf("%d\n", *(p2 + 2));		// 50
	printf("%d\n", *(p2 - 2));		// 10
	printf("%d\n", p2[2]);			// 50
	printf("%d\n", p2[-2]);			// 10

	printf("%d\n", *p2 + 2);		// 32
	printf("%d\n", *(p2 + 2));		// 116번지 * -> 50
}