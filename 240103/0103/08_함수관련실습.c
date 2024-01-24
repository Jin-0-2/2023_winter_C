// 08_함수관련실습.c
#include <stdio.h>

int input_height(const char* msg);
float input_width(const char* msg);
char input_char(const char* msg);
float get_area(int n1, float n2, char type);
void myprint(char type, float area);

int main()
{
	int num1;
	float num2;
	char type;
	float area;

	num1 = input_height("높이 입력(정수): ");
	num2 = input_width("폭 입력(실수): ");
	type = input_char("r(사각형)t(삼각형)");

	area = get_area(num1, num2, type);

	myprint(type, area);
}

int input_height(const char* msg)
{
	printf("%s : ", msg);
	int num1;

	scanf_s("%d", &num1);
	char dummy = getchar();

	return num1;
}

float input_width(const char* msg)
{
	printf("%s : ", msg);
	float num2;

	scanf_s("%f", &num2);
	char dummy = getchar();

	return num2;
}

char input_char(const char* msg)
{
	printf("%s : ", msg);

	char type;
	scanf_s("%c", &type, (int)sizeof(char));

	return type;
}

float get_area(int n1, float n2, char type)
{
	float area = 0;

	switch (type)
	{
		case 'r': area = n1 * n2; break;
		case 't': area = (n1 * n2) / 2; break;
	}

	return area;
}

void myprint(char type, float area)
{
	if (type == 'r')
	{
		printf("사각형 넓이 : %.1f\n", area);
	}
	else if (type == 't')
	{
		printf("삼각형 넓이 : %.1f\n", area);
	}
}