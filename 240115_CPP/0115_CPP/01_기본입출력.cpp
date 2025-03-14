// 01_기본입출력.cpp
/*
코드 작성      -> 컴파일                            -> 링커
소스파일(.cpp)	  소스파일화장에 따른 컴파일러 동작
				  목적파일(.obj)						실행파일(.exe)

[C++ 언어] : C를 확장한 언어(C언어의 모든 문법을 사용할 수 있다. + @)
1) [함수 중심의 프로그래밍] C언어 문법 개선, 추가
2) [객체 중심의 프로그래밍] 개념 3가지(캡슐화, 상속성, 다형성) -> OOP언어
   class라는 키워드의 사용법
3) [일반화 프로그래밍]
   template라는 키워드의 사용법, STL(Standard Template Library)
*/

//#include <stdio.h>		// c언어 기본 h파일
#include <iostream>		// C++언어 기본 h파일 (.h 생략)

void exam1();
void exam2();
void exam3();
void exam4();

int main()
{
	exam4();

	return 0;
}

void exam1()
{
	printf("Hello, World!\n");		// C 출력 함수

	// :: scope연산자(범위 연산자, 누구꺼냐?)
	// std  : namespace(이름이 있는 공간)의 이름
	// cout : 출력객체
	// <<   : 출력연산자

	// endl : 함수(fflush(stdout) + "\n"
	std::cout << "Hello, World!" << std::endl;
}

// 사용 1) 키워드별로 등록
using std::cout;
using std::endl;

void exam2()
{
	std::cout << "Hello, World!" << std::endl;
	cout << "Hello, World!" << std::endl;
}

// 사용 2) 무조건 std에 있는 키워드 사용
#include <iostream>
using namespace std;

void exam3()
{
	cout << "고길동과 둘리" << endl;
}

/*
cout : 출력객체		 << : 출력 연산자 --> printf()와 동일
cin  : 입력객체		 << : 입력 연산자 --> scanf_s()와 동일[공백 탭, 엔터]

>> 일관성(동일 기능은 동일한 패턴으로)
*/ 
void exam4()
{
	char name[20];
	int age;
	char gender;
	float weight;

	cout << "이름 : ";		cin >> name;
	cout << "나이 : ";		cin >> age;
	cout << "성별 : ";		cin >> gender;
	cout << "몸무게 : ";	cin >> weight;

	cout << "\n\n[결과출력]" << endl;
	cout << "이름 : " << name << endl;
	cout << "나이 : " << age << endl;
	cout << "성별 : " << gender << endl;
	cout << "몸무게 : " << weight << endl;
}