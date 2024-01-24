// 03_실습.c
/*
[프로그램 작성 단계]
1. 변수 선언 : 정보를 저장할 공간을 생성 (생성하면 기본적으로 쓰레기가 들어있음)
	int(: 정수(-1, 0, 1)) a(식별자) ;(문장의 끝)
	> a라는 이름의 정수형 변수 선언
2. 초기화    : 첫번째로 값을 저장
	a = 10;
	> a라는 공간에 10을 저장(대입)
3. 연산      : 정보를 이용해 결과값을 획득 (input은 초기화 필요, output)
	c = a + b; [in] a,b  [out] c
4. 결과출력
	c를 출력? 30 printf("c의 값 -> %d\n", c); > c의 값 -> 30
*/

#include <stdio.h>

void exam1();
void exam2();
void exam3();
void exam4();
void exam5();
void exam6();
void exam7();

void main()
{
	exam6();
}

void exam1()
{
	// 변수 선언
	int a;
	int b;
	int c;

	// 초기화
	a = 10;
	b = 20;

	// 연산 : [in]a, b  [out] c
	c = a + b;

	// 결과출력
	printf("%d + %d = %d\n", a, b, c);
}

void exam2()
{
	int a;
	int b;
	int c;

	a = 30;
	b = 40;

	c = a - b;
	printf("%d - %d = %d\n", a, b, c);
}

void exam3()
{
	double a;
	double b;
	double c;

	a = 10.12;
	b = 20.12;

	c = a * b;

	// %lf에 .2는 소숫점 2번째 자리까지
	printf("%.2lf x %.2lf = %.2lf\n", a, b, c);
}

void exam4()
{
	int a;
	double b;
	int c1;
	double c2;

	a = 10;
	b = 3.12;
	
	// .c(87,9): warning C4244: '=': 'double'에서 'int'(으)로 변환하면서 데이터가 손실될 수 있습니다.
	c1 = a * b;  // int = double;
	c2 = a * b;

	printf("%d * %lf = %lf\n", a, b, c2);
}

void exam5()
{
	int a;
	double b;
	double c;

	a = 10;
	b = 3;

	c = a / b;  // c(double) = int > 타입 안맞음 // c = 3.0;
	
	printf("%lf\n", c);
}

// 문자 타입
void exam6()
{
	char a;

	a = 'A';  //아스키코드표  --> 65를 저장

	printf("%c\n", a);  // 65 --> 아스키코드표 --> 'A'
	printf("%d\n", a);  // 65

	char b;
	b = a + 1;  // b = 66;
	printf("%d , %c\n", b, b);   // 66, B

	char c; // 0 ~ 127
	c = 97; // char = int
	printf("%d , %c\n", c, c); // 97, a

	char d;
	char e;
	d = 0;    //숫자 0 --> 그대로 저장
	e = '0';  //문자 0 --> 아스키코드표 --> 48

	printf("%d, %c", d, e);
}

// 입출력!
// 출력 : printf
// 입력 : scanf, scanf_s(safe)
// 사용자에게 2개의 정수를 입력받아 합의 결과를 출력하시오.
void exam7()
{
	int num1;
	int num2;
	int result;
	printf("정수 입력 : ");
	scanf_s("%d", &num1);

	printf("정수 입력 : ");
	scanf_s("%d", &num2);

	result = num1 + num2;

	printf("%d + %d = %d\n", num1, num2, result);
}