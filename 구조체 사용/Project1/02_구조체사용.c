// 02_����ü���.c
/*
���� ��¥�� �����ϰ� ���, ���� ��¥�� �����ϰ� ���
*/
#include <stdio.h>

// 1�ܰ�) �Լ��� ���� �� �ܰ�
/*
int main()
{
	int year;
	int month;
	int day;
	
	year = 2024;
	month = 1;
	day = 8;

	printf("%04d-%02d-%02d\n", year, month, day);

	day = 9;

	printf("%04d-%02d-%02d\n", year, month, day);

	return 0;
}
*/

// 2�ܰ�) �Լ��� ��� ��  (���� �ٲٷ��� �ּ� ����, ���� �ٲ��� ������ �� ����)
/*
void date_today(int* y, int* m, int* d);
void date_print(int y, int m, int d);
void date_nextday(int* y, int* m, int* d);
int main()
{
	int year, month, day;
	date_today(&year, &month, &day);
	date_print(year, month, day);
	date_nextday(&year, &month, &day);
	date_print(year, month, day);

	return 0;
}

void date_today(int* y, int* m, int* d)
{
	*y = 2024;
	*m = 1;
	*d = 8;
}

void date_print(int y, int m, int d)
{
	printf("%04d-%02d-%02d\n", y, m, d);
}

void date_nextday(int* y, int* m, int* d)
{
	(*d)++;
}
*/

// 3�ܰ� ����ü�� ��� �� : [��¥] ���ο� Ÿ���� ������
struct tagdate
{
	int year;
	int month;
	int day;
};

void date_today(struct tagdate* pdate);
void date_print(struct tagdate date);
void date_nextday(struct tagdate* pdate);

/*
108		mydate.day		X -> 8
104		mydate.month	X -> 1
100		mydate.year		X -> 2024
	[main stack memory]
*/
int main()
{
	struct tagdate mydate;

	date_today(&mydate);
	date_print(mydate);
	date_nextday(&mydate);
	date_print(mydate);

	return 0;
}

/*
200		pdate		[ 100 ]
[date_today stack]
*/
void date_today(struct tagdate* pdate)
{
	(*pdate).year = 2024;		// �켱������ .(��� ������)�� ���� > ��ȣ ����
	(*pdate).month = 1;
	(*pdate).day = 8;
}

/*
308		date.day		8
304		date.month		1
300		date.year		2024
[date_print]
*/
void date_print(struct tagdate date)
{
	printf("%04d-%02d-%02d\n", date.year, date.month, date.day);
}

void date_nextday(struct tagdate* pdate)
{
	(*pdate).day++;
}