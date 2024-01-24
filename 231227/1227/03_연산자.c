// 03_������.c
#include<stdio.h>

void exam1();
void exam2();
void exam3();
void exam4();
void exam5();
void exam6();
void exam7();
void exam8();
void exam9();

void main()
{
	exam9();
}

// ���� ����(�����ڸ� �Է¹ް� �� �������ڸ� ����Ͻÿ�.)
void exam1()
{
	char in_a;
	char out_a;

	printf("������ �Է� : ");
	scanf_s("%c", &in_a, (int)sizeof(in_a));

	out_a = in_a + 1;

	printf("������ ���ڴ� : %c\n", out_a);
}

// �����ڿ� ������ �Է¹ް� �Էµ� �����ڿ��� �Էµ� ������ŭ �̵��� ���� ���
void exam2()
{
	char in_a;
	int in_b;
	char out_a;

	printf("������ �Է� : ");
	scanf_s("%c", &in_a, (int)sizeof(in_a));
	printf("���� �Է� : ");
	scanf_s("%d", &in_b);

	out_a = in_a + in_b;
	printf("%c\n", out_a);
}

// �빮�ڸ� �Է¹޾� �ҹ��ڷ� ��ȯ�Ͻÿ�.
// ��Ʈ : A : 65 ->  a -> 97
void exam3()
{
	char in_a;
	char out_a;

	printf("�빮�� �Է� : ");
	scanf_s("%c", &in_a, (int)sizeof(in_a));
	
	out_a = in_a + ('a' - 'A');

	printf("�Է��� �빮�� : %c\n�ҹ��� ��ȯ : %c\n", in_a, out_a);
}

// ��ġ :  ���忡�� ���� ���� ����Ǵ� ����
void exam4()
{
	int a = 1;
	int b;

	// ��ġ ����
	b = ++a;    // b = 2;
	printf("%d, %d\n", a, b); // 2, 2

	a = 1;
	b = ++a + ++a;  // b = 3 + 3;
	printf("%d, %d\n", a, b); // 3, 6

	a = 1;
	b = ++a + ++a + ++a;  // b = 4 + 4 + 4;
	printf("%d, %d\n", a, b); // 4, 12
}

// ��ġ : ������ �� �� �� ����Ǵ� ����
void exam5()
{
	int a = 1;
	int b;

	// ��ġ ����
	b = a++;    // b = 1;
	printf("%d, %d\n", a, b); // 2, 1

	a = 1;
	b = a++ + a++;  // b = 1 + 1;
	printf("%d, %d\n", a, b); // 3, 2

	a = 1;
	b = a++ + a++ + a++;  // b = 1 + 1 + 1;
	printf("%d, %d\n", a, b); // 4, 3
}

void exam6()
{
	int a = 1;
	int b;

	a = 1;
	b = a++ + ++a + ++a + a++;  // b = 3 + 3 + 3 + 3
	printf("%d, %d\n", a, b); // 5, 12
}

// page 1-40(�� ����)
void exam7()
{
	int in_a = 100, in_b, out_a;

	printf("���� �Է� : ");
	scanf_s("%d", &in_b);

	out_a = (in_a == in_b);

	printf("%d", out_a);
}

// �� ������
// ����(flase)  : 0
// ��(true)     : 0�� ������ ��� ��, �� �� 1�� ��ǥ������ ���
void exam8()
{
	printf("%d\t", -100 && 200);
	printf("%d\t", !-10);

	printf("\n");
	printf("%d\t", 1 && 1);
	printf("%d\t", 1 && 0);
	printf("%d\t", 0 && 1);
	printf("%d\t", 0 && 0);

	printf("\n");
	printf("%d\t", 1 || 1);
	printf("%d\t", 1 || 0);
	printf("%d\t", 0 || 1);
	printf("%d\t", 0 || 0);

	printf("\n");
	printf("%d\t", !1);
	printf("%d\t", !0);
}

// �⼮(20), ����(20), �߰���(20), �⸻��(40)
// �� �Է��� �� �հ谡 60�̻��̰� 100�����̸� P
// �ƴϸ� F�� ����Ͻÿ�.
void exam9()
{
	int in_a, in_b, in_c, in_d;
	int out_a, out_b;

	printf("�⼮     : ");			scanf_s("%d", &in_a);
	printf("����	 : ");			scanf_s("%d", &in_b);
	printf("�߰��� : ");			scanf_s("%d", &in_c);
	printf("�⸻�� : ");			scanf_s("%d", &in_d);

	out_a = in_a + in_b + in_c + in_d;
	out_b = (out_a >= 60) && (out_a <= 100);


	printf("%s", out_b == 1 ? "P" : "F");
}