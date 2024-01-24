// 01_문자열입출력 c
#include <stdio.h>

void exam1();
void exam2();
void exam3();
void exam4();
void exam5();

void main()
{
	exam2();
}

// 문자열 선언
void exam1()
{
	// 변수 선언과 동시에 초기화
	int num = 1;
	char ch = 'A';
	// ABC\0 큰따옴표를 사용하면 자동으로 종결문자(\0)가 저장된다.
	char arr[5] = "ABCD"; // ABCD\0
}

// 문자열 전용 입출력함수
void exam2()
{
	char arr[10];  // 문자 9개 저장 + \0

	printf("문자열 입력 : ");
	gets_s(arr, sizeof(arr)); // 1st : 여기에 2nd : 이만큼의 크기를 준비했어

	puts(arr);
}

// 문자열 연속 입력
void exam3()
{
	char arr1[10]; 
	char arr2[10];

	printf("문자열 입력 : ");
	gets_s(arr1, sizeof(arr1));

	printf("문자열 입력 : ");
	gets_s(arr2, sizeof(arr2));

	puts(arr1);
	puts(arr2);
}

// 모든 타입의 입출력 최종 코드
void exam4()
{
	// 0차원은 값의 의미, 1차원이상은 주소의 의미를 갖는다.
	// &연산자를 사용하면 차수를 1증가 시킨다.
	char name[20];   // [ ] -> 1차원 [][] -> 2차원
	int age;         // age -> 0차원 &age -> 1차원
	char phone[20];
	float weight;
	char gender;

	printf("이    름 : ");
	scanf_s("%s", name, (int)sizeof(name)); //'scanf_s': 서식 문자열에 대한 인수가 충분하게 전달되지 않았습니다. 자리 표시자 및 해당 매개 변수에는 variadic 인수가 2개 필요하지만 1개가 제공되었습니다.
	
	printf("나    이 : ");
	scanf_s("%d", &age); 
	
	printf("전화번호 : ");
	scanf_s("%s", phone, (int)sizeof(phone)); // phone 자체가 주소라서 &를 안붙임.
	
	printf("몸 무 게 : ");
	scanf_s("%f", &weight);
	char dummy = getchar(); // 입력 범퍼에 남아있는 엔터를 c가 가져가서 입력이 스킵 됨. 그래서 엔터 빼주기
	
	printf("성별(m/f): ");
	scanf_s("%c", &gender, (int)sizeof(gender));

	printf("\n[출력]\n");
	printf("이름 : %s\n", name);
	printf("나이 : %d\n", age);
	printf("전화번호 : %s\n", phone);
	printf("몸무게 : %f\n", weight);
	printf("성별(m/f): %c\n", gender);
}

// gets_s : 문자열 -> 공백포함 엔터까지
void exam5()
{
	char name[20];   // [ ] -> 1차원 [][] -> 2차원
	int age;         // age -> 0차원 &age -> 1차원
	char phone[20];
	float weight;
	char gender;

	printf("이    름 : ");
	gets_s(name, (int)sizeof(name)); //'scanf_s': 서식 문자열에 대한 인수가 충분하게 전달되지 않았습니다. 자리 표시자 및 해당 매개 변수에는 variadic 인수가 2개 필요하지만 1개가 제공되었습니다.

	printf("나    이 : ");
	scanf_s("%d", &age);

	printf("전화번호 : ");
	gets_s(phone, (int)sizeof(phone));  // phone 자체가 주소라서 &를 안붙임.
	char dummy = getchar();

	printf("몸 무 게 : ");
	scanf_s("%f", & weight);
	dummy = getchar();    // 입력 범퍼에 남아있는 엔터를 c가 가져가서 입력이 스킵 됨. 그래서 엔터 빼주기

	printf("성별(m/f): ");
	scanf_s("%c", &gender, (int)sizeof(gender));

	printf("\n[출력]\n");
	printf("이름 : %s\n", name);
	printf("나이 : %d\n", age);
	printf("전화번호 : %s\n", phone);
	printf("몸무게 : %f\n", weight);
	printf("성별(m/f): %c\n", gender);
}