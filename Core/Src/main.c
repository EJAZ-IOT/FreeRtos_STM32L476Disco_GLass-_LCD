/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  * @DEVELOPED BY: MOHAMMAD EJAZ MOBASHIR
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"
#include "stm32l476g_discovery_glass_lcd.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

LCD_HandleTypeDef LCDHandle;

osThreadId Task01Handle;
osThreadId Task02Handle;

/* USER CODE BEGIN PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
void BSP_LCD_GLASS_Init(void);
//static void MX_LCD_Init(void);
void Task01_init(void const * argument);
void Task02_init(void const * argument);

int main(void)
{

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();

  BSP_LCD_GLASS_Init();

  /* Create the thread(s) */
  /* definition and creation of Task01 */
  osThreadDef(Task01, Task01_init, osPriorityNormal, 0, 128);
  Task01Handle = osThreadCreate(osThread(Task01), NULL);

  /* definition and creation of Task02 */
  osThreadDef(Task02, Task02_init, osPriorityNormal, 0, 128);
  Task02Handle = osThreadCreate(osThread(Task02), NULL);

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {}
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_RTC;
  PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief LCD Initialization Function
  * @param None
  * @retval None
  */


/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin : PA0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}


/* USER CODE BEGIN Header_Task01_init */
/**
  * @brief  Function implementing the Task01 thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_Task01_init */
void Task01_init(void const * argument)
{
 uint8_t arr[10]= {"0123456789"};

  for(;;)
  {
	  for(int y=0; y<6;y++)
	  	  {
	         for(int x=0;x<10;x++)
	         {
	  	        BSP_LCD_GLASS_DisplayChar(&arr[y], POINT_OFF, DOUBLEPOINT_OFF,LCD_DIGIT_POSITION_1);
	  	        BSP_LCD_GLASS_DisplayChar(&arr[x], POINT_OFF, DOUBLEPOINT_OFF,LCD_DIGIT_POSITION_2);
                HAL_LCD_UpdateDisplayRequest(&LCDHandle);

                osDelay(1000);
	         }

	       }

  }
  /* USER CODE END 5 */
}

/* USER CODE BEGIN Header_Task02_init */
/**
* @brief Function implementing the Task02 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task02_init */
void Task02_init(void const * argument)
{
  /* USER CODE BEGIN Task02_init */
	int x=0;
	int y=0;
	uint8_t arr[10]= {"0123456789"};
  /* Infinite loop */
  for(;;)
  {
	if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)>0)
	{
		if(x<9)
		{
			x++;
		}
		else
		{
			x=0;
			if(y<5)
			{
				y++;
			}
			else
			{
				y=0;
			}
		}
	}

	 BSP_LCD_GLASS_DisplayChar(&arr[x], POINT_OFF, DOUBLEPOINT_OFF,LCD_DIGIT_POSITION_5);
	 BSP_LCD_GLASS_DisplayChar(&arr[y], POINT_OFF, DOUBLEPOINT_OFF,LCD_DIGIT_POSITION_4);
     HAL_LCD_UpdateDisplayRequest(&LCDHandle);

     osDelay(200);

  }
  /* USER CODE END Task02_init */
}

 /**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM1 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM1) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
