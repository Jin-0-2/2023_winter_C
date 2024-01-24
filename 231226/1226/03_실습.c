// 03_�ǽ�.c
/*
[���α׷� �ۼ� �ܰ�]
1. ���� ���� : ������ ������ ������ ���� (�����ϸ� �⺻������ �����Ⱑ �������)
	int(: ����(-1, 0, 1)) a(�ĺ���) ;(������ ��)
	> a��� �̸��� ������ ���� ����
2. �ʱ�ȭ    : ù��°�� ���� ����
	a = 10;
	> a��� ������ 10�� ����(����)
3. ����      : ������ �̿��� ������� ȹ�� (input�� �ʱ�ȭ �ʿ�, output)
	c = a + b; [in] a,b  [out] c
4. ������
	c�� ���? 30 printf("c�� �� -> %d\n", c); > c�� �� -> 30
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
	// ���� ����
	int a;
	int b;
	int c;

	// �ʱ�ȭ
	a = 10;
	b = 20;

	// ���� : [in]a, b  [out] c
	c = a + b;

	// ������
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

	// %lf�� .2�� �Ҽ��� 2��° �ڸ�����
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
	
	// .c(87,9): warning C4244: '=': 'double'���� 'int'(��)�� ��ȯ�ϸ鼭 �����Ͱ� �սǵ� �� �ֽ��ϴ�.
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

	c = a / b;  // c(double) = int > Ÿ�� �ȸ��� // c = 3.0;
	
	printf("%lf\n", c);
}

// ���� Ÿ��
void exam6()
{
	char a;

	a = 'A';  //�ƽ�Ű�ڵ�ǥ  --> 65�� ����

	printf("%c\n", a);  // 65 --> �ƽ�Ű�ڵ�ǥ --> 'A'
	printf("%d\n", a);  // 65

	char b;
	b = a + 1;  // b = 66;
	printf("%d , %c\n", b, b);   // 66, B

	char c; // 0 ~ 127
	c = 97; // char = int
	printf("%d , %c\n", c, c); // 97, a

	char d;
	char e;
	d = 0;    //���� 0 --> �״�� ����
	e = '0';  //���� 0 --> �ƽ�Ű�ڵ�ǥ --> 48

	printf("%d, %c", d, e);
}

// �����!
// ��� : printf
// �Է� : scanf, scanf_s(safe)
// ����ڿ��� 2���� ������ �Է¹޾� ���� ����� ����Ͻÿ�.
void exam7()
{
	int num1;
	int num2;
	int result;
	printf("���� �Է� : ");
	scanf_s("%d", &num1);

	printf("���� �Է� : ");
	scanf_s("%d", &num2);

	result = num1 + num2;

	printf("%d + %d = %d\n", num1, num2, result);
}