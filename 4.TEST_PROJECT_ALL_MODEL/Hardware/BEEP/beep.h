/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.h
  * @brief   This file contains all the function prototypes for
  *          the gpio.c file
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
#ifndef __BEEP_H__
#define __BEEP_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"



/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */
#define BEEP_Pin          GPIO_PIN_8
#define BEEP_GPIO_Port    GPIOF

/* USER CODE BEGIN Includes */

/* ·äÃùÆ÷¿ØÖÆ */
#define BEEP(x) do{ x ? \
  HAL_GPIO_WritePin(BEEP_GPIO_Port, BEEP_Pin, GPIO_PIN_SET):\
  HAL_GPIO_WritePin(BEEP_GPIO_Port, BEEP_Pin, GPIO_PIN_RESET);\
}while(0)

/* BEEP ×´Ì¬·­×ª */
#define BEEP_TOGGLE() do{HAL_GPIO_TogglePin(BEEP_GPIO_Port, BEEP_Pin);\
}while(0)


/* USER CODE END Private defines */

void BEEP_GPIO_Init(void);

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ GPIO_H__ */

