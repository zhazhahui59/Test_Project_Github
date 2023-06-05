/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    key.h
  * @brief   This file contains all the function prototypes for
  *          the key.c file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __KEY_H__
#define __KEY_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */
/* 按键相关宏定义 */
#define KEY1_Pin 			GPIO_PIN_0
#define KEY1_GPIO_Port 		GPIOA
#define KEY2_Pin 			GPIO_PIN_2
#define KEY2_GPIO_Port 		GPIOE
#define KEY3_Pin 			GPIO_PIN_3
#define KEY3_GPIO_Port 		GPIOE
#define KEY4_Pin 			GPIO_PIN_4
#define KEY4_GPIO_Port 		GPIOE

#define KEY1 HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin)
#define KEY2 HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_Pin)
#define KEY3 HAL_GPIO_ReadPin(KEY3_GPIO_Port, KEY3_Pin)
#define KEY4 HAL_GPIO_ReadPin(KEY4_GPIO_Port, KEY4_Pin)

#define KEY1_PRESS 1
#define KEY2_PRESS 2
#define KEY3_PRESS 3
#define KEY4_PRESS 4

/* USER CODE END Private defines */
void KEY_GPIO_Init(void);

/* USER CODE BEGIN Prototypes */
uint8_t Key_Scanf(uint8_t mode);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ GPIO_H__ */

