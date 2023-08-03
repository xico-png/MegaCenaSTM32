/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define G1G GPIO_PIN_5
#define G1F GPIO_PIN_6
#define G1A GPIO_PIN_4
#define G1B GPIO_PIN_3
#define G1E GPIO_PIN_14
#define G1D GPIO_PIN_15
#define G1C GPIO_PIN_0
//pinos 2
#define G2G GPIO_PIN_5
#define G2F GPIO_PIN_6
#define G2A GPIO_PIN_4
#define G2B GPIO_PIN_3
#define G2E GPIO_PIN_14
#define G2D GPIO_PIN_15
#define G2C GPIO_PIN_0
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

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
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  int SorteioReal[60]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,52,53,54,56,57,58,59,60};
   int sortear6vezes =6;
   int diminui_indice = 60;

   while (sortear6vezes>0)
   {
 	  int num = rand();
 	 	  int sorteado = num%diminui_indice;
 	  for(int i = sorteado;i<diminui_indice; i++){
 		  SorteioReal[i] = SorteioReal[i++];


 	  }
 	  printf(sorteado);
 	  	int NumeroDisplay = 0;
 	  	NumeroDisplay = SorteioReal[sorteado];
 	  	int unidade = NumeroDisplay%10;
 	  	int dezena = NumeroDisplay/10;
 	  	Mostra_NumeroD(dezena);
 	  	Mostra_NumeroU(unidade);
 	  	HAL_Delay(1500);
 	  	diminui_indice --;
 	  	sortear6vezes--;

   }

    /* USER CODE END WHILE */


//Mostra_NumeroU(1);
//HAL_Delay(1000);
//Mostra_NumeroU(2);
//Mostra_NumeroD(0);
//HAL_Delay(1000);
//Mostra_NumeroU(3);
//Mostra_NumeroD(0);
//HAL_Delay(1000);






/* USER CODE BEGIN 3 */

}
  /* USER CODE END 3 */


/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_10|GPIO_PIN_11
                          |GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15
                          |GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6, GPIO_PIN_RESET);

  /*Configure GPIO pins : PC13 PC14 PC15 */
  GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB10 PB11
                           PB12 PB13 PB14 PB15
                           PB3 PB4 PB5 PB6 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_10|GPIO_PIN_11
                          |GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15
                          |GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

void Mostra_NumeroD(int n)
{
	switch(n)
	{
	case 1:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, 1); //g
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1); //f
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 1);  //a
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 0); // b
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1);  //e
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 1); //d
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, 0); //c
		break;
	case 2:
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, 0); //g
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1); //f
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);  //a
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 0); // b
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);  //e
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 0); //d
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, 1); //c
		break;
	case 3:
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, 0); //g
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1); //f
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);  //a
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 0); // b
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1);  //e
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 0); //d
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, 0); //c
		break;
	case 4:
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, 0); //g
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //f
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 1);  //a
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 0); // b
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1);  //e
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 1); //d
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, 0); //c
		break;
	case 5:
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, 0); //g
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //f
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);  //a
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 1); // b
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1);  //e
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 0); //d
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, 0); //c
		break;
	case 6:
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, 0); //g
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //f
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);  //a
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 1); // b
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);  //e
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 0); //d
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, 0); //c
		break;
	case 7:
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, 1); //g
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1); //f
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);  //a
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 0); // b
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1);  //e
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 1); //d
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, 0); //c
			break;
	case 8:
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, 0); //g
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //f
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);  //a
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 0); // b
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);  //e
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 0); //d
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, 0); //c
			break;
	case 9:
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, 0); //g
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //f
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);  //a
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 0); // b
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1);  //e
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 0); //d
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, 0); //c
			break;
	case 0:
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, 1); //g
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0); //f
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);  //a
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 0); // b
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);  //e
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 0); //d
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, 0); //c
			break;
	}
}



void Mostra_NumeroU(int a)
{
	switch(a)
	{
	case 1:
		HAL_GPIO_WritePin(GPIOB, G1G, 1); //g
		HAL_GPIO_WritePin(GPIOB, G1F, 1); //f
		HAL_GPIO_WritePin(GPIOB, G1A, 1);  //a
		HAL_GPIO_WritePin(GPIOB, G1B, 0); // b
		HAL_GPIO_WritePin(GPIOC, G1E, 1);  //e
		HAL_GPIO_WritePin(GPIOC, G1D, 1); //d
		HAL_GPIO_WritePin(GPIOB, G1C, 0); //c
		break;
	case 2:
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0); //g
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 1); //f
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 0);  //a
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 0); // b
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, 0);  //e
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, 0); //d
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 1); //c
		break;
	case 3:
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0); //g
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 1); //f
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 0);  //a
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 0); // b
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, 1);  //e
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, 0); //d
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0); //c
		break;
	case 4:
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0); //g
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 0); //f
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 1);  //a
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 0); // b
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, 1);  //e
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, 1); //d
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0); //c
		break;
	case 5:
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0); //g
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 0); //f
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 0);  //a
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 1); // b
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, 1);  //e
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, 0); //d
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0); //c
		break;
	case 6:
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0); //g
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 0); //f
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 0);  //a
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 1); // b
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, 0);  //e
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, 0); //d
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0); //c
		break;
	case 7:
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 1); //g
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 1); //f
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 0);  //a
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 0); // b
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, 1);  //e
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, 1); //d
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0); //c
			break;
	case 8:
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0); //g
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 0); //f
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 0);  //a
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 0); // b
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, 0);  //e
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, 0); //d
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0); //c
			break;
	case 9:
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0); //g
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 0); //f
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 0);  //a
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 0); // b
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, 1);  //e
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, 0); //d
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0); //c
			break;
	case 0:
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 1); //g
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 0); //f
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 0);  //a
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 0); // b
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, 0);  //e
				HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, 0); //d
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0); //c
			break;
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
