// 01_���ڿ������ c
#include <stdio.h>

void exam1();
void exam2();
void exam3();
void exam4();
void exam5();

void main()
{
	exam2();
}

// ���ڿ� ����
void exam1()
{
	// ���� ����� ���ÿ� �ʱ�ȭ
	int num = 1;
	char ch = 'A';
	// ABC\0 ū����ǥ�� ����ϸ� �ڵ����� ���Ṯ��(\0)�� ����ȴ�.
	char arr[5] = "ABCD"; // ABCD\0
}

// ���ڿ� ���� ������Լ�
void exam2()
{
	char arr[10];  // ���� 9�� ���� + \0

	printf("���ڿ� �Է� : ");
	gets_s(arr, sizeof(arr)); // 1st : ���⿡ 2nd : �̸�ŭ�� ũ�⸦ �غ��߾�

	puts(arr);
}

// ���ڿ� ���� �Է�
void exam3()
{
	char arr1[10]; 
	char arr2[10];

	printf("���ڿ� �Է� : ");
	gets_s(arr1, sizeof(arr1));

	printf("���ڿ� �Է� : ");
	gets_s(arr2, sizeof(arr2));

	puts(arr1);
	puts(arr2);
}

// ��� Ÿ���� ����� ���� �ڵ�
void exam4()
{
	// 0������ ���� �ǹ�, 1�����̻��� �ּ��� �ǹ̸� ���´�.
	// &�����ڸ� ����ϸ� ������ 1���� ��Ų��.
	char name[20];   // [ ] -> 1���� [][] -> 2����
	int age;         // age -> 0���� &age -> 1����
	char phone[20];
	float weight;
	char gender;

	printf("��    �� : ");
	scanf_s("%s", name, (int)sizeof(name)); //'scanf_s': ���� ���ڿ��� ���� �μ��� ����ϰ� ���޵��� �ʾҽ��ϴ�. �ڸ� ǥ���� �� �ش� �Ű� �������� variadic �μ��� 2�� �ʿ������� 1���� �����Ǿ����ϴ�.
	
	printf("��    �� : ");
	scanf_s("%d", &age); 
	
	printf("��ȭ��ȣ : ");
	scanf_s("%s", phone, (int)sizeof(phone)); // phone ��ü�� �ּҶ� &�� �Ⱥ���.
	
	printf("�� �� �� : ");
	scanf_s("%f", &weight);
	char dummy = getchar(); // �Է� ���ۿ� �����ִ� ���͸� c�� �������� �Է��� ��ŵ ��. �׷��� ���� ���ֱ�
	
	printf("����(m/f): ");
	scanf_s("%c", &gender, (int)sizeof(gender));

	printf("\n[���]\n");
	printf("�̸� : %s\n", name);
	printf("���� : %d\n", age);
	printf("��ȭ��ȣ : %s\n", phone);
	printf("������ : %f\n", weight);
	printf("����(m/f): %c\n", gender);
}

// gets_s : ���ڿ� -> �������� ���ͱ���
void exam5()
{
	char name[20];   // [ ] -> 1���� [][] -> 2����
	int age;         // age -> 0���� &age -> 1����
	char phone[20];
	float weight;
	char gender;

	printf("��    �� : ");
	gets_s(name, (int)sizeof(name)); //'scanf_s': ���� ���ڿ��� ���� �μ��� ����ϰ� ���޵��� �ʾҽ��ϴ�. �ڸ� ǥ���� �� �ش� �Ű� �������� variadic �μ��� 2�� �ʿ������� 1���� �����Ǿ����ϴ�.

	printf("��    �� : ");
	scanf_s("%d", &age);

	printf("��ȭ��ȣ : ");
	gets_s(phone, (int)sizeof(phone));  // phone ��ü�� �ּҶ� &�� �Ⱥ���.
	char dummy = getchar();

	printf("�� �� �� : ");
	scanf_s("%f", & weight);
	dummy = getchar();    // �Է� ���ۿ� �����ִ� ���͸� c�� �������� �Է��� ��ŵ ��. �׷��� ���� ���ֱ�

	printf("����(m/f): ");
	scanf_s("%c", &gender, (int)sizeof(gender));

	printf("\n[���]\n");
	printf("�̸� : %s\n", name);
	printf("���� : %d\n", age);
	printf("��ȭ��ȣ : %s\n", phone);
	printf("������ : %f\n", weight);
	printf("����(m/f): %c\n", gender);
}