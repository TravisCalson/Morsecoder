#include "stdint.h" 
#include "main.h"
#ifndef __INPUT_CONTENT_H
#define __INPUT_CONTENT_H
#define US_TO_MS 1000
extern uint8_t UartRxBuff[UART_DMA_BUFF_LEN_MAX];//���յ��ַ�
/*�ַ���������*/
void character_to_sign(uint8_t * character);
/*LED�ƿ��ƺ���*/
void led_control(void);
void sign_clear(void);

#endif