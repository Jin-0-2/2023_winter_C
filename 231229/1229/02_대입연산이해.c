// 02_���Կ�������.c
/*
[���� ����?]
---------------------------
1) ���� ����
	*, [ ] : ���� 1 ����
2) ���� ���
	*, [ ] : ���� 1 ����
	&	   : ���� 1 ����
---------------------------
0��		   : �� ��ȯ
1�� �̻�   : �ּ� ��ȯ
---------------------------

int num = 1;  100����	num		1
			  num  -> 1				(int)  > 0��
			  &num -> 100����		(int*) > int�� 1����� ��

int arr[3] = {1,2,3};							108		arr[2]		3
		> ���� ���� [ ] ��� > 1��			104		arr[1]		2
												100		arr[0]		1

												arr[0]		1		(int) > 1������ ��뿡 [ ]��� > 0�� 
												&arr[0]		100		(int*)
												arr			100		(int*) > arr��� �ǹ��� ������. > 100����
*/
#include <stdio.h>

void exam1();
void exam2();
void exam3();

void main()
{
	exam2();
}

// �迭�� �ּ�
// [������Ʈ] -> [�Ӽ�] -> (�����Ӽ� -> ��Ŀ -> ���): 
// ���� �ּ�(no), �����ּ�(yes)
/*
432	arr[3]	40
428 arr[2]	30	
424 arr[1]	20
420 arr[0]	10
*/

void exam1()
{
	int arr[4] = { 10,20,30,40 };

	printf("%d\n", (int)arr);		 // int* -> �ּ� : 1703420
	printf("%d\n", (int)&arr[1]);	 // int* -> �ּ� : 1703424

	// + ������ ������
	printf("%d\n", arr[0] + 3); // 10(��) + 3     = 13
	printf("%d\n", (int)(arr + 3));	// 420(�ּ�) + 3 = 417(x) > 420 �ּҿ� + 3�� ���� �ּҰ� �����ΰ�. > 432

	// * : ������ : ���� ���� �ִ� �ּҷ� �̵�
	// arr�� + 2 ��ŭ �̵��� ������
	printf("%d\n", arr[2]);			// �� 30 (int)
	printf("%d\n", *(arr + 2));		// �� 30 (int)
}

/*
108		ppnum	104			ppnnum : 104			&ppnum : 108		*ppnum : 100		**ppnum: 10
104		pnum	100			pnu	   : 100			&pnum  : 104		*pnum  : 10
100		num		10			num    : 10				&num   :100
*/
void exam2()
{
	int num = 10;			// 0��
	int* pnum;				// ���� ���� * �� > 1�� ��! > 1��
	int** ppnum;			// ���� ���� * �� > 1�� ��! > 2��

	pnum = &num;			// int*(int�� 1��) = int > Ÿ���� �ٸ� >>> int* = int*
	ppnum = &pnum;;		// int**(int�� 2��) = int > Ÿ���� �ٸ� >> num�� &&��� �Ұ�  // int** = int**

	printf("num, pnum, ppnum�� �ּҸ� �˾ƺ���\n");
	printf("num   �ּ� : %d\n", (int)&num);					// 1703432
	printf("pnum  �ּ� : %d\n", (int)&pnum);				// 1703420
	printf("ppnum �ּ� : %d\n", (int)&ppnum);				// 1703408
	printf("num��: %d, pnum��: %d, ppnum��: %d\n", num, (int)pnum, (int)ppnum); // 10, 1703432, 1703420
	printf("%d, %d, %d\n", num, *pnum, (int)*ppnum);  // 10, 10, 10

	// *ppnum = &num;		//int* = int*
}

void exam3()
{
	int arr[5] = { 10, 20, 30, 40, 50 };		// arr�� 100���� ����.
	int* p1 = arr;			// int* = int*
	int* p2 = arr + 2;		// int* = int*

	printf("%d\n", *(p1 + 2));		// 30
	printf("%d\n", p1[2]);			// 30
	printf("%d, %d\n", *(arr + 2), arr[2]); // 30, 30

	printf("%d\n", *p2);			// 30
	printf("%d\n", *(p2 + 2));		// 50
	printf("%d\n", *(p2 - 2));		// 10
	printf("%d\n", p2[2]);			// 50
	printf("%d\n", p2[-2]);			// 10

	printf("%d\n", *p2 + 2);		// 32
	printf("%d\n", *(p2 + 2));		// 116���� * -> 50
}