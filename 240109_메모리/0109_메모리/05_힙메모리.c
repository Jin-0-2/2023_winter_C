// 05_��(����)�޸�.c
/*
���� �̸�ŭ�� �޸𸮰� �ʿ��ѵ� �������!
���� : ������ ���� > NULL ��ȯ
	 : ������ ���� > �����ּ� ��ȯ
�ּ� = malloc(�ʿ��� ����Ʈ ũ��);
�ּ� = calloc(sizeof(int), 2);		//�ʿ��� ����Ʈ ũ�� 1st*2nd;
									//������ �޸� �ʱ�ȭ���� ����;
�� �ּҸ� ���̻� ������� ��������
free(�ּ�);
*/
#include <stdio.h>
#include <malloc.h>

void exam1();
void exam2();

int main()
{
	exam2();

	return 0;
}

/* 
1000	X-> 10
[heap]									// �޸� �� 

104		p		[1000] -> NULL
100		num		X
[stack]
*/
void exam1()
{
	//int num;		// �ٷ� ���ø޸𸮿� ����

	int* p = (int*)malloc(sizeof(int));
	if (p == NULL)
	{
		printf("�޸� ��û�� ���� ����\n");
		return;
	}

	// ���
	*p = 10;

	free(p);		// �޸� �ݳ�, ���ÿ� �ִ� p�� ������ �ּҸ� �����ִ�.
	//p = NULL;
	
	// �߸��� ���� �ڵ� -> ��������
	// *p = 20;

	//printf("%d\n", *p);
}

// ���� �迭(������ ������ �迭�� ũ�Ⱑ ���Ѵ�)
void exam2()
{
	int num;
	printf("���� : ");		scanf_s("%d", &num);
	//int arr[num];	// ����!


	// ��  : �迭 ����
	// ����: �迭 ���� �ּ�
	int* arr = malloc(sizeof(int) * num);
	if (arr == NULL)
	{
		printf("�޸� ��û�� ���� ����\n");
		return;
	}

	for (int i = 0; i < num; i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}

	free(arr);		arr = NULL;
}