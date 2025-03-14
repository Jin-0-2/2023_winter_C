//00_�迭.cpp

#include <stdio.h>
#include <malloc.h>

typedef struct tagMyArr Myarr;
struct tagMyArr
{
	int *data;
	int max;
	int size;
};

void myarr_init(Myarr* marr, int max)
{
	marr->data	= (int*)malloc(sizeof(int) * max);		//#include <malloc.h>
	marr->max	= max;
	marr->size	= 0;
}

//push_front �˰����� �������� �ʴ´�.(��? �ʹ� ����� ���� ���)
//push_back �� �����Ѵ�.
int myarr_pushback(Myarr* marr, int value)
{
	if (marr->max <= marr->size)
		return 0;

	marr->data[marr->size] = value;
	marr->size++;

	return 1;
}

void myarr_printall(const Myarr* marr)
{
	for (int i = 0; i< marr->size; i++)
	{
		int value = marr->data[i];
		printf("%3d", value);
	}
	printf("\n");
}

int myarr_select(const Myarr* marr, int value)  //�ε��� ��ȯ
{
	for (int i = 0; i < marr->size; i++)
	{
		int d = marr->data[i];
		if (d == value)
			return i;
	}
	return -1;
}

int myarr_frontdelete(Myarr* marr)
{
	if (marr->size == 0)
		return 0;

	for (int i = 0;  i< (marr->size) -1; i++)
	{
		marr->data[i] = marr->data[i + 1];
	}
	marr->size--;
	return 1;
}

int myarr_backdelete(Myarr* marr)
{
	if (marr->size == 0)
		return 0;

	marr->size--;
	return 1;
}

//F10 : �ϳ��� �Լ��ȿ��� �ڵ带 �̵�
//F11 : �Լ� ȣ�⳻�η� �̵�
int main()
{
	Myarr marr;

	myarr_init(&marr, 10);

	//����
	for (int i = 0; i < 5; i++)
	{
		myarr_pushback(&marr, (i + 1) * 10);  //10, 20, 30, 40
	}

	//��ü ���
	myarr_printall(&marr);

	//�˻�
	int idx = myarr_select(&marr, 30);
	if (idx == -1)
		printf("����\n");
	else
	{
		int value = marr.data[idx];
		printf("ã�� �� : %d\n", value);
	}

	//����
	printf("\n����-----------------------------\n");
	myarr_printall(&marr);
	for (int i = 0; i < 5; i++)
	{
		//myarr_frontdelete(&marr);
		myarr_backdelete(&marr);
		myarr_printall(&marr);
	}

	return 0;
}