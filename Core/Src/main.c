/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "Key.h"
#include "sign.h"
#include "input_content.h"
#include "string.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
uint8_t UartRxBuff[UART_DMA_BUFF_LEN_MAX];                                                   ///接收的字符
uint8_t UartTxBuff;                                                                          ///发送的字符
uint32_t exti_time = 0;                                                                      ///进入中断的次数-1
uint32_t key_down_time = 0;                                                                  ///按键按下的时间
uint32_t sign[SIGN_LENGTH_MAX] = {null,null,null,null,null,null};    ///默认电码组合为空
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
static inline void delayMicroseconds(uint32_t us);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_TIM2_Init();
  MX_TIM14_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  __HAL_UART_ENABLE_IT(&huart1,UART_IT_IDLE);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
      HAL_UART_Receive_DMA(&huart1,UartRxBuff,UART_DMA_BUFF_LEN_MAX);
      for(int x = 0;UartRxBuff[x] != '\0';x++)
      {
          character_to_sign(UartRxBuff + x);
          led_control();
          HAL_Delay(CHARACTER_REST_TIME);
      }
      memset(UartRxBuff,0,sizeof UartRxBuff);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
static inline void delayMicroseconds(uint32_t us)
{
    __IO uint32_t currentTicks = SysTick->VAL;
    /* Number of ticks per millisecond */
    const uint32_t tickPerMs = SysTick->LOAD + 1;
    /* Number of ticks to count */
    const uint32_t nbTicks = ((us - ((us > 0) ? 1 : 0)) * tickPerMs) / 1000;
    /* Number of elapsed ticks */
    uint32_t elapsedTicks = 0;
    __IO uint32_t oldTicks = currentTicks;
    do {
        currentTicks = SysTick->VAL;
        elapsedTicks += (oldTicks < currentTicks) ? tickPerMs + oldTicks - currentTicks :
                        oldTicks - currentTicks;
        oldTicks = currentTicks;
    } while (nbTicks > elapsedTicks);
}
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if(GPIO_Pin == GPIO_PIN_2){
        /**关闭定时器*/
        HAL_TIM_Base_Stop_IT(&htim2);
        /**计数器值清0*/
        __HAL_TIM_SET_COUNTER(&htim2,0);
        /**检测按键按下的时间*/
        while(HAL_GPIO_ReadPin(KEY2_GPIO_Port,KEY2_Pin) == GPIO_PIN_RESET){
            delayMicroseconds(1000);
            key_down_time++;
        }
        sign[exti_time] = Key_Time_Judge(key_down_time);
        /**根据进入中断的次数将每次按下的时间翻译成代号*/
        exti_time = Key_Exti_Judge(exti_time);
        /**判断是否要发送*/
        DataTx_Judge();
        /**打开定时器*/
        HAL_TIM_Base_Start_IT(&htim2);
        /**按下时间清0*/
        key_down_time = 0;
    }
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim == &htim2){
        /**关掉定时器*/
        HAL_TIM_Base_Stop_IT(&htim2);
        /**清空计数器值*/
        __HAL_TIM_SET_COUNTER(&htim2,0);
        /**进入中断次数清0*/
        exti_time = 0;
        /**把得到的时间长短转译成的代号翻译成文字*/
        UartTxBuff = sign_to_character(sign);
        /**清空时间长短转译成的代号*/
        sign_clear();
        /**向上位机传输字符*/
        HAL_UART_Transmit_DMA(&huart1,&UartTxBuff,1);
        /**判断字符是否为数字，并控制灯的亮度*/
        LED_Brightness_Control(&UartTxBuff);
    }
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
