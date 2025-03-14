// 03_구조체사용c
#include <stdio.h>

struct tagdate
{
	int year;
	int month;
	int day;
};

void date_today(int* y, int* m, int* d);
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

	date_today(&mydate.year, &mydate.month, &mydate.day);
	date_print(mydate);
	date_nextday(&mydate);
	date_print(mydate);

	return 0;
}

/*
208		d		[108]
204		m		[104]
200		y		[100]
[date_today stack]
*/
void date_today(int* y, int* m, int* d)
{
	*y = 2024;
	*m = 1;
	*d = 8;
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