// 01_���� ���� �ݱ�.c

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

// ���� ����� ��� : fopen, fopen_s
/*
w : ���� - ������ ���� (����X -> ����), if (���� O -> ���ϳ��� �ʱ�ȭ)
a : ���� - ������ ���� (����X -> ����), if (���� O -> ���ϳ��� ����)
r : �б� -		       (����X -> ����), if (���� O -> ����)
*/
void exam1()
{
	FILE* fp;
//	fp = fopen("aaa.txt", "w");
	int  ret = fopen_s(&fp, "aaa.txt", "r");
	if (ret != 0)
	{
		printf("���Ͽ������\n");
		return;
	}
	fclose(fp);
}

//���� ��� ��� : putc()
void exam2()
{
	FILE* fp;
	int  ret = fopen_s(&fp, "aaa.txt", "w");
	if (ret != 0)
	{
		printf("���Ͽ������\n");
		return;
	}

	putc('A', stdout);	//putchar('A')
	putc('A', fp);
	putc('C', fp);
	putc('D', fp);
	putc('E', fp);
	putc('\n', fp);		// '\r'(�ڵ� �� �������� �̵�) + '\w'(�Ʒ��� ��ĭ �̵�) �׷��� 6byte�� �ƴ϶� 7byte�� ����
	putc('f', fp);

	fclose(fp);
}

//���� ��� �Է� : getc()
void exam3()
{
	FILE* fp;
	int  ret = fopen_s(&fp, "aaa.txt", "r");
	if (ret != 0)
	{
		printf("���Ͽ������\n");
		return;
	}

	//char ch = getc(stdin);		// Ű���� 
	char ch = getc(fp);	// A
	ch = getc(fp); // C �ڵ����� �̵�

	putchar(ch);				// ȭ��

	fclose(fp);
}

// [�б�]01_���Ͽ���ݱ�.c
// [����]01_����.txt
void exam4()
{
	FILE* rfp, *wfp;
	int  ret = fopen_s(&rfp, "01_���Ͽ���ݱ�.c", "r");
	if (ret != 0)
	{
		printf("���Ͽ������\n");
		return;
	}

	ret = fopen_s(&wfp, "01_����.txt", "w");
	if (ret != 0)
	{
		printf("���Ͽ������\n");
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

// ���ڿ� ��� : fputs()
void exam5()
{
	FILE* fp;
	int  ret = fopen_s(&fp, "aaa.txt", "w");
	if (ret != 0)
	{
		printf("���Ͽ������\n");
		return;
	}

	fputs("abcdef\n", fp);
	fputs("ABCDEF\n", fp);

	fclose(fp);
}

// ���ڿ� �б� : fgets()
// �� ���� �о�´�. 
// ���� ���Ļ���� ���ٸ� ? �Ϻθ� �о�´�.
void exam6()
{
	FILE* fp;
	int  ret = fopen_s(&fp, "aaa.txt", "r");
	if (ret != 0)
	{
		printf("���Ͽ������\n");
		return;
	}

	char buf[512];
	fgets(buf, sizeof(buf), fp);
	fgets(buf, sizeof(buf), fp);

	puts(buf);

	fclose(fp);
}

// ���ڿ� ��� ���� ����
void exam7()
{
	FILE* rfp, * wfp;
	int  ret = fopen_s(&rfp, "01_���Ͽ���ݱ�.c", "r");
	if (ret != 0)
	{
		printf("���Ͽ������\n");
		return;
	}

	ret = fopen_s(&wfp, "01_����.txt", "w");
	if (ret != 0)
	{
		printf("���Ͽ������\n");
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

// ���ı�� : fprintf()
void exam8()
{
	FILE* fp;
	int  ret = fopen_s(&fp, "aaa.txt", "w");
	if (ret != 0)
	{
		printf("���Ͽ������\n");
		return;
	}

	printf("%s %d %c %f\n", "ȫ�浿", 12, 'm', 10.123f);
	fprintf(stdout, "%s %d %c %f\n", "ȫ�浿", 12, 'm', 10.123f);
	fprintf(fp, "%s %d %c %f\n", "ȫ�浿", 12, 'm', 10.123f);
	fprintf(fp, "%s %d %c %f\n", "��浿", 13, 'm', 15.123f);

	fclose(fp);
}

void exam9()
{
	FILE* fp;
	int  ret = fopen_s(&fp, "aaa.txt", "r");
	if (ret != 0)
	{
		printf("���Ͽ������\n");
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