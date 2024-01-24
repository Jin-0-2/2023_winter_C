//member.h

#pragma once

typedef struct tagmember member;

struct tagmember
{
	char name[20];
	char phone[20];
};
// printall에서 활용(전달된 회원정보를 한줄에 출력)
void member_print(const member* pmem);

// insert에서 활용(member mem 변수선언 -> 전달된 정보로 초기화)
member member_create(const char* name, const char* phone);

// select에서 활용 (전달된 회원정보를 여러줄에 출력)
void member_println(const member* pmem);

// update에서 활용(전달된 회원정보를 2nd, 3nd 인자로 변경)
void member_update(member* pmem, const char* phone);