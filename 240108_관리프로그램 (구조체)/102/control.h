#pragma once
void con_init();
void con_printall();
void con_insert();
void con_select();
void con_update();
void con_delete();
void con_exit();

int id_to_idx(const char* id);
member g_members[DATA_MAX];