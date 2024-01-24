#pragma once
#define DATA_MAX 10

void con_init();
void con_printall();
void con_insert();
void con_select();
void con_update();
void con_delete();
void con_exit();

int name_to_idx(char* name);