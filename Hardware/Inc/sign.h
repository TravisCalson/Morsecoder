#ifndef SIGN_H_
#define SIGN_H_
#include "stdint.h"
#include "main.h"
extern uint32_t sign[SIGN_LENGTH_MAX];//点划代号：0代表点，1代表划，9代表空
unsigned char sign_to_character(uint32_t * p);
#endif