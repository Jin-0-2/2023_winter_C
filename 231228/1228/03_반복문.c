// 03_�ݺ���.c
/*
Ư�� ������ �ݺ��ؼ� ����
����1) Ƚ���� ���س��´�.
����2) Ư�� ������ ������ �� ����
*/
#include <stdio.h>

void exam1();
void exam2();
void exam3();
void exam4();
void exam5();
void exam6();
void exam7();
void exam8(); // ����1)
void exam9();
void exam10();
void exam11();
void exam12();
void exam12();
void exam13();
void exam14();
void exam15();
void exam16();
void exam17();
void exam18();
void exam19();
void exam20();
void exam21();



void main()
{
	exam20();
}

// [while]Hello, World�� 5�� ���
// Ƚ�� count ���� �ʿ� 1) �ʱ�ȭ 2) �ݺ��� �� ���� ���� 3) ��� �ݺ����� ���θ� �Ǵ�.
void exam1()
{
	int i = 0;  // 1) �ʱ�ȭ

	while ( i < 5 )	// 2) ���ǿ� �����ϸ� �ݺ�
	{
		// �ϰ��� �ϴ� ��
		printf("Hello, World!\n");

		i++;  // 3) ����
	}
}

// ������ 3�� �Է� �����ÿ�.
void exam2()
{
	int in_a;
	int i = 0;

	while (i < 3)
	{
		printf("���� �Է� : ");
		scanf_s("%d", &in_a);

		i++;
	}
}

// 1���� 10���� ���ڸ� ��� �Ͻÿ�.
void exam3()
{
	int i = 1; 

	while (i < 11)
	{
		printf("%d\n", i);

		i++; 
	}
}

// 1���� 100���� ������ ���� ����Ͻÿ�.
void exam4()
{
	int i = 1, sum = 0;

	while (i < 101)
	{
		sum = sum + i;

		i++;
	}

	printf("�� : %d", sum);
}

// 1���� 100���� ���� �� ¦���� ���� ����Ͻÿ�
void exam5()
{
	int i = 1, sum = 0;

	// ��� 1)
	while (i < 101)
	{
		if(i%2 == 0)
			sum = sum + i;

		i++;
	}
	printf("�� : %d\n", sum);

	// ��� 2)
	i = 2;
	sum = 0;
	while (i < 101)
	{
		sum = sum + i;

		i = i + 2;
	}

	printf("�� : %d\n", sum);
}

// 10���� 1���� ����Ͻÿ�.
void exam6()
{
	int i = 10; 

	while (i > 0)
	{
		printf("%2d", i);

		i--;
	}
}

// �빮�� A���� Z���� ����Ͻÿ�.
void exam7()
{
	char c = 'A';

	while ( c <= 'Z' )
	{
		printf("%2c", c);

		c++;
	}
}

// ������ �� 5���� ����Ͻÿ�.
void exam8()
{
	int i = 1; 

	while (i < 10)
	{
		printf("%d * %d = %d\n", 5, i, 5 * i);

		i++;
	}
}

// [������ ������ �� ����] -1�� �Է��� ������ �Է��� ��
void exam9()
{
	int num;

	// ���ѷ���
	while (1)
	{
		printf("���� �Է� : ");
		scanf_s("%d", &num);

		if (num == -1)
			break;
	}
}

// -1�� �Է��� ������ ���� ���Ͻÿ�.
void exam10()
{
	int num, sum = 0;

	
	while (1)
	{
		printf("���� �Է� : ");
		scanf_s("%d", &num);
		
		if (num == -1)
			break;

		sum = sum + num;
	}

	printf("���� ��� : %d", sum);
}

void exam11()
{
	int i;

	for (i = 0; i < 5; i++)		// �ʱ�ȭ ; ���� 
	{
		printf("Hello, World!\n");
	}
}

void exam12()
{
	int in_a;

	for (int i = 0; i < 3; i++)
	{
		printf("���� �Է� : ");
		scanf_s("%d", &in_a);
	}
}

void exam13()
{
	for (int i = 1; i < 11; i++)
	{
		printf("%d\n", i);
	}
}

void exam14()
{
	int sum = 0;

	for (int i = 1; i < 101 ; i++)
	{
		sum = sum + i;
	}

	printf("�� : %d", sum);
}

void exam15()
{
	int sum = 0;

	// ��� 1)
	for (int i = 1; i < 101; i++)
	{
		if (i % 2 == 0)
			sum = sum + i;
	}

	printf("�� : %d\n", sum);

	// ��� 2)
	sum = 0;

	for (int i = 2; i < 101; i = i + 2)
	{
		if(i%2==0)
			sum = sum + i;
		
	}
	printf("�� : %d\n", sum);

}

void exam16()
{
	for (int i = 10; i > 0; i--)
	{
		printf("%2d", i);
	}
}

void exam17()
{
	for (char c = 'A'; c <= 'Z'; c++)
	{
		printf("%2c", c);
	}
}

void exam18()
{
	for (int i = 1; i < 10; i++)
	{
		printf("%d * %d = %d\n", 5, i, 5 * i);
	}
}

void exam19()
{
	int num;

	for (;;)
	{
		printf("���� �Է� : ");
		scanf_s("%d", &num);

		if (num == -1)
			break;
	}
		
}

void exam20()
{
	int num, sum = 0;

	for (;;)
	{
		printf("���� �Է� : ");
		scanf_s("%d", &num);

		sum = sum + num;

		if (num == -1)
			break;
	}
	printf("���� ��� : %d", sum);
}

// continue
void exam21()
{
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0) // ¦���� ��
			continue;   // ���� ������ ���� x

		printf("%2d", i);
	}
}