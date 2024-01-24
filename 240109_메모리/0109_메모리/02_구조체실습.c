// 2_구조체 실습.c
/*
학생의 이름, 학년(1~4), 국어 , 영어, 수학, 평균을 갖는 구조체정의
1. 정보 입력
2. 성적 수정
3. 각각의 성적 수정 및 획득
4. 결과 출력
*/
#include <stdio.h>
#include <string.h>

#define DATA_MAX 3


typedef struct tagstudent student;
struct tagstudent
{
	char name[20];
	int grade;
	int kor;
	int mat;
	int eng;
	float aver;
};

void stu_create1(student* pstu, const char* n, int g, int k, int m, int e);
student stu_create2(const char* n, int g, int k, int m, int e);
void stu_print(const student* pstu);
void stu_update_jumsu(student* pstu, int k, int m, int e);
void stu_set_korea(student* pstu, int k);
int stu_get_korea(const student* pstu);
void stu_print_all(const student* stu, int size);

int main()
{
	student stu[DATA_MAX];

	stu_create1(stu, "홍길동", 1, 90, 96, 89);		// >시작주소 첫번째학생의 주소;
	stu_create1(&stu[1], "둘리", 1, 90, 96, 89);
	stu_create1(stu+2, "고길동", 1, 90, 96, 89);
	stu_print_all(stu, DATA_MAX);
	printf("\n");

	stu[0] = stu_create2("마이클", 1, 90, 95, 89);
	stu[1] = stu_create2("또치", 1, 90, 95, 89);
	stu[2] = stu_create2("도우너", 1, 90, 95, 89);
	stu_print_all(stu, DATA_MAX);

	printf("\n");

	stu_update_jumsu(&stu[2], 89, 86, 96);
	stu_print_all(stu, DATA_MAX);

	printf("\n");
	stu_set_korea(&stu[2], 100);		// set
	int k = stu_get_korea(&stu[2]);		// get
	stu_print_all(stu, DATA_MAX);

	return 0;
}

void stu_create1(student* pstu, const char* n, int g, int k, int m, int e)
{
	strcpy_s(pstu->name, sizeof(pstu->name), n);
	pstu->grade = g;
	pstu->kor = k;
	pstu->mat = m;
	pstu->eng = e;
	pstu->aver = (k + e + m) / 3.0f;
}

student stu_create2(const char* n, int g, int k, int m, int e)
{
	student stu;
	strcpy_s(stu.name, sizeof(stu.name), n);
	stu.grade = g;
	stu.kor = k;
	stu.mat = m;
	stu.eng = e;
	stu.aver = (k + e + m) / 3.0f;

	return stu;
}

void stu_print(const student* pstu)
{
	printf("%s \t %d \t %d \t %d \t %d \t %.1f\n", pstu->name, pstu->grade, pstu->kor, pstu->mat, pstu->eng, pstu->aver);
}

void stu_update_jumsu(student* pstu, int k, int m, int e)
{
	pstu->kor = k;
	pstu->mat = m;
	pstu->eng = e;
	pstu->aver = (k + e + m) / 3.0f;
}

void stu_set_korea(student* pstu, int k)
{
	pstu->kor = k;

	pstu->aver = (pstu->kor + pstu->eng + pstu->mat) / 3.0f;
}

int stu_get_korea(const student* pstu)
{
	// int k = pstu->kor;

	return pstu->kor;
}

void stu_print_all(const student* stu, int size)
{
	for (int i = 0; i < size; i++)
	{
		stu_print(&stu[i]);
	}
}