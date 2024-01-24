// start.c

#include "std.h"

/*
회원 정보를 관리하는 프로그램 구현

회원정보 : 이름(문자열), 전화번호(문자열), 나이(정수)

[조건]
최대 관리 회원의 수 10명
기능 : 저장, 검색, 수정, 삭제, 전체 출력
저장 : 저장 위치, 이름, 전화번호, 나이를 입력받아 전역변수에 저장
검색 : 이름으로 검색해서 해당 회원 정보 출력
수정 : 이름으로 검색하고, 전화번로, 나이를 입력받아 해당 정보 변경
삭제 : 이름으로 검색하고, 해당 회원정보 초기화
단, 저장유무를 확인하기 위해 아래의 배열을 활용할 것
int g_flag[10] ;  //0 없음 , 1 저장데이터가 존재함

데이터는 아래와 같이 전역변수로 구성
            #define DATA_MAX   10
            int g_flag[DATA_MAX];
           char g_name[DATA_MAX][20];
           char g_phone[DATA_MAX][20];
           int    g_age[DATA_MAX];

*/

void main()
{
	app_init();
	app_run();
	app_exit();
}