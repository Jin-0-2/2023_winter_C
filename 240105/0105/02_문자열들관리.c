// 02_���ڿ��� ����
#include <stdio.h>

void exam1();

int main()
{
	exam1();

	return 0;
}

// �迭�� �̿��Ͽ� �������� ������ ������ �� �ִ�.
void exam1()
{
	int age[3] = { 10, 20,30 };

	// 3 : ���ڿ��� ����
	// 10 : �ϳ��� ���ڿ�ũ��(����1, �ѱ�2)
	char name[3][10] = { "ȫ�浿", 
						 "��浿", 
						 "�̱浿" };

	// ù��° ����� ����
	printf("%d\n", age[0]);
	printf("%s\n", name[0]);

	// �ι�° ����� ����
	printf("%d\n", age[1]);
	printf("%s\n", name[1]);
}