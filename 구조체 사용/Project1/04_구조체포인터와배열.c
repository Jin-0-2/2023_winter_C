// 04_구조체 포인터와 배열.c
#include <stdio.h>

struct tagdate
{
	int year;
	int month;
	int day;
};

void exam1();
void exam2();
void exam3();

int main()
{
	exam3();

	return 0;
}

void exam1()
{
	struct tagdate d1 = { 2024,1,8 };			// 12byte
	struct tagdate d2;							// 12byte

	d2 = d1;		// OK	struct tagdate = struct tagdate
	printf("%d-%d-%d\n", d2.year, d2.month, d2.day);

	d2.month = d1.month;	// OK	int = int 
}

void exam2()
{
	struct tagdate d1 = { 2024, 1, 8 };		//12byte
	struct tagdate* p;						//4byte

	p = &d1;

	printf("%d-%d-%d\n", d1.year, d1.month, d1.day);		// 값을 가진다. >  . 사용

	printf("%d-%d-%d\n", (*p).year, (*p).month, (*p).day);
	printf("%d-%d-%d\n", p->year, p->month, p->day);		// 주소를 가진다. > -> 사용
}

/*
120		days[1].day		9
116		days[1].month	2
112		days[1].year	2025
108		days[0].day		8
104		days[0].month	1
100		days[0].year	2024
*/
void exam3()
{
	struct tagdate days[2] = { {2024,1,8},
							   {2025,2,9} };

	printf("%d-%d-%d\n", days[0].year, days[0].month, days[0].day);

	struct tagdate* p1;
	struct tagdate* p2;

	p1 = days;
	p2 = days + 1;

	printf("%d, %d\n", p1[1].year, days[1].year);
}