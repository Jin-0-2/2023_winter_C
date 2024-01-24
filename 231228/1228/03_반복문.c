// 03_반복문.c
/*
특정 문장을 반복해서 실행
형태1) 횟수를 정해놓는다.
형태2) 특정 조건을 만족할 때 까지
*/
#include <stdio.h>

void exam1();
void exam2();
void exam3();
void exam4();
void exam5();
void exam6();
void exam7();
void exam8(); // 형태1)
void exam9();
void exam10();
void exam11();
void exam12();
void exam12();
void exam13();
void exam14();
void exam15();
void exam16();
void exam17();
void exam18();
void exam19();
void exam20();
void exam21();



void main()
{
	exam20();
}

// [while]Hello, World를 5번 출력
// 횟수 count 변수 필요 1) 초기화 2) 반복할 때 마다 증감 3) 계속 반복할지 여부를 판단.
void exam1()
{
	int i = 0;  // 1) 초기화

	while ( i < 5 )	// 2) 조건에 만족하면 반복
	{
		// 하고자 하는 일
		printf("Hello, World!\n");

		i++;  // 3) 증감
	}
}

// 정수를 3번 입력 받으시오.
void exam2()
{
	int in_a;
	int i = 0;

	while (i < 3)
	{
		printf("정수 입력 : ");
		scanf_s("%d", &in_a);

		i++;
	}
}

// 1부터 10까지 숫자를 출력 하시오.
void exam3()
{
	int i = 1; 

	while (i < 11)
	{
		printf("%d\n", i);

		i++; 
	}
}

// 1부터 100까지 숫자의 합을 출력하시오.
void exam4()
{
	int i = 1, sum = 0;

	while (i < 101)
	{
		sum = sum + i;

		i++;
	}

	printf("합 : %d", sum);
}

// 1부터 100까지 숫자 중 짝수의 합을 출력하시오
void exam5()
{
	int i = 1, sum = 0;

	// 방법 1)
	while (i < 101)
	{
		if(i%2 == 0)
			sum = sum + i;

		i++;
	}
	printf("합 : %d\n", sum);

	// 방법 2)
	i = 2;
	sum = 0;
	while (i < 101)
	{
		sum = sum + i;

		i = i + 2;
	}

	printf("합 : %d\n", sum);
}

// 10부터 1까지 출력하시오.
void exam6()
{
	int i = 10; 

	while (i > 0)
	{
		printf("%2d", i);

		i--;
	}
}

// 대문자 A부터 Z까지 출력하시오.
void exam7()
{
	char c = 'A';

	while ( c <= 'Z' )
	{
		printf("%2c", c);

		c++;
	}
}

// 구구단 중 5단을 출력하시오.
void exam8()
{
	int i = 1; 

	while (i < 10)
	{
		printf("%d * %d = %d\n", 5, i, 5 * i);

		i++;
	}
}

// [조건이 만족할 때 까지] -1을 입력할 때까지 입력할 것
void exam9()
{
	int num;

	// 무한루프
	while (1)
	{
		printf("정수 입력 : ");
		scanf_s("%d", &num);

		if (num == -1)
			break;
	}
}

// -1을 입력할 때까지 합을 구하시오.
void exam10()
{
	int num, sum = 0;

	
	while (1)
	{
		printf("정수 입력 : ");
		scanf_s("%d", &num);
		
		if (num == -1)
			break;

		sum = sum + num;
	}

	printf("합을 결과 : %d", sum);
}

void exam11()
{
	int i;

	for (i = 0; i < 5; i++)		// 초기화 ; 조건 
	{
		printf("Hello, World!\n");
	}
}

void exam12()
{
	int in_a;

	for (int i = 0; i < 3; i++)
	{
		printf("정수 입력 : ");
		scanf_s("%d", &in_a);
	}
}

void exam13()
{
	for (int i = 1; i < 11; i++)
	{
		printf("%d\n", i);
	}
}

void exam14()
{
	int sum = 0;

	for (int i = 1; i < 101 ; i++)
	{
		sum = sum + i;
	}

	printf("합 : %d", sum);
}

void exam15()
{
	int sum = 0;

	// 방법 1)
	for (int i = 1; i < 101; i++)
	{
		if (i % 2 == 0)
			sum = sum + i;
	}

	printf("합 : %d\n", sum);

	// 방법 2)
	sum = 0;

	for (int i = 2; i < 101; i = i + 2)
	{
		if(i%2==0)
			sum = sum + i;
		
	}
	printf("합 : %d\n", sum);

}

void exam16()
{
	for (int i = 10; i > 0; i--)
	{
		printf("%2d", i);
	}
}

void exam17()
{
	for (char c = 'A'; c <= 'Z'; c++)
	{
		printf("%2c", c);
	}
}

void exam18()
{
	for (int i = 1; i < 10; i++)
	{
		printf("%d * %d = %d\n", 5, i, 5 * i);
	}
}

void exam19()
{
	int num;

	for (;;)
	{
		printf("정수 입력 : ");
		scanf_s("%d", &num);

		if (num == -1)
			break;
	}
		
}

void exam20()
{
	int num, sum = 0;

	for (;;)
	{
		printf("정수 입력 : ");
		scanf_s("%d", &num);

		sum = sum + num;

		if (num == -1)
			break;
	}
	printf("합을 결과 : %d", sum);
}

// continue
void exam21()
{
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0) // 짝수일 때
			continue;   // 밑의 문장은 실행 x

		printf("%2d", i);
	}
}