// start.cpp
#include "std.h"
/*
0. seleton코드 구성
0. 입력기능, 출력기능 클래스 정의
---------------------------------
1. 데이터 클래스 정의	-> 
2. 저장 클래스 정의		-> pushback, erase bool -> void
3. 관리 클래스 정의		-> 코드 수정필요 + 구조화된 예외처리
---------------------------------
4. 실행 흐름 관련 클래스 정의
5. main 연결
6. file io
*/
int main()
{
	app _app;
	_app.init();
	_app.run();
	_app.exit();

	return 0;
}