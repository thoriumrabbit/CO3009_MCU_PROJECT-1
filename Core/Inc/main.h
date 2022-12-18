/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define A0_BTN_PED_Pin GPIO_PIN_0
#define A0_BTN_PED_GPIO_Port GPIOA
#define A1_BTN_SELECT_Pin GPIO_PIN_1
#define A1_BTN_SELECT_GPIO_Port GPIOA
#define A2_BTN_MODIFY_Pin GPIO_PIN_4
#define A2_BTN_MODIFY_GPIO_Port GPIOA
#define A3_BTN_SET_Pin GPIO_PIN_0
#define A3_BTN_SET_GPIO_Port GPIOB
#define D6_PED_LIGHT1_Pin GPIO_PIN_10
#define D6_PED_LIGHT1_GPIO_Port GPIOB
#define D7_PEDLIGHT2_Pin GPIO_PIN_8
#define D7_PEDLIGHT2_GPIO_Port GPIOA
#define D2_RED_LED1_Pin GPIO_PIN_10
#define D2_RED_LED1_GPIO_Port GPIOA
#define D3_GREEN_LED1_Pin GPIO_PIN_3
#define D3_GREEN_LED1_GPIO_Port GPIOB
#define D5_GREEN_LED2_Pin GPIO_PIN_4
#define D5_GREEN_LED2_GPIO_Port GPIOB
#define D4_RED_LED_2_Pin GPIO_PIN_5
#define D4_RED_LED_2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
