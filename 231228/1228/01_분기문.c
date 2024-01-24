// 01_분기문.c
/*
제어문
1) 분기문     : if, if~else, if~else if~else if...~else (모든 분기문 처리) 
			    swith case (특정 형태의 분기문에 가독성 제공)
	조건에 만족하는 문장을 실행하겠다.(선택적 실행)

2) 반복문     : while      : 흐름이 보인다.
				do while   : while을 변경처리
				for        : 흐름이 안보인다. (가장 많이 사용함)
	조건을 반복해서 계속 물어봄, 만족되면 실행. (특정 문장 반복 실행)

 *관련 키워드 : break, countiue
*/
#include<stdio.h>

void exam1();
void exam2();
void exam3();
void exam4();
void exam5();
void exam6();
void exam7();

void main()
{
	exam7();
}

// if : 특정 문장을 실행할지 여부
//		조건 : 값, 범위
void exam1()
{
	int num = 11;

	// 조건에 만족하면 하위 문장 실행
	if (num == 10)
		printf("num은 10이다.\n");
	printf("if문과 관련 없는 코드");

	// 만약, 조건에 만족했을 때 여러 문장을 실행하고 싶다면?
	if (num == 11)
	{
		printf("문장1\n");
		printf("문장2\n");
	}
	
		


}

// if ~ else if : 둘 중 하나의 문장을 [반드시] 실행
void exam2()
{
	char gender = 'm';
	 
	if (gender == 'm')
		printf("남성\n");
	else
		printf("여성\n");
}

// if ~ else if ... else : 여러 문장 중 하나를 [반드시] 실행
void exam3()
{
	int age = 15;

	if (age >= 0 && age <= 9)
		printf("나이가 9보다 작거나 같다.\n");
	else if (age >= 10 && age <= 19)
		printf("10대\n");
	else if (age >= 20 && age <= 29)
		printf("20대\n");
	else
		printf("30대 이상\n");
}

// [조건문 형태] 값 비교
// 정수 2개, 연산자를 입력받아 해당 연산의 결과를 출력하시오.
void exam4()
{
	int in_a, in_b;
	char in_c;
	float out_a;

	printf("정수 입력 : ");
	scanf_s("%d", &in_a);
	printf("정수 입력 : ");
	scanf_s("%d", &in_b);
	char dummy = getchar();
	printf("연산자(+, -, *, /)입력 : ");
	scanf_s("%c", &in_c, (int)sizeof(in_c));
	

	if (in_c == '+')
		out_a = (float)in_a + in_b;
	else if (in_c == '-')
		out_a = (float)in_a - in_b;
	else if (in_c == '*')
		out_a = (float)in_a * in_b;
	else if (in_c == '/')
		out_a = (float)in_a / in_b;
	else
	{
		printf("잘못된 연산자 입력\n");
		
		return; // 함수를 종료하겠다!
	}

	printf("%d %c %d = %.1f", in_a, in_c, in_b, out_a);
}

// [조건문 형태] 범위 비교
// 점수를 입력받아 학점을 출력하시오.(A,B,C,D,F)
void exam5()
{
	int in_a;
	char out_a;

	printf("점수를 입력 : ");		
	scanf_s("%d", &in_a);

	if (in_a >= 90 && in_a <= 100)
		out_a = 'A';
	else if (in_a >= 80 && in_a <= 89)
		out_a = 'B';
	else if (in_a >= 70 && in_a <= 79)
		out_a = 'C';
	else if (in_a >= 60 && in_a <= 69)
		out_a = 'D';
	else
		out_a = 'F';

	printf("학점 : %c", out_a);
}

// switch 문의 이해 (값 비교 형태에서 가독서이 좋다)
// 책이 있고 중간에 책갈피로 구분하는 형태
void exam6()
{
	int num = 4;

	switch (num) // [값 비교]비교대상의 정보(정수와 문자만 가능 [실수, 문자열 X])
	{
	case 1:                                //if
		printf("1페이지\n");
		printf("2페이지\n");
		break; // 멈춤 
	case 2:                                // if else
		printf("3페이지\n");
		printf("4페이지\n");
		printf("5페이지\n");
		break;
	case 3:                                // if else
		printf("6페이지\n");
		printf("7페이지\n");
		break;
	default:                               // else
		printf("만족하지 않음\n");
	}
	
}

//exam4를 switch문으로 변경
void exam7()
{
	int in_a, in_b;
	char in_c;
	float out_a;

	printf("정수 입력 : ");
	scanf_s("%d", &in_a);
	printf("정수 입력 : ");
	scanf_s("%d", &in_b);
	char dummy = getchar();
	printf("연산자(+, -, *, /)입력 : ");
	scanf_s("%c", &in_c, (int)sizeof(in_c));

	switch (in_c)
	{
	case '+':
		out_a = (float)in_a + in_b;
		break;
	case '-':
		out_a = (float)in_a - in_b;
		break;
	case '*':
		out_a = (float)in_a * in_b;
		break;
	case '/':
		out_a = (float)in_a / in_b;
		break;
	default:
		printf("잘못된 연산자 입력\n");
		
		return;
	}
	printf("%d %c %d = %.1f", in_a, in_c, in_b, out_a);
}