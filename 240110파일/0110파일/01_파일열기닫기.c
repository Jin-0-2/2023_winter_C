// 01_파일 열기 닫기.c

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void exam1();
void exam2();
void exam3();
void exam4();
void exam5();
void exam6();
void exam7();
void exam8();
void exam9();

int main()
{
	exam8();
	
	return 0;
}

// 파일 열기와 모드 : fopen, fopen_s
/*
w : 쓰기 - 무조건 성공 (파일X -> 생성), if (파일 O -> 파일내용 초기화)
a : 쓰기 - 무조건 성공 (파일X -> 생성), if (파일 O -> 파일내용 유지)
r : 읽기 -		       (파일X -> 오류), if (파일 O -> 성공)
*/
void exam1()
{
	FILE* fp;
//	fp = fopen("aaa.txt", "w");
	int  ret = fopen_s(&fp, "aaa.txt", "r");
	if (ret != 0)
	{
		printf("파일열기실패\n");
		return;
	}
	fclose(fp);
}

//문자 기반 출력 : putc()
void exam2()
{
	FILE* fp;
	int  ret = fopen_s(&fp, "aaa.txt", "w");
	if (ret != 0)
	{
		printf("파일열기실패\n");
		return;
	}

	putc('A', stdout);	//putchar('A')
	putc('A', fp);
	putc('C', fp);
	putc('D', fp);
	putc('E', fp);
	putc('\n', fp);		// '\r'(코드 줄 시작으로 이동) + '\w'(아래로 한칸 이동) 그래서 6byte가 아니라 7byte로 저장
	putc('f', fp);

	fclose(fp);
}

//문자 기반 입력 : getc()
void exam3()
{
	FILE* fp;
	int  ret = fopen_s(&fp, "aaa.txt", "r");
	if (ret != 0)
	{
		printf("파일열기실패\n");
		return;
	}

	//char ch = getc(stdin);		// 키보드 
	char ch = getc(fp);	// A
	ch = getc(fp); // C 자동으로 이동

	putchar(ch);				// 화면

	fclose(fp);
}

// [읽기]01_파일열기닫기.c
// [쓰기]01_복사.txt
void exam4()
{
	FILE* rfp, *wfp;
	int  ret = fopen_s(&rfp, "01_파일열기닫기.c", "r");
	if (ret != 0)
	{
		printf("파일열기실패\n");
		return;
	}

	ret = fopen_s(&wfp, "01_복사.txt", "w");
	if (ret != 0)
	{
		printf("파일열기실패\n");
		return;
	}

	char ch;
	while ((ch = getc(rfp)) != -1)		// EOf (-1)
	{
		// putc(ch, stdout);
		putc(ch, wfp);
	}
	
	fclose(rfp);
	fclose(wfp);
}

// 문자열 출력 : fputs()
void exam5()
{
	FILE* fp;
	int  ret = fopen_s(&fp, "aaa.txt", "w");
	if (ret != 0)
	{
		printf("파일열기실패\n");
		return;
	}

	fputs("abcdef\n", fp);
	fputs("ABCDEF\n", fp);

	fclose(fp);
}

// 문자열 읽기 : fgets()
// 한 줄을 읽어온다. 
// 만약 버파사이즈가 적다면 ? 일부만 읽어온다.
void exam6()
{
	FILE* fp;
	int  ret = fopen_s(&fp, "aaa.txt", "r");
	if (ret != 0)
	{
		printf("파일열기실패\n");
		return;
	}

	char buf[512];
	fgets(buf, sizeof(buf), fp);
	fgets(buf, sizeof(buf), fp);

	puts(buf);

	fclose(fp);
}

// 문자열 기반 파일 복사
void exam7()
{
	FILE* rfp, * wfp;
	int  ret = fopen_s(&rfp, "01_파일열기닫기.c", "r");
	if (ret != 0)
	{
		printf("파일열기실패\n");
		return;
	}

	ret = fopen_s(&wfp, "01_복사.txt", "w");
	if (ret != 0)
	{
		printf("파일열기실패\n");
		return;
	}

	char buf[512];
	while (fgets(buf, sizeof(buf), rfp) != NULL)		// EOF  (NULL)
	{
		fputs(buf, wfp);		// putc(ch, stdout);
	}

	fclose(rfp);
	fclose(wfp);
}

// 서식기반 : fprintf()
void exam8()
{
	FILE* fp;
	int  ret = fopen_s(&fp, "aaa.txt", "w");
	if (ret != 0)
	{
		printf("파일열기실패\n");
		return;
	}

	printf("%s %d %c %f\n", "홍길동", 12, 'm', 10.123f);
	fprintf(stdout, "%s %d %c %f\n", "홍길동", 12, 'm', 10.123f);
	fprintf(fp, "%s %d %c %f\n", "홍길동", 12, 'm', 10.123f);
	fprintf(fp, "%s %d %c %f\n", "고길동", 13, 'm', 15.123f);

	fclose(fp);
}

void exam9()
{
	FILE* fp;
	int  ret = fopen_s(&fp, "aaa.txt", "r");
	if (ret != 0)
	{
		printf("파일열기실패\n");
		return;
	}

	char name[20];
	int age;
	char gender;
	float weight;

	fscanf_s(fp, "%s %d %c %f", name, (int)sizeof(name), &age, &gender, (int)sizeof(gender), &weight);

	fscanf_s(fp, "%s %d %c %f", name, (int)sizeof(name), &age, &gender, (int)sizeof(gender), &weight);

	fscanf_s(fp, "%s", name, (int)sizeof(name));
	fscanf_s(fp, "%d", &age);

	char dummy = getc(fp);
	// fscanf_s(fp, "%c", &dummy, (int)sizeof(dummy));

	fscanf_s(fp, "%c", &gender, (int)sizeof(gender));
	fscanf_s(fp, "%f", &weight);

	printf("%s, %d, %c, %f\n", name, age, gender, weight);

	fclose(fp);
}