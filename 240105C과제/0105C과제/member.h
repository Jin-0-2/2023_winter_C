#pragma once


void member_print(int i, int flag, char* name, char* phone, int age);

void member_println(char* name, char* phone, int age);

int member_idx_check(int idx, int flag);

int member_insert(int* flag, char* name, char* phone, int* age, const char* n, const char* p, int a);

int member_update(char* phone, int* age, const char* p, const int a);

int member_delete(char* name, char* phone, int* age, int* flag);