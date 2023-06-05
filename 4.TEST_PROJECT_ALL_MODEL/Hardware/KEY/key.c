/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
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

/* Includes ------------------------------------------------------------------*/
#include "key.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/
void KEY_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();


  /*Configure GPIO pins : PEPin PEPin PEPin */
  GPIO_InitStruct.Pin = KEY2_Pin|KEY3_Pin|KEY4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = KEY1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(KEY1_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */
uint8_t Key_Scanf(uint8_t mode)
{
  static uint8_t key_up = 1;  /* 按键按松开标志 */
  uint8_t key_value=0;
  if(mode) key_up = 1;          /* 支持连按 */
  
  if(key_up && (KEY1 == 1 || KEY2 == 0 || KEY3 == 0 || KEY4 == 0))
  {
    HAL_Delay(10);
    key_up = 0;
    if(KEY1 == 1) key_value = KEY1_PRESS;
    if(KEY2 == 0) key_value = KEY2_PRESS;
    if(KEY3 == 0) key_value = KEY3_PRESS;
    if(KEY4 == 0) key_value = KEY4_PRESS;  
  }else if(KEY1 == 0 || KEY2 == 1 || KEY3 == 1 || KEY4 == 1)
  {
    /* 没有任何按键按下, 标记按键松开 */
    key_up = 1;
  }
  return key_value; //返回按键值
}

/* USER CODE END 2 */
