//member.h

#pragma once
#define DATA_MAX 10

typedef struct tagmember member;

struct tagmember
{
	int flag;
	char id[20];
	char phone[20];
	int age;
};

// insert에서 활용(member mem 변수선언 -> 전달된 정보로 초기화, flag는 1로 -> mem 반환)
member member_create(const char* name, const char* phone, int age);

// printall에서 활용(전달된 회원정보를 한줄에 출력)
void member_print(const member* pmem);

// select에서 활용 (전달된 회원정보를 여러줄에 출력)
void member_println(const member* pmem);

// update에서 활용(전달된 회원정보를 2nd, 3nd 인자로 변경)
void member_update(member* pmem, const char* phone, int age);

// delete에서 활용(전달된 회원정볼르 "","",0으로 초기화, flag도 0ㅇ로 초기화
void member_delete(member* pmem);