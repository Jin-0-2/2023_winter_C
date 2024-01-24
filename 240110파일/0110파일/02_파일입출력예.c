// 02_파일입출력예.c
#include <stdio.h>

typedef struct tagstudent
{
	char name[20];
	int kor;
	int eng;
	int mat;
}student;

void file_save()
{
	student stu[2] = { {"홍길동", 100, 90, 80},
					   {"고길동", 95, 85, 75} };

		FILE* fp;
		int  ret = fopen_s(&fp, "aaa.txt", "w");
		if (ret != 0)
		{
			printf("파일열기실패\n");
			return;
		}

		// 개수(header)
		fprintf(fp, "%d\n", 2);

		//데이터
		for (int i = 0; i < 2; i++)
		{
			fprintf(fp, "%s %d %d %d\n", stu[i].name, stu[i].kor, stu[i].eng, stu[i].mat);
		}
		

		fclose(fp);
}

void file_load()
{
	student stu[10];

	FILE* fp;
	int  ret = fopen_s(&fp, "aaa.txt", "r");
	if (ret != 0)
	{
		printf("파일열기실패\n");
		return;
	}

	int size;
	fscanf_s(fp, "%d\n", &size);

	for (int i = 0; i < size; i++)
	{
		fscanf_s(fp, "%s %d %d %d\n", stu[i].name, (int)sizeof(stu[i]).name,  &stu[i].kor, &stu[i].eng, &stu[i].mat);
	}


	for (int i = 0; i < size; i++)
	{
		fprintf(stdout, "%s %d %d %d\n", stu[i].name, stu[i].kor, stu[i].eng, stu[i].mat);
	}


	fclose(fp);
}

int main()
{
	file_save();
	file_load();

	return 0;
}
