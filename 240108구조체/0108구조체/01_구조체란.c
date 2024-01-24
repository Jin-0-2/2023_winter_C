//01_구조체란?
/*
사용자가 만드는 데이터 [타입] : 복합타입

타입 키워드의 의미 : 무엇을?               어떤 크기로?
		int           정수                 4byte  sizeof(int)
  struct 태그명     (정수,문자,
					 실수주소,문자5개배열) 14byte sizeof(struct 태그명)

1) 구조체 정의 --> 타입 정의 ==> 정보 생성(코드가 아님)
struct 태그명
{
	int num;		//4
	char ch;		//1
	float *pf;		//4
	char arr[5];	//5
};

2) 변수 선언 --> int를 통해서 할 수 있는 모든 선언의 방법들을 동일하게

3) 메모리 생성 --> 메모리 생성 모양 이해
*/
#include <stdio.h>

//구조체 정의  
struct tagdata
{
	int num1;
	char ch;
};

void exam1();

int main()
{
	exam1();

	return 0;
}

//변수 선언 및 메모리
/*
108    data.ch       A
104    data.num1     20
100    num           10
*/
void exam1()
{
	int num = 10;
	struct tagdata  data = { 20, 'A' };

	printf("%d\n", num);		//10
	printf("%d\n", data.num1);	//20
	printf("%c\n", data.ch);	//A 

	//타입?
	/*
	num  : int      10          &num : int*    100
	data : struct tagdata ?    &data : struct tagdata*   104
	data.num1 : int   20        &data.num1 : int*        104
	data.ch   : char  A        &(data.ch) : char*        108
	*/
}
