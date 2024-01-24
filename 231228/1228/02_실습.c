// 02_실습.c
#include <stdio.h>

void exam1();
void exam2();
void exam3();
void exam4();


void main()
{
	exam4();
}

// 1) 양의 정수를 입력한 후 짝수면 “even number”, 홀수면 “odd number” 출력
// (힌트 : 나머지 연산자의 결과가 0이면 짝수, 1이면 홀수 임)
// 출력 예) 정수 : 3
// 3은 odd number
void exam1()
{
	unsigned int in_a;
	int out_a;

	printf("양의 정수 입력 : ");
	scanf_s("%d", &in_a);

	out_a = in_a % 2;

	if (out_a == 0)
		printf("%d은(는) even number", in_a);
	else
		printf("%d은(는) odd  number", in_a);

}

// 2) 알파벳 한 글자를 입력한 후 소문자이면 대문자로, 대문자이면 소문자로 변환하여 출력
// 출력 예) 알파벳 입력 : a
// 알파벳 변환 : A

void exam2()
{
	char in_a, out_a;

	printf("알파벳 입력 : ");
	scanf_s("%c", &in_a, (int)sizeof(in_a));

	if (in_a >= 65 && in_a <= 90)
		out_a = in_a + 32;
	else if (in_a >= 97 && in_a <= 122)
		out_a = in_a - 32;
	else
	{
		printf("잘못입력하셨습니다.");
		
		return;
	}

	printf("알파벳 변환 : %c", out_a);
}


//3) 출력예)에 맞는 4칙연산을 완성하시오.
//출력예) 
// ====================================================
//1. 더하기           2. 빼  기            3. 곱하기             4. 나누기
//====================================================
//선택하세요[1]
//첫번째 수 : 5
//두번째 수 : 7
//두 수의 합 = 12

void exam3()
{
	char ch_a;
	float in_a, in_b, out_a;

	printf("=============================================\n");
	printf("1. 더하기 \t2. 빼기 \t3. 곱하기 \t 4. 나누기\n");
	printf("=============================================\n");
	printf("선택하세요 : ");
	scanf_s("%c", &ch_a, (int)sizeof(char));
	char dummy = getchar();
	printf("첫번째 수: ");
	scanf_s("%f", &in_a);
	printf("두번째 수: ");
	scanf_s("%f", &in_b);

	if (ch_a == '1')
	{
		out_a = in_a + in_b;
		printf("두 수의 덧셈 : %.1f", out_a);
	}
	else if (ch_a == '2')
	{
		out_a = in_a - in_b;
		printf("두 수의 뺄셈 : %.1f", out_a);
	}
	else if (ch_a == '3')
	{
		out_a = in_a * in_b;
		printf("두 수의 곱셈 : %.1f", out_a);
	}	
	else if (ch_a == '4')
	{
		out_a = in_a / in_b;
		printf("두 수의 나눗셈 : %.1f", out_a);
	}
	else
	{
		printf("잘못 입력하였습니다.");
		
		return;
	}
}

// 2개의 수 입력한 후 큰 수를 출력
void exam4()
{
	float in_a, in_b, out_a;

	printf("수 입력 : ");
	scanf_s("%f", &in_a);
	printf("수 입력 : ");
	scanf_s("%f", &in_b);

	out_a = in_a - in_b;

	if (out_a > 0)
		printf("%.1f", in_a);
	else if (out_a < 0)
		printf("%.1f", in_b);
	else
	{
		printf("두 수가 같습니다.");

		return;
	}
}