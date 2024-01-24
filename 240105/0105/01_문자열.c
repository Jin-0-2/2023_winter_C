// 01_���ڿ�.c
/*
���ڿ� : ū����ǥ�� ǥ�� ��) "abcde" -> �ڵ����� �������� ���Ṯ�� ����
���ڿ��� ���� ���� ����ϴ� Ÿ�� -> �⺻�� Ÿ������ ���� X
- ���� : ũ�Ⱑ �������̴�.
	     �⺻��Ÿ�Ե��� ũ��� ����
		 ���ڿ��� ���Ṯ�ڷ� ����('\0')

- Ư¡ : 1�����̴�. (1���� �迭�� Ȱ���Ͽ� ���ڿ��� �����Ѵ�.)
		 ��) char arr[10];
		 // "%s" : �����ּҸ� �����ϸ� �� ��ġ���� ���Ṯ�ڰ� ���� �� ���� ���!
			 printf("%s\n", arr);			// abcde
			 printf("%s\n", arr + 2);		// cde
			 printf("%c\n", arr[0]);		// a

			 // "%s" : ���ڵ��� �о���δ�. (����, ��, ����)
					   ������ ����(����, ��, ����)�� '\0'�� �����Ų��.
					   ������ �ּ��� ��ġ�� ���������� ���ڸ� �����Ѵ�.
			 char arr[5];
			 scanf_s("%s", arr, (int)sizeof(arr));

			 // ������ ����(����)���� �Է¹޴´�. \0�� �߰��Ͽ� ��ȯ
			 get_s(arr, sizeof(arr));
*/

#include <stdio.h>

void exam1();
void exam2();
void exam3();

int main()
{
	exam3();

	return 0;
}

// 1. ���ڿ� ���
#define MSG "ABCD"
void exam1()
{
	// ������������(���ڿ��� ����Ǵ� �ӽð��� - ���)
	"abcde";
	MSG;

	printf("%s, %p\n", MSG, &MSG);
	printf("%s, %p\n", "ABCD", &"ABCD");
}

// 2. �����͸� Ȱ���� ���ڿ� ���(Java)
/*
[static&global memeory ��(��� ���ڿ� �ӽ� �������)]
2000 "ABCD"
3000 "ABCDE"
4000 "abcd"

[exam2 stack]
108 str3 [3000]
104 str2 [2000]
100 str1 [2000] -> [4000]
*/
void exam2()
{
	char* str1 = "ABCD";
	char* str2 = "ABCD";
	char* str3 = "ABCDE";

	printf("%s\n", str1);		// str1���� 2000�� �ּҰ� ���� > ABCD
	printf("%s\n", str1 + 2);	// CD
	printf("%c\n", str1[2]);	// C

	// 1) �迭���ڿ��� �ٸ� �� : ��� - > �� ���� �Ұ����ϴ�.
	/*str1[2] = 'c';*/				// �� ���� �Ұ� ����
	printf("%s\n", str1);

	// 2) �迭���ڿ��� �ٸ� �� : ������ ������ �ּ� ���� ����
	printf("%p, %p\n", str1, str2);		// �����ϴ�

	str1 = "abcd";
	printf("%s, %s\n", str1, str2);		// abcd, ABCD
}

// �迭�� Ȱ���� ���ڿ� ���(���� �Ϲ����� ����)
/*
[exam3 stack]
200 arr2	"abcd"
------------------
104 arr1[4] \n
103 arr1[3] d
102 arr1[2] c
101 arr1[1] b -> B
100 arr1[0]	a
*/
void exam3()
{
	char arr1[5] = "abcd";
	char arr2[5] = { "abcd" };
	char arr3[5] = { 'a', 'b', 'c', 'd', '\0' };

	arr1[1] = 'B';
	printf("%s\n", arr1); // aBcd

	// ���� : �迭�� �̸��� ����ּ�
	// arr1 = "ABCD";		// �迭 ���� ����
}