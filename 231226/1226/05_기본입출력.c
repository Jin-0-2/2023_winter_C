// 05_기본입출력.c
#include <stdio.h>

void exam1();
void exam2();
void exam3();
void exam4();
void exam5();
void exam6();

void main()
{
	exam4();
}

// 입출력 상수(printf에 기본탑재 stdout, scanf에 기본탑재 stdin)
void exam1()
{
	// 프로그램 -> [출력 버퍼] -> 모니터
	printf("Hello, World!\n");

	//stdout : 모니터 출력 상수
	fprintf(stdout, "Hello, World\n");
}

// 문자 전용입출력 putchar
void exam2()
{
	char ch = 'A';
	putchar(ch); // 출력
	putchar('B');
	putchar('\t'); // tab
	putchar('C');
}

// 문자 전용입출력 getchar
void exam3()
{
	char ch1, ch2;

	ch1 = getchar();  //입렵버퍼에 들어온 첫번째 문자 가져감.
	ch2 = getchar();

	printf("%c, %c\n", ch1, ch2); // getchar(ch1);
}

// 문자 연속 입력
// 엔터(\n)도 입력 문자로 간주된다.
void exam4()
{
	char ch1, ch2;
	printf("문자 입력 : "); ch1 = getchar();
	char dummy = getchar(); // 엔터를 가져감

	printf("문자 입력 : "); ch2 = getchar();
	dummy = getchar(); 

	printf("\n입력 결과 --> %c, %c\n", ch1, ch2);
}

/*
개행('\n')      스페이스바(' ')    탭 ('\t')
 
12 23           1223

scanf("%d[받아드릴 서식]", &a[주소])
*/
// 1번째 : 10엔터(구분의 엔터) 20엔터 : 엔터는 구분자로서 사라짐
// 2번째 : 10스페이스바20엔터
void exam5()
{
	int num1, num2;

	printf("나누어서 입력\n");
	scanf_s("%d", &num1);
	scanf_s("%d", &num2);

	printf("입력결과 -> %d, %d\n", num1, num2);
}

void exam6()
{
	int num1, num2;

	printf("한번에 입력(예 : 10 20)\n");
	scanf_s("%d%d", &num1, &num2);

	printf("입력결과 -> %d, %d\n", num1, num2);
}