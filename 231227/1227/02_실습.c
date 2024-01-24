// 02_실습.c
// 변수 선언 -> 초기화 -> 연산(in/out) -> 결과 출력

#include <stdio.h>

void exam1();
void exam2();
void exam3();
void exam4();

void main()
{
	exam4();
}

// 폭과 높이를 입력받아 사각형의 넓이를 구하시오.
void exam1()
{
	float lenght;
	float width;
	float area;

	printf("폭 : "); 
	scanf_s("%f", &width);
	printf("높이 : "); 
	scanf_s("%f", &lenght);

	area = lenght * width;

	printf("넓이는 %f", area);
}

// 폭과 높이를 입력받아 삼각형의 넓이를 구하시오.
// 정수를 입력받아 실수로 출력
// 단, 나눗셈을 하면 실수값이 나와야함. (소수점 한자리까지 출력 요망)
// 삼각형의 넓이 = 폭 * 높이 / 2; 
void exam2()
{
	int lenght;
	int width;
	float area;

	printf("폭 : ");
	scanf_s("%d", &width);
	printf("높이 : ");
	scanf_s("%d", &lenght);

	area = lenght * width / 2.0f;
	area = (float)lenght * width / 2;

	printf("넓이는 %.1f", area);
}

// 반지름을 정수로 입력받아 원의 넓이를 구하시오.
// 원의 넓이 = 반지름 * 반지름 * 3.14
// 결과는 소수점 한자리까지
void exam3()
{
	int r;
	float area;

	printf("반지름을 입력하시오 : ");
	scanf_s("%d", &r);

	area = r * r * 3.14f;

	printf("원의 넓이 : %.1f", area);
}

// 연습문제
void exam4()
{
	char ch;

	printf("단일 문자를 입력하시오. 예) A\n입력 : ");
	scanf_s("%c", &ch, (int)sizeof(ch));

	printf("%d", ch);
}
