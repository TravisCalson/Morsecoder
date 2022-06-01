#include "tim.h"
#include "usart.h"
#include "Key.h"
#include "sign.h"
#include "main.h" 
#include "input_content.h" 
#define K 100
extern uint8_t UartTxBuff;//���͵��ַ�
extern uint32_t exti_time;//�����жϵĴ���-1
uint32_t Key_Time_Judge(uint32_t time)
{
	uint32_t x;
	/**500ms���ж�Ϊ��*/
	if(time <= KEY_LONG_OR_SHORT)
		x = point;
	/**����500ms�ж�Ϊ��*/
	else if(time > KEY_LONG_OR_SHORT)
		x = row;
	/**����Ϊnull*/
	else
		x = null;
	return x;
}
uint32_t Key_Exti_Judge(uint32_t exti)
{
	switch(exti)
	{
		/**���sign���鵽������Ԫ�أ������жϴ�����0*/
		case 5:
		{
			exti = 0;
			break;
		}
		/**û�������*/
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
		/**��ʱ�����ת�����ַ�*/
		UartTxBuff = sign_to_character(sign);
		/**����*/
		HAL_UART_Transmit_DMA(&huart1,&UartTxBuff,1);
		/**��ʱ�������0*/
		sign_clear();
	}
}
void LED_Brightness_Control(uint8_t * number)
{
	uint32_t LED_brightness;
	if((* number >= '0')&&(* number <= '9'))
	{
		/**���ڼ�����������Ϊ999����1����Ӧ�ıȽ�ֵΪ100���Դ�����*/
		LED_brightness = (* number - '0') * K;
		/**���������ڶ�ʱ��PWM����*/
		HAL_TIM_PWM_Start(&htim14,TIM_CHANNEL_1);
		/**����ռ�ձ�*/
		__HAL_TIM_SET_COMPARE(&htim14,TIM_CHANNEL_1,LED_brightness);
	}
	else ;
}