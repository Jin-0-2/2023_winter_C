//00_배열.cpp

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

//push_front 알고리즘을 지원하지 않는다.(왜? 너무 비용이 많이 든다)
//push_back 만 지원한다.
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

int myarr_select(const Myarr* marr, int value)  //인덱스 반환
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

//F10 : 하나의 함수안에서 코드를 이동
//F11 : 함수 호출내부로 이동
int main()
{
	Myarr marr;

	myarr_init(&marr, 10);

	//저장
	for (int i = 0; i < 5; i++)
	{
		myarr_pushback(&marr, (i + 1) * 10);  //10, 20, 30, 40
	}

	//전체 출력
	myarr_printall(&marr);

	//검색
	int idx = myarr_select(&marr, 30);
	if (idx == -1)
		printf("없다\n");
	else
	{
		int value = marr.data[idx];
		printf("찾은 값 : %d\n", value);
	}

	//삭제
	printf("\n삭제-----------------------------\n");
	myarr_printall(&marr);
	for (int i = 0; i < 5; i++)
	{
		//myarr_frontdelete(&marr);
		myarr_backdelete(&marr);
		myarr_printall(&marr);
	}

	return 0;
}