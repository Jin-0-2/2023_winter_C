// 05_힙(동적)메모리.c
/*
내가 이만큼의 메모리가 필요한데 허락해줘!
리턴 : 공간이 부족 > NULL 반환
	 : 공간을 생성 > 시작주소 반환
주소 = malloc(필요한 바이트 크기);
주소 = calloc(sizeof(int), 2);		//필요한 바이트 크기 1st*2nd;
									//생성된 메모리 초기화까지 수행;
이 주소를 더이상 사용하지 않을꺼야
free(주소);
*/
#include <stdio.h>
#include <malloc.h>

void exam1();
void exam2();

int main()
{
	exam2();

	return 0;
}

/* 
1000	X-> 10
[heap]									// 메모리 릭 

104		p		[1000] -> NULL
100		num		X
[stack]
*/
void exam1()
{
	//int num;		// 바로 스택메모리에 저장

	int* p = (int*)malloc(sizeof(int));
	if (p == NULL)
	{
		printf("메모리 요청에 대한 오류\n");
		return;
	}

	// 사용
	*p = 10;

	free(p);		// 메모리 반납, 스택에 있는 p는 아직도 주소를 갖고있다.
	//p = NULL;
	
	// 잘못된 접근 코드 -> 강제종료
	// *p = 20;

	//printf("%d\n", *p);
}

// 동적 배열(실행할 때마다 배열의 크기가 변한다)
void exam2()
{
	int num;
	printf("개수 : ");		scanf_s("%d", &num);
	//int arr[num];	// 에러!


	// 힙  : 배열 생성
	// 스택: 배열 시작 주소
	int* arr = malloc(sizeof(int) * num);
	if (arr == NULL)
	{
		printf("메모리 요청에 대한 오류\n");
		return;
	}

	for (int i = 0; i < num; i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}

	free(arr);		arr = NULL;
}