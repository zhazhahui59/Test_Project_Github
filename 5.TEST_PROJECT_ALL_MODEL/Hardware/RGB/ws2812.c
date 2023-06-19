/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    ws2812.c
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
#include "ws2812.h"

/* USER CODE BEGIN 0 */
#include "delay.h"
/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/*********************************************************************************************************
*	函 数 名: RGB_GPIO_Init
*	功能说明: 初始化RGB相关IO口配置。
*	形    参: 无
*	返 回 值: 无
*********************************************************************************************************
*/
void RGB_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOG_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(RGB_GPIO_Port, RGB_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = RGB_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(RGB_GPIO_Port, &GPIO_InitStruct);
  
}

/* USER CODE BEGIN 2 */
/*********************************************************************************************************
*	函 数 名: RGB_LED_Write0
*	功能说明: 对ws2812，数据写0操作
*	形    参: 无
*	返 回 值: 无
* 备    注: 不同主频的__nop()延时不太一样，对于168M主频，最小延时应该是：1/168000000=5.95ns，有示波器的话，可以测一下时序。
*********************************************************************************************************
*/
void RGB_LED_Write0(void)
{
  RGB_LED_HIGH;     //备注：高约320ns
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();//1
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
  __nop();__nop();__nop();
   RGB_LED_LOW;     //备注：低约960ns
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();//1
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();//6
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();//11
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();//16

}

/*********************************************************************************************************
*	函 数 名: RGB_LED_Write1
*	功能说明: 对ws2812，数据写1操作
*	形    参: 无
*	返 回 值: 无
* 备    注: 不同主频的__nop()延时不太一样，对于168M主频，最小延时应该是：1/168000000=5.95ns，有示波器的话，可以测一下时序。
*********************************************************************************************************
*/
void RGB_LED_Write1(void)
{
  RGB_LED_HIGH;     //备注：高约960ns
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();//1
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();//6
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();//11
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();//16

  RGB_LED_LOW;      //备注：低约320ns
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();//1
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
  __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
  __nop();__nop();__nop();
}
/*********************************************************************************************************
*	函 数 名: RGB_LED_Reset
*	功能说明: 对ws2812，数据复位操作
*	形    参: 无
*	返 回 值: 无
* 备    注: 无
*********************************************************************************************************
*/
void RGB_LED_Reset(void)
{
  RGB_LED_LOW;
  delay_us(280);
}
/*********************************************************************************************************
*	函 数 名: RGB_LED_Write_Byte
*	功能说明: 对ws2812，写入一个字节(8位)的数据，根据ws2812数据结构，要先发送高位。
*	形    参: 无
*	返 回 值: 无
* 备    注: 24bit数据结构为：8绿8红8蓝，先发高位，按照RGB的顺序发送数据(G7->G6->···...B0)
*********************************************************************************************************
*/

void RGB_LED_Write_Byte(uint8_t byte)
{
  uint8_t i;
  //
  for(i=0;i<8;i++)
  {
    //先判断最高位为0还是1，如果是1就调用发送数据1的函数，反之，调用发送数据0的函数。
    if(byte&0x80)
    {
      RGB_LED_Write1();
    }
    else
    {
      RGB_LED_Write0();
    }
    byte <<= 1;//发送高位后，通过移位操作发送次高位，知道发送完最低位。
  }
}
/*********************************************************************************************************
*	函 数 名: RGB_LED_Write_24Bits
*	功能说明: 拆解写入RGB三原色对应的16进制数字
*	形    参: 例如：	要亮灯的颜色为：深兰花紫	对应的16进制为：0x9932CC 对应的十进制RGB为：153,50,204
*           uint8_t green:0x32
*           uint8_t red:0x99
*           uint8_t blue:0xCC
*	返 回 值: 无
* 备    注: 24bit数据结构为：8绿8红8蓝，高位先发，按照RGB的顺序发送数据(G7->G6->···...B0)
*           RGB颜色与16进制颜色码转换网址：https://www.sioe.cn/yingyong/yanse-rgb-16/
*********************************************************************************************************
*/
void RGB_LED_Write_24Bits(uint8_t green, uint8_t red, uint8_t blue)
{
  RGB_LED_Write_Byte(green);    //先发送绿色对应8位
  RGB_LED_Write_Byte(red);      //再发送红色对应8位
  RGB_LED_Write_Byte(blue);     //最后是蓝色对应8位
}

/*********************************************************************************************************
*	函 数 名: RGB_LED_Write_24Bits_Hex
*	功能说明: 直接写入RGB三原色对应的16进制数字，不用拆解。
*	形    参: uint32_t color：16进制颜色码
*	返 回 值: 无
* 备    注: 24bit数据结构为：8绿8红8蓝，高位先发，按照RGB的顺序发送数据(G7->G6->···...B0)
*           RGB颜色与16进制颜色码转换网址：https://www.sioe.cn/yingyong/yanse-rgb-16/
*********************************************************************************************************
*/
void RGB_LED_Write_24Bits_Hex(uint32_t color)
{
  RGB_LED_Write_Byte(color>>8);     //先发送绿色对应8位
  RGB_LED_Write_Byte(color>>16);    //再发送红色对应8位
  RGB_LED_Write_Byte(color);        //最后是蓝色对应8位
}

/*********************************************************************************************************
*	函 数 名: RGB_LED_Red
*	功能说明: 亮灯颜色设定，其他颜色以此类推。
*	形    参: 
*	返 回 值: 
* 备    注: 24bit数据结构为：8绿8红8蓝，高位先发，按照RGB的顺序发送数据(G7->G6->···...B0)
*           RGB颜色与16进制颜色码转换网址：https://www.sioe.cn/yingyong/yanse-rgb-16/
*********************************************************************************************************
*/
void RGB_LED_Red(void)
{
  uint8_t i;
  //7个LED全彩灯
  for(i=0;i<RGB_NUM;i++)
  {
    RGB_LED_Write_24Bits(0, 0xff, 0);
  }
}

void RGB_LED_Green(void)
{
  uint8_t i;

  for(i=0;i<RGB_NUM;i++)
  {
    RGB_LED_Write_24Bits(0xff, 0, 0);
  }
}

void RGB_LED_Blue(void)
{
  uint8_t i;

  for(i=0;i<RGB_NUM;i++)
  {
    RGB_LED_Write_24Bits(0, 0, 0xff);
  }
}

/*********************************************************************************************************
*	函 数 名: RGB_LED_Color
*	功能说明: 亮灯颜色设定，亮多种颜色。
*	形    参: uint32_t color：16进制颜色码
*	返 回 值: 
* 备    注: 24bit数据结构为：8绿8红8蓝，高位先发，按照RGB的顺序发送数据(G7->G6->···...B0)
*           RGB颜色与16进制颜色码转换网址：https://www.sioe.cn/yingyong/yanse-rgb-16/
*********************************************************************************************************
*/
void RGB_LED_Color(uint8_t num, uint32_t color)
{
  uint8_t i;
  for(i=0;i<RGB_NUM;i++)
  {
    if(i < num)
      RGB_LED_Write_24Bits_Hex(color);
    else
      RGB_LED_Write_24Bits_Hex(0);
  }
  RGB_LED_Reset();
}

/*********************************************************************************************************
*	函 数 名: RGB_LED_Color_One_By_One
*	功能说明: 亮灯颜色设定，亮多种颜色。
*	形    参: uint32_t color：16进制颜色码
*	返 回 值: 
* 备    注: 24bit数据结构为：8绿8红8蓝，高位先发，按照RGB的顺序发送数据(G7->G6->···...B0)
*           RGB颜色与16进制颜色码转换网址：https://www.sioe.cn/yingyong/yanse-rgb-16/
*********************************************************************************************************
*/
void RGB_LED_Color_One_By_One(uint32_t color)
{
  uint8_t i;
  for(i=0;i<RGB_WANT_NUM-1;++i)
  {
    RGB_LED_Write_24Bits_Hex(0);
//    HAL_Delay(1000);
  }
  
}

/* USER CODE END 2 */
