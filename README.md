# 文件说明：

每一个文件夹都是一个模块的测试，所有代码均才用了AC6的编写，编译方式。

## 一、软硬件平台说明

**硬件平台说明：**

硬件平台采用基于Cotex-M4内核的STM32F407ZGT6芯片的开发板。

**软件平台说明：**

***STM32CubeMX 版本**：*

STM32CubeMX Version：6.8.0
Firmware Package Name and Vsersion：STM32Cube_FW_F4_V1.27.0

***Keil版本：***

Keil μVision V5.36.0.0

Keil package version：Keil.STM32F4xx_DFP.2.17.0.pack

以上所有软件均在**Windows11专业版**22H2上安装测试。



## 二、文件说明

通过上述3个简单的例子，可以看出使用STM32CubeMX可以快速的创建工程模板和代码，但是对模块化编程不是很友好，所有关于IO的代码都生成在了gpio.c/h文件中了。为了更好的体现模块化编程，我们将在接下来的项目中，重新改造工程模板。当然，1中创建的工程模板，大家仍可以继续使用，而且在单个模块联系的项目中，1中的模板更容易上手和使用哦。