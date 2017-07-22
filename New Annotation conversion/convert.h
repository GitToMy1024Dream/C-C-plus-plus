#pragma once
#ifndef _CONVERT_H_
#define _CONVERT_H_
#include <stdio.h>
#include <Windows.h>
#include <assert.h>
#define INPUT_FILE "input.c"
#define OUTPUT_FILE "output.c"
#pragma warning(disable:4996)
typedef enum STATUS {
	NORMAL_STATUS,
	C_STATUS,
	CPP_STATUS,
	END_STATUS,
}status_t;
extern status_t gStatus;
void convertBegin();
#endif