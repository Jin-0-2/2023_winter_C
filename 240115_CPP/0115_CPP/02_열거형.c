// 02_열거형.c
/*
[사용자 정의 데이터 타입 : 타입키워드, 무엇을?, 크기]
struct : 복합 타입(기본형 타입으로 저장할 수 없기 때문에 새로운 타입 정의)
union
enum   : 열거형(저장할 값을 미리 정의함[범위?]) --> 가독성?
*/
#include <stdio.h>

// 타입명 : enum subject or sub
// 무엇을 : CPM, IT, GAME, ETC
// 크  기 : 4byte(위에 열거된 정보를 저장할 수 있는 크기)
typedef enum subject sub;
enum subject
{
	COM, IT = 101, GAME, ETC = 200
};

int main()
{
	// 1. enum에 열거된 키워드 사용
	printf("%d\n", COM);	// 0

	// 2. 변수 선언
	enum subject s1 = COM; //s1 = 0;
	s1 = GAME;			   //s1 = 102

	// 3. 조심할 부분(논리적 오류)
	s1 = 300;

	printf("%d\n", s1);

	return 0;
}