// 04_�ǽ�.c
#include <stdio.h>

void exam1();
void exam2();
void exam3();
void exam4();
void exam4();
void exam5();
void exam6();

void main()
{
	exam5();
}


// 1) ����ڷκ��� ���ڸ� �Է� �޾�, �� ����ŭ ��Hello, World!�� �� ����Ͻÿ�.
void exam1()
{
	int in_a;

	printf("�ݺ��� Ƚ�� �Է�: ");
	scanf_s("%d", &in_a);

	for (int i = 0; i < in_a; i++)
	{
		printf("Hello, World!\n");
	}
}

// 2) ���ĺ� �ҹ��ڸ� a~z���� ������� ����Ͻÿ�.
void exam2()
{
	for (char c = 'a'; c <= 'z'; c++)
	{
		printf("%2c", c);
	}
}

// 3) ���� ��X�� �� ��x�� �� �Է��� �� ���� ����ؼ� ���ڸ� �Է¹޾� ȭ�鿡 ����Ͻÿ�. 
void exam3()
{
	
	for (char c;;)
	{
		printf("���� �Է�(X or x �Է½� ��): ");
		scanf_s("%c", &c, (int)sizeof(char));
		char dummy = getchar();

		if (c == 'X' || c == 'x')
			break;
	}
}

// 4) ������ �ܼ��� �Է¹޾� �ش� �������� ����Ͻÿ�. ��, ������ �ܼ��� 0�� �Է��� 
// ������ ���  ����ڰ� ���ϴ� �������� �ݺ��ؼ� ����� ��
void exam4()
{
	int in_a;

	for (;;)
	{
		printf("������ �ܼ� �Է�(��, 0�Է½� ����): ");
		scanf_s("%d", &in_a);

		if (in_a == 0)               // Ż���� ��ġ > if ���� for�� ���� �Ʒ��� ��ġ�ϸ� 0�� ���� ������ ���� ������ Ż���� 0�Է½� �����Ϸ��� �ǵ��� ���� ����.
		{
			break;
		}

		for (int i = 1; i < 10; i++)
			{
				printf("%d * %d = %d\n", in_a, i, in_a * i);
			}
	}
}

// 5) -1�� �Է��� ������ ������ ��� �Է��ϰ�, �Է��� ���� �հ� ����� ����Ͻÿ�. 
void exam5()
{
	int num, sum = 0, i = 0;
	float aver;

	for (;;)
	{
		printf("���� �Է� : ");
		scanf_s("%d", &num);

		if (num == -1)  // Ż���� ��ġ > -1�� ������ Ż���ε� sum ���� �Ʒ��� ��ġ�ϸ� -1���� ���Ͽ��� ����� �� �������� ���� ������ �� �� ����.
			break;

		sum = sum + num;
		
		i++;
		
	}
	aver = sum / (float)i;

	printf("�� ���: %d\n", sum);
	printf("��� ��: %.1f\n", aver);
}

// ȭ�� �µ��� ���� �µ��� ȯ���Ͽ� ����Ͻÿ�. 
// ��, 0������ 100������ 10�� ������ 10���� �µ��� ����Ͻÿ�.
// (�����µ� = 5 / 9 * (ȭ���µ� - 32)) * Ÿ�Կ� ���� �Ұ�, ����� �Ǽ��� ����
void exam6()
{
	for (int hwa = 0; hwa < 101; hwa = hwa + 10)
	{
		printf("ȭ�� �µ�: %d >> ���� �µ�: %.3f\n", hwa, (float)5 / 9 * (hwa - 32));  
		//  5 / 9 * ((float)hwa - 32) > 0�� ���� ���� ������� ���� 5(int) / 9(int)�� ������� 0�� ���� hwa�� float�� �ٿ����� ���ϴ� ���� 0�̱� ������ �ȵ�.
	}
}