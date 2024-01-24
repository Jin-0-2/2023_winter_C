// 01_�б⹮.c
/*
���
1) �б⹮     : if, if~else, if~else if~else if...~else (��� �б⹮ ó��) 
			    swith case (Ư�� ������ �б⹮�� ������ ����)
	���ǿ� �����ϴ� ������ �����ϰڴ�.(������ ����)

2) �ݺ���     : while      : �帧�� ���δ�.
				do while   : while�� ����ó��
				for        : �帧�� �Ⱥ��δ�. (���� ���� �����)
	������ �ݺ��ؼ� ��� ���, �����Ǹ� ����. (Ư�� ���� �ݺ� ����)

 *���� Ű���� : break, countiue
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

// if : Ư�� ������ �������� ����
//		���� : ��, ����
void exam1()
{
	int num = 11;

	// ���ǿ� �����ϸ� ���� ���� ����
	if (num == 10)
		printf("num�� 10�̴�.\n");
	printf("if���� ���� ���� �ڵ�");

	// ����, ���ǿ� �������� �� ���� ������ �����ϰ� �ʹٸ�?
	if (num == 11)
	{
		printf("����1\n");
		printf("����2\n");
	}
	
		


}

// if ~ else if : �� �� �ϳ��� ������ [�ݵ��] ����
void exam2()
{
	char gender = 'm';
	 
	if (gender == 'm')
		printf("����\n");
	else
		printf("����\n");
}

// if ~ else if ... else : ���� ���� �� �ϳ��� [�ݵ��] ����
void exam3()
{
	int age = 15;

	if (age >= 0 && age <= 9)
		printf("���̰� 9���� �۰ų� ����.\n");
	else if (age >= 10 && age <= 19)
		printf("10��\n");
	else if (age >= 20 && age <= 29)
		printf("20��\n");
	else
		printf("30�� �̻�\n");
}

// [���ǹ� ����] �� ��
// ���� 2��, �����ڸ� �Է¹޾� �ش� ������ ����� ����Ͻÿ�.
void exam4()
{
	int in_a, in_b;
	char in_c;
	float out_a;

	printf("���� �Է� : ");
	scanf_s("%d", &in_a);
	printf("���� �Է� : ");
	scanf_s("%d", &in_b);
	char dummy = getchar();
	printf("������(+, -, *, /)�Է� : ");
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
		printf("�߸��� ������ �Է�\n");
		
		return; // �Լ��� �����ϰڴ�!
	}

	printf("%d %c %d = %.1f", in_a, in_c, in_b, out_a);
}

// [���ǹ� ����] ���� ��
// ������ �Է¹޾� ������ ����Ͻÿ�.(A,B,C,D,F)
void exam5()
{
	int in_a;
	char out_a;

	printf("������ �Է� : ");		
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

	printf("���� : %c", out_a);
}

// switch ���� ���� (�� �� ���¿��� �������� ����)
// å�� �ְ� �߰��� å���Ƿ� �����ϴ� ����
void exam6()
{
	int num = 4;

	switch (num) // [�� ��]�񱳴���� ����(������ ���ڸ� ���� [�Ǽ�, ���ڿ� X])
	{
	case 1:                                //if
		printf("1������\n");
		printf("2������\n");
		break; // ���� 
	case 2:                                // if else
		printf("3������\n");
		printf("4������\n");
		printf("5������\n");
		break;
	case 3:                                // if else
		printf("6������\n");
		printf("7������\n");
		break;
	default:                               // else
		printf("�������� ����\n");
	}
	
}

//exam4�� switch������ ����
void exam7()
{
	int in_a, in_b;
	char in_c;
	float out_a;

	printf("���� �Է� : ");
	scanf_s("%d", &in_a);
	printf("���� �Է� : ");
	scanf_s("%d", &in_b);
	char dummy = getchar();
	printf("������(+, -, *, /)�Է� : ");
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
		printf("�߸��� ������ �Է�\n");
		
		return;
	}
	printf("%d %c %d = %.1f", in_a, in_c, in_b, out_a);
}