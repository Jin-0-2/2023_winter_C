// app.h
#pragma once

/*
[흐름] 초기화 : 최초 한번만 실행
*/
void app_init();

/*
[흐름] 반복(엔진)
*/
void app_run();

/*
[흐름] 종료처리 : 종료시 한번만 실행
*/
void app_exit();


void menuprint();
void logo();
void ending();