#include "input_content.h" 
#include "sign.h"
#include "main.h"
/**将输入的字符转换为LED的电平时间长短*/
void character_to_sign(uint8_t * character)
{
		switch(*character)
		{
			case 'A': {sign[0] = point; sign[1] = row; 	 sign[2] = null;  sign[3] = null;  sign[4] = null;  sign[5] = null;  break; }
			case 'B': {sign[0] = row; 	sign[1] = point; sign[2] = point; sign[3] = point; sign[4] = null;  sign[5] = null;  break; }
			case 'C': {sign[0] = row; 	sign[1] = point; sign[2] = row; 	sign[3] = point; sign[4] = null;  sign[5] = null;  break; }
			case 'D': {sign[0] = row; 	sign[1] = point; sign[2] = point; sign[3] = null;  sign[4] = null;  sign[5] = null;  break; }
			case 'E': {sign[0] = point; sign[1] = row; 	 sign[2] = null;  sign[3] = null;  sign[4] = null;  sign[5] = null;  break; }
			case 'F': {sign[0] = point; sign[1] = point; sign[2] = row; 	sign[3] = point; sign[4] = null;  sign[5] = null;  break; }
			case 'G': {sign[0] = row; 	sign[1] = row; 	 sign[2] = point; sign[3] = null;  sign[4] = null;  sign[5] = null;  break; }
			case 'H': {sign[0] = point; sign[1] = point; sign[2] = point; sign[3] = point; sign[4] = null;  sign[5] = null;  break; }
			case 'I': {sign[0] = point; sign[1] = point; sign[2] = null;  sign[3] = null;  sign[4] = null;  sign[5] = null;  break; }
			case 'J': {sign[0] = point; sign[1] = row; 	 sign[2] = row; 	sign[3] = row;   sign[4] = null;  sign[5] = null;  break; }
			case 'K': {sign[0] = row; 	sign[1] = point; sign[2] = row; 	sign[3] = null;  sign[4] = null;  sign[5] = null;  break; }
			case 'L': {sign[0] = point; sign[1] = row; 	 sign[2] = point; sign[3] = point; sign[4] = null;  sign[5] = null;  break; }
			case 'M': {sign[0] = row; 	sign[1] = row;   sign[2] = null;  sign[3] = null;  sign[4] = null;  sign[5] = null;  break; }
			case 'N': {sign[0] = row; 	sign[1] = point; sign[2] = null;  sign[3] = null;  sign[4] = null;  sign[5] = null;  break; }
			case 'O': {sign[0] = row; 	sign[1] = row; 	 sign[2] = row; 	sign[3] = null;  sign[4] = null;  sign[5] = null;  break; }
			case 'P': {sign[0] = point; sign[1] = row;	 sign[2] = row; 	sign[3] = point; sign[4] = null;  sign[5] = null;  break; }
			case 'Q': {sign[0] = row; 	sign[1] = row;	 sign[2] = point; sign[3] = row;   sign[4] = null;  sign[5] = null;  break; }
			case 'R': {sign[0] = point; sign[1] = row;	 sign[2] = point; sign[3] = null;  sign[4] = null;  sign[5] = null;  break; }
			case 'S': {sign[0] = point; sign[1] = point; sign[2] = point; sign[3] = null;  sign[4] = null;  sign[5] = null;  break; }
			case 'T': {sign[0] = row; 	sign[1] = null;  sign[2] = null;  sign[3] = null;  sign[4] = null;  sign[5] = null;  break; }
			case 'U': {sign[0] = point; sign[1] = point; sign[2] = row; 	sign[3] = null;  sign[4] = null;  sign[5] = null;  break; }
			case 'V': {sign[0] = point; sign[1] = point; sign[2] = point; sign[3] = row;   sign[4] = null;  sign[5] = null;  break; }
			case 'W': {sign[0] = point; sign[1] = row;	 sign[2] = row; 	sign[3] = null;  sign[4] = null;  sign[5] = null;  break; }
			case 'X': {sign[0] = row; 	sign[1] = point; sign[2] = point; sign[3] = row;   sign[4] = null;  sign[5] = null;  break; }
			case 'Y': {sign[0] = row; 	sign[1] = point; sign[2] = row; 	sign[3] = row;   sign[4] = null;  sign[5] = null;  break; }
			case 'Z': {sign[0] = row; 	sign[1] = row;	 sign[2] = point; sign[3] = point; sign[4] = null;  sign[5] = null;  break; }
			case '0': {sign[0] = row; 	sign[1] = row;	 sign[2] = row; 	sign[3] = row;   sign[4] = row; 	sign[5] = null;  break; }
			case '1': {sign[0] = point; sign[1] = row;	 sign[2] = row; 	sign[3] = row;   sign[4] = row; 	sign[5] = null;  break; }
			case '2': {sign[0] = point; sign[1] = point; sign[2] = row; 	sign[3] = row;   sign[4] = row;		sign[5] = null;  break; }
			case '3': {sign[0] = point; sign[1] = point; sign[2] = point; sign[3] = row;   sign[4] = row; 	sign[5] = null;  break; }
			case '4': {sign[0] = point; sign[1] = point; sign[2] = point; sign[3] = point; sign[4] = row; 	sign[5] = null;  break; }
			case '5': {sign[0] = point; sign[1] = point; sign[2] = point; sign[3] = point; sign[4] = point; sign[5] = null;  break; }
			case '6': {sign[0] = row; 	sign[1] = point; sign[2] = point; sign[3] = point; sign[4] = point; sign[5] = null;  break; }
			case '7': {sign[0] = row; 	sign[1] = row;	 sign[2] = row; 	sign[3] = point; sign[4] = point; sign[5] = null;  break; }
			case '8': {sign[0] = row; 	sign[1] = row;	 sign[2] = row; 	sign[3] = row;   sign[4] = point; sign[5] = null;  break; }
			case '9': {sign[0] = row; 	sign[1] = row;	 sign[2] = row; 	sign[3] = row;   sign[4] = row; 	sign[5] = null;  break; }
			case '?': {sign[0] = point; sign[1] = point; sign[2] = row; 	sign[3] = row;   sign[4] = point; sign[5] = point; break; }
			case '/': {sign[0] = row; 	sign[1] = point; sign[2] = point; sign[3] = row;   sign[4] = point; sign[5] = null;  break; }
			case '(': {sign[0] = row; 	sign[1] = point; sign[2] = row; 	sign[3] = row;   sign[4] = point; sign[5] = row; 	 break; }
			case '-': {sign[0] = row; 	sign[1] = point; sign[2] = point; sign[3] = point; sign[4] = point; sign[5] = row;   break; }
			case '.': {sign[0] = point; sign[1] = row;	 sign[2] = point; sign[3] = row;   sign[4] = point; sign[5] = row;   break; }
			default:break;
	}
}
/**根据发送过来的字符解析成电平时间长短通过GPIO的方式输出为灯亮的时间*/
void led_control(void)
{
	int i = 0;
	for(i = 0;i < SIGN_LENGTH_MAX;i++)
	{
		switch(sign[i])
		{
			case point:
			{
				HAL_GPIO_TogglePin(GPIOF,GPIO_PIN_10);
				HAL_Delay(LED_SHORT_TIME);
				HAL_GPIO_TogglePin(GPIOF,GPIO_PIN_10);
				HAL_Delay(LED_REST_TIME);
				break;
			}
			case row:
			{
				HAL_GPIO_TogglePin(GPIOF,GPIO_PIN_10);
				HAL_Delay(LED_LONG_TIME);
				HAL_GPIO_TogglePin(GPIOF,GPIO_PIN_10);
				HAL_Delay(LED_REST_TIME);
				break;
			} 
			default:break;
		}
	}	
	/**每执行一次后，把解析的标志初始化*/
	sign_clear();
}
void sign_clear(void)
{
	int y;
	for(y = 0;y < SIGN_LENGTH_MAX;y++)
	{
		sign[y] = null;
	}
}