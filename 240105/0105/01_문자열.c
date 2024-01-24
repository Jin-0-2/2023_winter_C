// 01_문자열.c
/*
문자열 : 큰따옴표로 표현 예) "abcde" -> 자동으로 마지막에 종결문자 포함
문자열은 가장 많이 사용하는 타입 -> 기본형 타입으로 제공 X
- 이유 : 크기가 가변적이다.
	     기본형타입들은 크기로 관리
		 문자열은 종결문자로 관리('\0')

- 특징 : 1차원이다. (1차원 배열을 활용하여 문자열을 관리한다.)
		 예) char arr[10];
		 // "%s" : 시작주소를 전달하면 그 위치부터 종결문자가 나올 때 까지 출력!
			 printf("%s\n", arr);			// abcde
			 printf("%s\n", arr + 2);		// cde
			 printf("%c\n", arr[0]);		// a

			 // "%s" : 문자들을 읽어들인다. (공백, 탭, 엔터)
					   마지막 문자(공백, 탭, 엔터)를 '\0'로 변경시킨다.
					   전달한 주소의 위치에 순차적으로 문자를 저장한다.
			 char arr[5];
			 scanf_s("%s", arr, (int)sizeof(arr));

			 // 마지막 문자(엔터)까지 입력받는다. \0로 추가하여 반환
			 get_s(arr, sizeof(arr));
*/

#include <stdio.h>

void exam1();
void exam2();
void exam3();

int main()
{
	exam3();

	return 0;
}

// 1. 문자열 상수
#define MSG "ABCD"
void exam1()
{
	// 정적전역공간(문자열이 저장되는 임시공간 - 상수)
	"abcde";
	MSG;

	printf("%s, %p\n", MSG, &MSG);
	printf("%s, %p\n", "ABCD", &"ABCD");
}

// 2. 포인터를 활용한 문자열 사용(Java)
/*
[static&global memeory 내(상수 문자열 임시 저장공간)]
2000 "ABCD"
3000 "ABCDE"
4000 "abcd"

[exam2 stack]
108 str3 [3000]
104 str2 [2000]
100 str1 [2000] -> [4000]
*/
void exam2()
{
	char* str1 = "ABCD";
	char* str2 = "ABCD";
	char* str3 = "ABCDE";

	printf("%s\n", str1);		// str1에는 2000번 주소가 있음 > ABCD
	printf("%s\n", str1 + 2);	// CD
	printf("%c\n", str1[2]);	// C

	// 1) 배열문자열과 다른 점 : 상수 - > 값 변경 불가능하다.
	/*str1[2] = 'c';*/				// 값 변경 불가 에러
	printf("%s\n", str1);

	// 2) 배열문자열과 다른 점 : 포인터 변수의 주소 변경 가능
	printf("%p, %p\n", str1, str2);		// 동일하다

	str1 = "abcd";
	printf("%s, %s\n", str1, str2);		// abcd, ABCD
}

// 배열을 활용한 문자열 사용(가장 일반적인 사용법)
/*
[exam3 stack]
200 arr2	"abcd"
------------------
104 arr1[4] \n
103 arr1[3] d
102 arr1[2] c
101 arr1[1] b -> B
100 arr1[0]	a
*/
void exam3()
{
	char arr1[5] = "abcd";
	char arr2[5] = { "abcd" };
	char arr3[5] = { 'a', 'b', 'c', 'd', '\0' };

	arr1[1] = 'B';
	printf("%s\n", arr1); // aBcd

	// 에러 : 배열의 이름은 상수주소
	// arr1 = "ABCD";		// 배열 문법 이해
}