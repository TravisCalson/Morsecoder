#ifndef SIGN_H_
#define SIGN_H_
#include "stdint.h"
#include "main.h"
extern uint32_t sign[SIGN_LENGTH_MAX];//�㻮���ţ�0����㣬1������9�����
unsigned char sign_to_character(uint32_t * p);
#endif