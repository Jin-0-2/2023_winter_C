// 03_���ڿ�����.c
/*
���ڿ� ������ �ݵ�� �����Ǵ� ���ڿ� �Լ��� ����Ѵ�.
*/
#include <stdio.h>
#include <string.h>

void exam1();
void exam2();
void exam3();
void exam4();

int main()
{
	exam4();

	return 0;
}

// ���Կ���
void mystrcpy(char* msg1, const char* msg2)
{
	for ( ; *msg2 != '\0'; msg2++, msg1++)
	{
		*msg1 = *msg2;
	}
	*msg1 = '\0';
}

void exam1()
{
	int num1 = 10, num2;
	num2 = num1;		// ���Կ���

	char arr1[5] = "abcd";
	char arr2[5];

	//arr2 = arr1;		// �Ұ���
	mystrcpy(arr2, arr1);

	printf("%s\n", arr2);
}

// ���Կ���			: strcpy_s
// ���ڿ� �߰� ����	: strcat_s
void exam2()
{
	char str1[] = "abcd";
	char str2[10] ="ABCDEFG";

	strcpy_s(str2, sizeof(str2), str1);

	printf("%s\n", str2);

	strcat_s(str2, sizeof(str2), "���ڿ��߰�");
	printf("%s\n", str2);
}

// �񱳿���
void exam3()
{
	char str1[20] = "abcde";
	char str2[20] = "abCDEGGG";

	if (str1 == str2)
		printf("�ּҰ� �����ϴ�\n");
	else
		printf("�ּҰ� �ٸ���\n");

	// ù��° ���ڿ��� �������� �۴�(���� -1), ����(0), ũ��(��� +1)
	if (strcmp(str1, str2) == 0)
		printf("����\n");
	else
		printf("�ٸ���\n");
}

// ���ڿ��� ����� �������� ����Ʈ ũ�� : strlen
void exam4()
{
	int num;
	char arr1[10] = "abc";
	char arr2[20] = "�ѱ�";
	char arr3[30] = "abc�ѱ�";

	// sizeof : �޸� ũ�� (��� Ÿ�Կ� ��� ����)
	// 4, 10, 20, 30
	printf("%d, %d, %d, %d\n", (int)sizeof(num), (int)sizeof(arr1), (int)sizeof(arr2), (int)sizeof(arr3));

	// strlen : ���ڿ����� ��밡��
	// ���� ����Ǿ� �ִ� ���ڿ��� ũ��(���Ṯ�� ����)
	// 3, 4, 7
	printf("%d, %d, %d\n", (int)strlen(arr1), (int)strlen(arr2), (int)strlen(arr3));

}