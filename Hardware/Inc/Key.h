#include "stdint.h"
#include "tim.h"
#ifndef KEY_H_
#define KEY_H_
void LED_Brightness_Control(uint8_t * number);
uint32_t Key_Time_Judge(uint32_t time);
uint32_t Key_Exti_Judge(uint32_t exti);
void DataTx_Judge(void);
#endif