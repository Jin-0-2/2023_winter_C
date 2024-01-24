// 01_aaa.c 소스파일 - 방

// 함수 선언 (컴파일러에게 ~한 함수가 있어 - 알림 에러 x) 함수를 사용하려면(호출) 반드시 함수의 선언이 필요하다.!
void aaa_fun2();
void bbb_fun1();
// 함수 정의 - 학생 생성

void aaa_fun1()
{
	aaa_fun2();
	bbb_fun1();
}

void aaa_fun2()
{
	aaa_fun1(); //[흐름]함수 호출 - 학생의 이름을 부름
}

// 약속된 시작 함수, main 함수의 끝(종료)
void main()
{
	aaa_fun1();
	aaa_fun2();
}