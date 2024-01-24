// 03_연산자.c
#include<stdio.h>

void exam1();
void exam2();
void exam3();
void exam4();
void exam5();
void exam6();
void exam7();
void exam8();
void exam9();

void main()
{
	exam9();
}

// 문자 연산(영문자를 입력받고 그 다음문자를 출력하시오.)
void exam1()
{
	char in_a;
	char out_a;

	printf("영문자 입력 : ");
	scanf_s("%c", &in_a, (int)sizeof(in_a));

	out_a = in_a + 1;

	printf("다음번 문자는 : %c\n", out_a);
}

// 영문자와 정수를 입력받고 입력된 영문자에서 입력된 정수만큼 이동한 문자 출력
void exam2()
{
	char in_a;
	int in_b;
	char out_a;

	printf("영문자 입력 : ");
	scanf_s("%c", &in_a, (int)sizeof(in_a));
	printf("정수 입력 : ");
	scanf_s("%d", &in_b);

	out_a = in_a + in_b;
	printf("%c\n", out_a);
}

// 대문자를 입력받아 소문자로 변환하시오.
// 힌트 : A : 65 ->  a -> 97
void exam3()
{
	char in_a;
	char out_a;

	printf("대문자 입력 : ");
	scanf_s("%c", &in_a, (int)sizeof(in_a));
	
	out_a = in_a + ('a' - 'A');

	printf("입력한 대문자 : %c\n소문자 변환 : %c\n", in_a, out_a);
}

// 전치 :  문장에서 가장 먼저 수행되는 연산
void exam4()
{
	int a = 1;
	int b;

	// 전치 연산
	b = ++a;    // b = 2;
	printf("%d, %d\n", a, b); // 2, 2

	a = 1;
	b = ++a + ++a;  // b = 3 + 3;
	printf("%d, %d\n", a, b); // 3, 6

	a = 1;
	b = ++a + ++a + ++a;  // b = 4 + 4 + 4;
	printf("%d, %d\n", a, b); // 4, 12
}

// 후치 : 문장이 끝 난 후 수행되는 연산
void exam5()
{
	int a = 1;
	int b;

	// 후치 연산
	b = a++;    // b = 1;
	printf("%d, %d\n", a, b); // 2, 1

	a = 1;
	b = a++ + a++;  // b = 1 + 1;
	printf("%d, %d\n", a, b); // 3, 2

	a = 1;
	b = a++ + a++ + a++;  // b = 1 + 1 + 1;
	printf("%d, %d\n", a, b); // 4, 3
}

void exam6()
{
	int a = 1;
	int b;

	a = 1;
	b = a++ + ++a + ++a + a++;  // b = 3 + 3 + 3 + 3
	printf("%d, %d\n", a, b); // 5, 12
}

// page 1-40(비교 연산)
void exam7()
{
	int in_a = 100, in_b, out_a;

	printf("정수 입력 : ");
	scanf_s("%d", &in_b);

	out_a = (in_a == in_b);

	printf("%d", out_a);
}

// 논리 연산자
// 거짓(flase)  : 0
// 참(true)     : 0을 제외한 모든 수, 그 중 1을 대표값으로 사용
void exam8()
{
	printf("%d\t", -100 && 200);
	printf("%d\t", !-10);

	printf("\n");
	printf("%d\t", 1 && 1);
	printf("%d\t", 1 && 0);
	printf("%d\t", 0 && 1);
	printf("%d\t", 0 && 0);

	printf("\n");
	printf("%d\t", 1 || 1);
	printf("%d\t", 1 || 0);
	printf("%d\t", 0 || 1);
	printf("%d\t", 0 || 0);

	printf("\n");
	printf("%d\t", !1);
	printf("%d\t", !0);
}

// 출석(20), 과제(20), 중간평가(20), 기말평가(40)
// 를 입력한 후 합계가 60이상이고 100이하이면 P
// 아니면 F를 출력하시오.
void exam9()
{
	int in_a, in_b, in_c, in_d;
	int out_a, out_b;

	printf("출석     : ");			scanf_s("%d", &in_a);
	printf("과제	 : ");			scanf_s("%d", &in_b);
	printf("중간평가 : ");			scanf_s("%d", &in_c);
	printf("기말평가 : ");			scanf_s("%d", &in_d);

	out_a = in_a + in_b + in_c + in_d;
	out_b = (out_a >= 60) && (out_a <= 100);


	printf("%s", out_b == 1 ? "P" : "F");
}