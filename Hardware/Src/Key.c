#include "tim.h"
#include "usart.h"
#include "Key.h"
#include "sign.h"
#include "main.h" 
#include "input_content.h" 
#define K 100
extern uint8_t UartTxBuff;//发送的字符
extern uint32_t exti_time;//进入中断的次数-1
uint32_t Key_Time_Judge(uint32_t time)
{
	uint32_t x;
	/**500ms内判定为点*/
	if(time <= KEY_LONG_OR_SHORT)
		x = point;
	/**大于500ms判定为划*/
	else if(time > KEY_LONG_OR_SHORT)
		x = row;
	/**其他为null*/
	else
		x = null;
	return x;
}
uint32_t Key_Exti_Judge(uint32_t exti)
{
	switch(exti)
	{
		/**如果sign数组到第六个元素，进入中断次数清0*/
		case 5:
		{
			exti = 0;
			break;
		}
		/**没到则递增*/
		default:
		{
			exti++;
			break;
		}
	}
	return exti;
}
void DataTx_Judge(void)
{
	if(exti_time == 0)
	{
		/**将时间代号转换成字符*/
		UartTxBuff = sign_to_character(sign);
		/**发送*/
		HAL_UART_Transmit_DMA(&huart1,&UartTxBuff,1);
		/**将时间代号清0*/
		sign_clear();
	}
}
void LED_Brightness_Control(uint8_t * number)
{
	uint32_t LED_brightness;
	if((* number >= '0')&&(* number <= '9'))
	{
		/**由于计数周期设置为999，则‘1’对应的比较值为100，以此类推*/
		LED_brightness = (* number - '0') * K;
		/**开启灯所在定时器PWM功能*/
		HAL_TIM_PWM_Start(&htim14,TIM_CHANNEL_1);
		/**设置占空比*/
		__HAL_TIM_SET_COMPARE(&htim14,TIM_CHANNEL_1,LED_brightness);
	}
	else ;
}