//01_����ü��?
/*
����ڰ� ����� ������ [Ÿ��] : ����Ÿ��

Ÿ�� Ű������ �ǹ� : ������?               � ũ���?
		int           ����                 4byte  sizeof(int)
  struct �±׸�     (����,����,
					 �Ǽ��ּ�,����5���迭) 14byte sizeof(struct �±׸�)

1) ����ü ���� --> Ÿ�� ���� ==> ���� ����(�ڵ尡 �ƴ�)
struct �±׸�
{
	int num;		//4
	char ch;		//1
	float *pf;		//4
	char arr[5];	//5
};

2) ���� ���� --> int�� ���ؼ� �� �� �ִ� ��� ������ ������� �����ϰ�

3) �޸� ���� --> �޸� ���� ��� ����
*/
#include <stdio.h>

//����ü ����  
struct tagdata
{
	int num1;
	char ch;
};

void exam1();

int main()
{
	exam1();

	return 0;
}

//���� ���� �� �޸�
/*
108    data.ch       A
104    data.num1     20
100    num           10
*/
void exam1()
{
	int num = 10;
	struct tagdata  data = { 20, 'A' };

	printf("%d\n", num);		//10
	printf("%d\n", data.num1);	//20
	printf("%c\n", data.ch);	//A 

	//Ÿ��?
	/*
	num  : int      10          &num : int*    100
	data : struct tagdata ?    &data : struct tagdata*   104
	data.num1 : int   20        &data.num1 : int*        104
	data.ch   : char  A        &(data.ch) : char*        108
	*/
}
