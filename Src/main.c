/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
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
#include "ws2811.h"
#include "display.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

DAC_HandleTypeDef hdac;

TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim4;

/* USER CODE BEGIN PV */
extern const uint8_t rawAudio[38530];
uint16_t audio;
int a = 0;	//counter for audio interrupt
double audio_1 = 0.0;
int i = 0;	// counter for led interrupt
BRG LEDstruct[50];
uint8_t LEDbinary[1200];
int animationFlag = 0;
int diode = 0;
int value = 0;
extern int key;
extern int keyTab[4];
int keyAccept[4] = {1,3,3,7};
int keyCounter = 0;
int digit;
int flag;
int mode = 0;

void idleMode(){
	if (mode!=1){
		mode=1;
		i=0;
		turnOFF(LEDstruct);
		decimalToBinary(LEDstruct, LEDbinary);
	}

	if (i >= 11222){
		decimalToBinary(LEDstruct, LEDbinary);
		i = 0;
		if (animationFlag==0){
		setDiode(LEDstruct,diode,0,255,255,1);
		diode++;
		}
		else if (animationFlag==1){
			setDiode(LEDstruct,diode,0,0,0,0);
			diode--;
		}
		if (diode == 50){
			animationFlag=1;
			diode = 49;
		}
		else if (diode == 0){
			animationFlag = 0;
		}
	}
}

void activeMode(){
	if(mode!=2){
		mode=2;
		i=0;
		turnOFF(LEDstruct);
		decimalToBinary(LEDstruct, LEDbinary);
	}

	if (i >= 401222){
		if (animationFlag == 0){
			odd(LEDstruct);
		  	animationFlag = 1;
		}
		else if (animationFlag == 1){
			even(LEDstruct);
			animationFlag = 0;
		}
		decimalToBinary(LEDstruct, LEDbinary);
		i=0;
	}
}

void alarmMode(){
	if(mode!=3){
		mode=3;
		i=0;
		turnOFF(LEDstruct);
		decimalToBinary(LEDstruct, LEDbinary);
	}

	if (i >= 201222){
		if (animationFlag == 0){
			allRed(LEDstruct);
		  	decimalToBinary(LEDstruct, LEDbinary);

		  	animationFlag = 1;
		}
		else if (animationFlag == 1){
			turnOFF(LEDstruct);
			decimalToBinary(LEDstruct, LEDbinary);
			animationFlag = 0;
		}
		i=0;
	}
}

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM4_Init(void);
static void MX_ADC1_Init(void);
static void MX_DAC_Init(void);
static void MX_TIM3_Init(void);
/* USER CODE BEGIN PFP */
void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef *htim){
	if (htim-> Instance == TIM4){

		if (i<1200){
			if (LEDbinary[i] == 0){
				TIM4->CCR1 = low;
			}
			if (LEDbinary[i] == 1){
				TIM4->CCR1 = high;
			}
		}
		if (i >= 1200 && i < 1222){
			TIM4->CCR1 = ret;
		}
		i++;

		if(value == 0 && key == 0){
			idleMode();
		}
		else if (value == 0 && key == 1){
			activeMode();
		}
		else if (value == 1 && key == 1){
			alarmMode();
		}
	}

	if (value == 1 && key == 1){
		if (htim-> Instance == TIM3){
			if(a < 38530 ){
				HAL_DAC_SetValue(&hdac,DAC_CHANNEL_1,DAC_ALIGN_12B_R,rawAudio[a]*audio_1);
				a++;
			}
			else{
				a = 0;
			}
		}
	}
}

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
  MX_TIM4_Init();
  MX_ADC1_Init();
  MX_DAC_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim4);
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);

  HAL_TIM_Base_Start_IT(&htim3);
  HAL_DAC_Start(&hdac,DAC_CHANNEL_1);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  //MOTION SENSOR
	  	  if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4) && key == 1){
	  	  		  value = 1;
	  	  }

	  //KEYBOARD
	  	  if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_7)){
	  		  for(int t = 0; t < 2000000; t++){}
	  		  keyTab[keyCounter] = 0;
	  		  digit = 0;
	  		  keyCounter++;
	  		  while(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_7) == 1);
	  	  }
	  	  if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_8)){
	  		  for(int t = 0; t < 2000000; t++){}
	  		  keyTab[keyCounter] = 1;
	  		  keyCounter++;
	  		  digit = 1;
	  		  while(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_8) == 1);
	  	  }
	  	  if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_9)){
	  		  for(int t = 0; t < 2000000; t++){}
	  		  keyTab[keyCounter] = 2;
	  		  keyCounter++;
	  		  digit =2;
	  		  while(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_9) == 1);
	  	  }
	  	  if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_10)){
	  		  for(int t = 0; t < 2000000; t++){}
	  		  keyTab[keyCounter] = 3;
	  		  keyCounter++;
	  		  digit = 3;
	  		  while(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_10) == 1);
	  	  }
	  	  if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_11)){
	  		  for(int t = 0; t < 2000000; t++){}
	  		  keyTab[keyCounter] = 4;
	  		  keyCounter++;
	  		  digit =4;
	  		  while(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_11) == 1);
	  	  }
	  	  if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_12)){
	  		  for(int t = 0; t < 2000000; t++){}
	  		  keyTab[keyCounter] = 5;
	  		  keyCounter++;
	  		  digit = 5;
	  		  while(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_12) == 1);
	  	  }
	  	  if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_13)){
	  		  for(int t = 0; t < 2000000; t++){}
	  		  keyTab[keyCounter] = 6;
	  		  keyCounter++;
	  		  digit = 6;
	  		  while(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_13) == 1);
	  	  }
	  	  if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_14)){
	  		  for(int t = 0; t < 2000000; t++){}
	  		  keyTab[keyCounter] = 7;
	  		  keyCounter++;
	  		  digit = 7;
	  		  while(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_14) == 1);
	  	  }
	  	  if (keyCounter == 4){
	  		  for(int t = 0; t < 4; t++){
	  			  if(keyTab[t] == keyAccept[t]){
	  				flag = 1;
	  			  }
	  			  else{
	  				flag = 0;
	  				keyCounter = 0;
	  				break;

	  			  }
	  		  }
	  		  if (flag == 1){
	  			  if(key == 0 ){
	  				  key = 1;
	  				  flag = 0;
	  			  }
	  			  else if(key == 1){
	  				  key = 0;
	  				  value = 0;
	  				  flag = 0;
	  			  }
	  			  keyCounter = 0;
	  		  }
	  	  }

	  //AUDIO//
	  	  HAL_ADC_Start(&hadc1);
	  	  if(HAL_ADC_PollForConversion(&hadc1, 10)== HAL_OK){
	  		  audio = HAL_ADC_GetValue(&hadc1);
	  		  audio_1 = (2.95/4096) * audio;
	  	  }

	  //DISPLAY//
	  	  display(keyCounter);

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
  /** Initializes the CPU, AHB and APB busses clocks 
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
  /** Initializes the CPU, AHB and APB busses clocks 
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

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */
  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion) 
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time. 
  */
  sConfig.Channel = ADC_CHANNEL_1;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief DAC Initialization Function
  * @param None
  * @retval None
  */
static void MX_DAC_Init(void)
{

  /* USER CODE BEGIN DAC_Init 0 */

  /* USER CODE END DAC_Init 0 */

  DAC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN DAC_Init 1 */

  /* USER CODE END DAC_Init 1 */
  /** DAC Initialization 
  */
  hdac.Instance = DAC;
  if (HAL_DAC_Init(&hdac) != HAL_OK)
  {
    Error_Handler();
  }
  /** DAC channel OUT1 config 
  */
  sConfig.DAC_Trigger = DAC_TRIGGER_NONE;
  sConfig.DAC_OutputBuffer = DAC_OUTPUTBUFFER_ENABLE;
  if (HAL_DAC_ConfigChannel(&hdac, &sConfig, DAC_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN DAC_Init 2 */

  /* USER CODE END DAC_Init 2 */

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 524;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 9;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

/**
  * @brief TIM4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM4_Init(void)
{

  /* USER CODE BEGIN TIM4_Init 0 */

  /* USER CODE END TIM4_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM4_Init 1 */

  /* USER CODE END TIM4_Init 1 */
  htim4.Instance = TIM4;
  htim4.Init.Prescaler = 0;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = 209;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim4) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim4, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim4) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM4_Init 2 */

  /* USER CODE END TIM4_Init 2 */
  HAL_TIM_MspPostInit(&htim4);

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
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3 
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pins : PE7 PE8 PE9 PE10 
                           PE11 PE12 PE13 PE14 */
  GPIO_InitStruct.Pin = GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10 
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : PB12 PB13 PB14 PB15 */
  GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PD0 PD1 PD2 PD3 
                           PD4 PD5 PD6 PD7 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3 
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pin : PB4 */
  GPIO_InitStruct.Pin = GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
