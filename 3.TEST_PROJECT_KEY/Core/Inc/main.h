/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "delay.h"
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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define KEY2_Pin GPIO_PIN_2
#define KEY2_GPIO_Port GPIOE
#define KEY3_Pin GPIO_PIN_3
#define KEY3_GPIO_Port GPIOE
#define KEY4_Pin GPIO_PIN_4
#define KEY4_GPIO_Port GPIOE
#define LED1_Pin GPIO_PIN_6
#define LED1_GPIO_Port GPIOF
#define BEEP_Pin GPIO_PIN_8
#define BEEP_GPIO_Port GPIOF
#define LED2_Pin GPIO_PIN_9
#define LED2_GPIO_Port GPIOF
#define LED3_Pin GPIO_PIN_10
#define LED3_GPIO_Port GPIOF
#define LED4_Pin GPIO_PIN_0
#define LED4_GPIO_Port GPIOC
#define KEY1_Pin GPIO_PIN_0
#define KEY1_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* 蜂鸣器控制 */
#define BEEP(x) do{ x ? \
  HAL_GPIO_WritePin(BEEP_GPIO_Port, BEEP_Pin, GPIO_PIN_SET):\
  HAL_GPIO_WritePin(BEEP_GPIO_Port, BEEP_Pin, GPIO_PIN_RESET);\
}while(0)

/* BEEP 状态翻转 */
#define BEEP_TOGGLE() do{HAL_GPIO_TogglePin(BEEP_GPIO_Port, BEEP_Pin);\
}while(0)

/* 按键相关宏定义 */
#define KEY1 HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin)
#define KEY2 HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_Pin)
#define KEY3 HAL_GPIO_ReadPin(KEY3_GPIO_Port, KEY3_Pin)
#define KEY4 HAL_GPIO_ReadPin(KEY4_GPIO_Port, KEY4_Pin)

#define KEY1_PRESS 1
#define KEY2_PRESS 2
#define KEY3_PRESS 3
#define KEY4_PRESS 4

/* LED灯相关宏定义 */
#define LED1_TOGGLE() do{HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);\
}while(0)

#define LED2_TOGGLE() do{HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);\
}while(0)

#define LED3_TOGGLE() do{HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin);\
}while(0)

#define LED4_TOGGLE() do{HAL_GPIO_TogglePin(LED4_GPIO_Port, LED4_Pin);\
}while(0)



/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
