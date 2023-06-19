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
#ifndef __WS2812_H__
#define __WS2812_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */
/* LED灯相关宏定义 */
#define RGB_Pin 			      GPIO_PIN_5
#define RGB_GPIO_Port 		  GPIOG

#define RGB_LED_HIGH        HAL_GPIO_WritePin(RGB_GPIO_Port,RGB_Pin,GPIO_PIN_SET)
#define RGB_LED_LOW         HAL_GPIO_WritePin(RGB_GPIO_Port,RGB_Pin,GPIO_PIN_RESET)

#define RGB_NUM 7           //RGB灯珠的总个数。
#define RGB_WANT_NUM 7      //想要点亮RGB灯珠的个数。

// https://www.sioe.cn/yingyong/yanse-rgb-16/ 
#define RED_RGB16           0xFF0000        //红色
#define ORANGE_RGB16        0xFFA500        //橙色
#define YELLOW_RGB16        0xFFFF00        //黄色
#define GREEN_RGB16         0x008000        //绿色
#define CYAN_RGB16          0x00FFFF        //青色
#define BLUE_RGB16          0x0000FF        //蓝色
#define PURPLE_RGB16        0x800080        //紫色


/* USER CODE END Private defines */

void RGB_GPIO_Init(void);

/* USER CODE BEGIN Prototypes */
void RGB_LED_Write0(void);
void RGB_LED_Write1(void);

void RGB_LED_Reset(void);
void RGB_LED_Write_Byte(uint8_t byte);
void RGB_LED_Write_24Bits(uint8_t red,uint8_t green,uint8_t blue);

void RGB_LED_Red(void);
void RGB_LED_Green(void);
void RGB_LED_Blue(void);
void RGB_LED_Color(uint8_t num, uint32_t color);
void RGB_LED_Color_One_By_One(uint32_t color);

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ GPIO_H__ */

