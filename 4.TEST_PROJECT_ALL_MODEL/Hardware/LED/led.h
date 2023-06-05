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
#ifndef __LED_H__
#define __LED_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */
/* LED灯相关宏定义 */
#define LED1_Pin 			      GPIO_PIN_6
#define LED1_GPIO_Port 		  GPIOF
#define LED2_Pin 			      GPIO_PIN_9
#define LED2_GPIO_Port 		  GPIOF
#define LED3_Pin 			      GPIO_PIN_10
#define LED3_GPIO_Port 		  GPIOF
#define LED4_Pin 			      GPIO_PIN_0
#define LED4_GPIO_Port 		  GPIOC

#define LED1_TOGGLE() do{HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);\
}while(0)

#define LED2_TOGGLE() do{HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);\
}while(0)

#define LED3_TOGGLE() do{HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin);\
}while(0)

#define LED4_TOGGLE() do{HAL_GPIO_TogglePin(LED4_GPIO_Port, LED4_Pin);\
}while(0)

/* USER CODE END Private defines */

void LED_GPIO_Init(void);

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ GPIO_H__ */

