// 01_����ü �ǽ�.c
/*
�л��� �̸�, �г�(1~4), ���� , ����, ����, ����� ���� ����ü����
1. ���� �Է�
2. ���� ����
3. ������ ���� ���� �� ȹ��
4. ��� ���
*/
#include <stdio.h>
#include <string.h>

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

int main()
{
	student stu;
	
	stu_create1(&stu, "ȫ�浿", 1, 90, 96, 89);		//student 1�� , int, int, int
	stu_print(&stu);

	stu = stu_create2("ȫ�浿", 1, 90, 95, 89);
	stu_print(&stu);

	stu_update_jumsu(&stu, 89, 86, 96);
	stu_print(&stu);

	stu_set_korea(&stu, 100);		// set
	int k = stu_get_korea(&stu);	// get
	stu_print(&stu);

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
	printf("%s \t %d \t %d \t %d \t %d \t %.1f\n", pstu->name, pstu->grade, pstu->kor, pstu->eng, pstu->mat, pstu->aver);
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