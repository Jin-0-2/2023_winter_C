// aaa.c


/*
# : 전처리 : 컴파일러보다 먼저 처리
include    : 포함하겠다(복사해 오겠다.) -> 그리고 전처리 문장은 사라짐.
*/


#include <stdio.h>  //라이브러리 헤더 < >, 직접만든 헤더 " "
#include "bbb.h"
#include "ccc.h"

//void fun1();
//void fun3();

void main()
{
	printf("main_start()\n");
	fun1();
	fun3();
	printf("main_end()\n");
}