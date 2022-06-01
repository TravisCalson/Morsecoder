#include "stdint.h" 
#include "main.h"
#ifndef __INPUT_CONTENT_H
#define __INPUT_CONTENT_H
#define US_TO_MS 1000
extern uint8_t UartRxBuff[UART_DMA_BUFF_LEN_MAX];//接收的字符
/*字符解析函数*/
void character_to_sign(uint8_t * character);
/*LED灯控制函数*/
void led_control(void);
void sign_clear(void);

#endif