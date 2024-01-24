// 04_실습.c
#include <stdio.h>

void exam1();
void exam2();
void exam3();
void exam4();
void exam4();
void exam5();
void exam6();

void main()
{
	exam5();
}


// 1) 사용자로부터 숫자를 입력 받아, 그 수만큼 “Hello, World!” 를 출력하시오.
void exam1()
{
	int in_a;

	printf("반복할 횟수 입력: ");
	scanf_s("%d", &in_a);

	for (int i = 0; i < in_a; i++)
	{
		printf("Hello, World!\n");
	}
}

// 2) 알파벳 소문자를 a~z까지 순서대로 출력하시오.
void exam2()
{
	for (char c = 'a'; c <= 'z'; c++)
	{
		printf("%2c", c);
	}
}

// 3) 문자 ‘X’ 나 ‘x’ 를 입력할 때 까지 계속해서 문자를 입력받아 화면에 출력하시오. 
void exam3()
{
	
	for (char c;;)
	{
		printf("문자 입력(X or x 입력시 끝): ");
		scanf_s("%c", &c, (int)sizeof(char));
		char dummy = getchar();

		if (c == 'X' || c == 'x')
			break;
	}
}

// 4) 구구단 단수를 입력받아 해당 구구단을 출력하시오. 단, 구구단 단수에 0을 입력할 
// 때까지 계속  사용자가 원하는 구구단을 반복해서 출력할 것
void exam4()
{
	int in_a;

	for (;;)
	{
		printf("구구단 단수 입력(단, 0입력시 종료): ");
		scanf_s("%d", &in_a);

		if (in_a == 0)               // 탈출의 위치 > if 문이 for문 보다 아래에 위치하면 0에 대한 구구단 값이 나오고 탈출함 0입력시 종료하려는 의도와 맞지 않음.
		{
			break;
		}

		for (int i = 1; i < 10; i++)
			{
				printf("%d * %d = %d\n", in_a, i, in_a * i);
			}
	}
}

// 5) -1을 입력할 때까지 정수를 계속 입력하고, 입력한 수의 합과 평균을 출력하시오. 
void exam5()
{
	int num, sum = 0, i = 0;
	float aver;

	for (;;)
	{
		printf("정수 입력 : ");
		scanf_s("%d", &num);

		if (num == -1)  // 탈출의 위치 > -1을 받으면 탈출인데 sum 보다 아래에 위치하면 -1까지 더하여서 계산을 함 최종적인 값에 영향을 줄 수 있음.
			break;

		sum = sum + num;
		
		i++;
		
	}
	aver = sum / (float)i;

	printf("합 결과: %d\n", sum);
	printf("평균 값: %.1f\n", aver);
}

// 화씨 온도를 섭씨 온도로 환산하여 출력하시오. 
// 단, 0도부터 100도까지 10도 단위로 10개의 온도를 출력하시오.
// (섭씨온도 = 5 / 9 * (화씨온도 - 32)) * 타입에 주의 할것, 결과는 실수로 나옴
void exam6()
{
	for (int hwa = 0; hwa < 101; hwa = hwa + 10)
	{
		printf("화씨 온도: %d >> 섭씨 온도: %.3f\n", hwa, (float)5 / 9 * (hwa - 32));  
		//  5 / 9 * ((float)hwa - 32) > 0만 나온 이유 순서대로 계산시 5(int) / 9(int)의 나누기는 0만 나옴 hwa에 float를 붙여봤자 곱하는 값이 0이기 때문에 안됨.
	}
}