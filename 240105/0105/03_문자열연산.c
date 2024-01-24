// 03_문자열연산.c
/*
문자열 연산은 반드시 제공되는 문자열 함수를 사용한다.
*/
#include <stdio.h>
#include <string.h>

void exam1();
void exam2();
void exam3();
void exam4();

int main()
{
	exam4();

	return 0;
}

// 대입연산
void mystrcpy(char* msg1, const char* msg2)
{
	for ( ; *msg2 != '\0'; msg2++, msg1++)
	{
		*msg1 = *msg2;
	}
	*msg1 = '\0';
}

void exam1()
{
	int num1 = 10, num2;
	num2 = num1;		// 대입연산

	char arr1[5] = "abcd";
	char arr2[5];

	//arr2 = arr1;		// 불가능
	mystrcpy(arr2, arr1);

	printf("%s\n", arr2);
}

// 대입연산			: strcpy_s
// 문자열 추가 연산	: strcat_s
void exam2()
{
	char str1[] = "abcd";
	char str2[10] ="ABCDEFG";

	strcpy_s(str2, sizeof(str2), str1);

	printf("%s\n", str2);

	strcat_s(str2, sizeof(str2), "문자열추가");
	printf("%s\n", str2);
}

// 비교연산
void exam3()
{
	char str1[20] = "abcde";
	char str2[20] = "abCDEGGG";

	if (str1 == str2)
		printf("주소가 동일하다\n");
	else
		printf("주소가 다르다\n");

	// 첫번째 문자열을 기준으로 작다(음수 -1), 같다(0), 크다(양수 +1)
	if (strcmp(str1, str2) == 0)
		printf("같다\n");
	else
		printf("다르다\n");
}

// 문자열에 저장된 데이터의 바이트 크기 : strlen
void exam4()
{
	int num;
	char arr1[10] = "abc";
	char arr2[20] = "한글";
	char arr3[30] = "abc한글";

	// sizeof : 메모리 크기 (모든 타입에 사용 가능)
	// 4, 10, 20, 30
	printf("%d, %d, %d, %d\n", (int)sizeof(num), (int)sizeof(arr1), (int)sizeof(arr2), (int)sizeof(arr3));

	// strlen : 문자열에만 사용가능
	// 실제 저장되어 있는 문자열의 크기(종결문자 제외)
	// 3, 4, 7
	printf("%d, %d, %d\n", (int)strlen(arr1), (int)strlen(arr2), (int)strlen(arr3));

}