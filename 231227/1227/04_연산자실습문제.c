#include<stdio.h>

void exam1();
void exam2();
void exam3();
void exam4();

void main()
{
	exam4();
}

//1. ���� 2���� �Է¹޾� ���� ������ ����� ����Ͻÿ�.
//�� �������� �Ҽ��� 1�ڸ����� ����Ͻÿ�.

void exam1()
{
	int in_a, in_b, out_a;
	float out_b;
	
	printf("���� �Է� : ");
	scanf_s("%d", &in_a);
	printf("���� �Է� : ");
	scanf_s("%d", &in_b);
	printf("\n");

	out_a = in_a * in_b;
	out_b = in_a / (float)in_b;

	printf("�� ������ �� : %d\n", out_a);
	printf("�� ������ ������ : %.1f", out_b);
}

//2.  �ҹ��ڸ� �Է¹޾� �빮�ڷ� ��ȯ�Ͽ� ����Ͻÿ�.
void exam2()
{
	char in_a, out_a;

	printf("�ҹ��� �Է� : ");
	scanf_s("%c", &in_a, (int)sizeof(in_a));

	out_a = in_a - ('a' - 'A');
	printf("�빮�� ��ȯ : %c", out_a);
}

// 3. ������ �Է¹޾� ��� ���������� ����Ͻÿ�.
// ��, 1������ 30�Ϸ� ������.
void exam3()
{
	int in_a, out_a, out_b;
	printf("���� �Է� : ");
	scanf_s("%d", &in_a);
	out_a = in_a / 30;
	out_b = in_a % 30;

	printf("%d���� %d��", out_a, out_b);
}

// 4. ���� ������ �Է¹޾� ¦���� "¦��" �ƴϸ� "Ȧ��"�� ����Ͻÿ�.
// ����� = �Է��� �� % 2;
// ������� 0�̸� ¦��, 1�̸� Ȧ��(3�׿����ڸ� ����Ͽ� ����� ��� �� ��)
void exam4()
{
	unsigned int in_a;
	int out_a;

	printf("���� ���� �Է� : ");
	scanf_s("%d", &in_a);

	out_a = in_a % 2;

	printf("%s", out_a == 0 ? "¦��" : "Ȧ��");
}
