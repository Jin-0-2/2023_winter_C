// 02_�ǽ�.c
// ���� ���� -> �ʱ�ȭ -> ����(in/out) -> ��� ���

#include <stdio.h>

void exam1();
void exam2();
void exam3();
void exam4();

void main()
{
	exam4();
}

// ���� ���̸� �Է¹޾� �簢���� ���̸� ���Ͻÿ�.
void exam1()
{
	float lenght;
	float width;
	float area;

	printf("�� : "); 
	scanf_s("%f", &width);
	printf("���� : "); 
	scanf_s("%f", &lenght);

	area = lenght * width;

	printf("���̴� %f", area);
}

// ���� ���̸� �Է¹޾� �ﰢ���� ���̸� ���Ͻÿ�.
// ������ �Է¹޾� �Ǽ��� ���
// ��, �������� �ϸ� �Ǽ����� ���;���. (�Ҽ��� ���ڸ����� ��� ���)
// �ﰢ���� ���� = �� * ���� / 2; 
void exam2()
{
	int lenght;
	int width;
	float area;

	printf("�� : ");
	scanf_s("%d", &width);
	printf("���� : ");
	scanf_s("%d", &lenght);

	area = lenght * width / 2.0f;
	area = (float)lenght * width / 2;

	printf("���̴� %.1f", area);
}

// �������� ������ �Է¹޾� ���� ���̸� ���Ͻÿ�.
// ���� ���� = ������ * ������ * 3.14
// ����� �Ҽ��� ���ڸ�����
void exam3()
{
	int r;
	float area;

	printf("�������� �Է��Ͻÿ� : ");
	scanf_s("%d", &r);

	area = r * r * 3.14f;

	printf("���� ���� : %.1f", area);
}

// ��������
void exam4()
{
	char ch;

	printf("���� ���ڸ� �Է��Ͻÿ�. ��) A\n�Է� : ");
	scanf_s("%c", &ch, (int)sizeof(ch));

	printf("%d", ch);
}
