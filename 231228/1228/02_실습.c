// 02_�ǽ�.c
#include <stdio.h>

void exam1();
void exam2();
void exam3();
void exam4();


void main()
{
	exam4();
}

// 1) ���� ������ �Է��� �� ¦���� ��even number��, Ȧ���� ��odd number�� ���
// (��Ʈ : ������ �������� ����� 0�̸� ¦��, 1�̸� Ȧ�� ��)
// ��� ��) ���� : 3
// 3�� odd number
void exam1()
{
	unsigned int in_a;
	int out_a;

	printf("���� ���� �Է� : ");
	scanf_s("%d", &in_a);

	out_a = in_a % 2;

	if (out_a == 0)
		printf("%d��(��) even number", in_a);
	else
		printf("%d��(��) odd  number", in_a);

}

// 2) ���ĺ� �� ���ڸ� �Է��� �� �ҹ����̸� �빮�ڷ�, �빮���̸� �ҹ��ڷ� ��ȯ�Ͽ� ���
// ��� ��) ���ĺ� �Է� : a
// ���ĺ� ��ȯ : A

void exam2()
{
	char in_a, out_a;

	printf("���ĺ� �Է� : ");
	scanf_s("%c", &in_a, (int)sizeof(in_a));

	if (in_a >= 65 && in_a <= 90)
		out_a = in_a + 32;
	else if (in_a >= 97 && in_a <= 122)
		out_a = in_a - 32;
	else
	{
		printf("�߸��Է��ϼ̽��ϴ�.");
		
		return;
	}

	printf("���ĺ� ��ȯ : %c", out_a);
}


//3) ��¿�)�� �´� 4Ģ������ �ϼ��Ͻÿ�.
//��¿�) 
// ====================================================
//1. ���ϱ�           2. ��  ��            3. ���ϱ�             4. ������
//====================================================
//�����ϼ���[1]
//ù��° �� : 5
//�ι�° �� : 7
//�� ���� �� = 12

void exam3()
{
	char ch_a;
	float in_a, in_b, out_a;

	printf("=============================================\n");
	printf("1. ���ϱ� \t2. ���� \t3. ���ϱ� \t 4. ������\n");
	printf("=============================================\n");
	printf("�����ϼ��� : ");
	scanf_s("%c", &ch_a, (int)sizeof(char));
	char dummy = getchar();
	printf("ù��° ��: ");
	scanf_s("%f", &in_a);
	printf("�ι�° ��: ");
	scanf_s("%f", &in_b);

	if (ch_a == '1')
	{
		out_a = in_a + in_b;
		printf("�� ���� ���� : %.1f", out_a);
	}
	else if (ch_a == '2')
	{
		out_a = in_a - in_b;
		printf("�� ���� ���� : %.1f", out_a);
	}
	else if (ch_a == '3')
	{
		out_a = in_a * in_b;
		printf("�� ���� ���� : %.1f", out_a);
	}	
	else if (ch_a == '4')
	{
		out_a = in_a / in_b;
		printf("�� ���� ������ : %.1f", out_a);
	}
	else
	{
		printf("�߸� �Է��Ͽ����ϴ�.");
		
		return;
	}
}

// 2���� �� �Է��� �� ū ���� ���
void exam4()
{
	float in_a, in_b, out_a;

	printf("�� �Է� : ");
	scanf_s("%f", &in_a);
	printf("�� �Է� : ");
	scanf_s("%f", &in_b);

	out_a = in_a - in_b;

	if (out_a > 0)
		printf("%.1f", in_a);
	else if (out_a < 0)
		printf("%.1f", in_b);
	else
	{
		printf("�� ���� �����ϴ�.");

		return;
	}
}