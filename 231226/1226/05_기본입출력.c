// 05_�⺻�����.c
#include <stdio.h>

void exam1();
void exam2();
void exam3();
void exam4();
void exam5();
void exam6();

void main()
{
	exam4();
}

// ����� ���(printf�� �⺻ž�� stdout, scanf�� �⺻ž�� stdin)
void exam1()
{
	// ���α׷� -> [��� ����] -> �����
	printf("Hello, World!\n");

	//stdout : ����� ��� ���
	fprintf(stdout, "Hello, World\n");
}

// ���� ��������� putchar
void exam2()
{
	char ch = 'A';
	putchar(ch); // ���
	putchar('B');
	putchar('\t'); // tab
	putchar('C');
}

// ���� ��������� getchar
void exam3()
{
	char ch1, ch2;

	ch1 = getchar();  //�Էƹ��ۿ� ���� ù��° ���� ������.
	ch2 = getchar();

	printf("%c, %c\n", ch1, ch2); // getchar(ch1);
}

// ���� ���� �Է�
// ����(\n)�� �Է� ���ڷ� ���ֵȴ�.
void exam4()
{
	char ch1, ch2;
	printf("���� �Է� : "); ch1 = getchar();
	char dummy = getchar(); // ���͸� ������

	printf("���� �Է� : "); ch2 = getchar();
	dummy = getchar(); 

	printf("\n�Է� ��� --> %c, %c\n", ch1, ch2);
}

/*
����('\n')      �����̽���(' ')    �� ('\t')
 
12 23           1223

scanf("%d[�޾Ƶ帱 ����]", &a[�ּ�])
*/
// 1��° : 10����(������ ����) 20���� : ���ʹ� �����ڷμ� �����
// 2��° : 10�����̽���20����
void exam5()
{
	int num1, num2;

	printf("����� �Է�\n");
	scanf_s("%d", &num1);
	scanf_s("%d", &num2);

	printf("�Է°�� -> %d, %d\n", num1, num2);
}

void exam6()
{
	int num1, num2;

	printf("�ѹ��� �Է�(�� : 10 20)\n");
	scanf_s("%d%d", &num1, &num2);

	printf("�Է°�� -> %d, %d\n", num1, num2);
}