// 07_�ڵ庯��.c
#include <stdio.h>

// �Լ��� ���� �� �ڵ��� ��
/*int main()
{
	int num1, num2;
	char oper;
	float result;

	printf("���� �Է� : ");		scanf_s("%d", &num1);
	printf("���� �Է� : ");		scanf_s("%d", &num2);
	char dummy = getchar();
	printf("������ �Է� : ");	scanf_s("%c", &oper, (int)sizeof(char));

	switch (oper)
	{
		case '+': result = num1 + num2; break;
		case '-': result = num1 - num2; break;
	}

	printf("%d %c %d = %.0f\n", num1, oper, num2, result);
}
*/

// �Լ��� ��� �� �ڵ��� ��
int input_number(const char* msg);
char input_char(const char* msg);
int mycal(int n1, int n2, char oper);
void myprint(int n1, int n2, char oper, int result);

int main()
{
	int num1, num2;
	char oper;
	int result;

	num1 = input_number("���� �Է� : ");
	num2 = input_number("���� �Է� : ");
	oper = input_char("������ �Է� : ");

	result = mycal(num1, num2, oper);

	myprint(num1, num2, oper, result);

	return 0;
}

// ������ �Է¹޾� ��ȯ
int input_number(const char* msg)
{
	printf("%s : ", msg);

	int num;
	scanf_s("%d", &num);
	char dummy = getchar();

	return num;
}

char input_char(const char* msg)
{
	printf("%s : ", msg);

	char oper;
	scanf_s("%c", &oper, (int)sizeof(char));

	return oper;
}

int mycal(int n1, int n2, char oper)
{
	int result = 0;
	switch (oper)
	{
	case '+': result = n1 + n2; break;
	case '-': result = n1 - n2; break;
	}

	return result;
}

void myprint(int n1, int n2, char oper, int result)
{
	printf("%d %c %d = %d\n", n1, oper, n2, result);
}