#include "led.h"

//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK战舰STM32开发板
//LED驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2012/9/2
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	   

//初始化PB5和PE5为输出口.并使能这两个口的时钟		    
//LED IO初始化
void LED_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
	
		
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO |RCC_APB2Periph_GPIOA |RCC_APB2Periph_GPIOB |\
 	RCC_APB2Periph_GPIOC |RCC_APB2Periph_GPIOD |RCC_APB2Periph_GPIOE |RCC_APB2Periph_GPIOF |RCC_APB2Periph_GPIOG, ENABLE);	 //使能PA,PB端口时钟

	
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOD, ENABLE);	 //使能PB,PE端口时钟
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;				 //LED0-->PB.5 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB.5
 GPIO_SetBits(GPIOA,GPIO_Pin_8);						 //PB.5 输出高

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;	    		 //LED1-->PE.5 端口配置, 推挽输出
 GPIO_Init(GPIOD, &GPIO_InitStructure);	  				 //推挽输出 ，IO口速度为50MHz
 GPIO_SetBits(GPIOD,GPIO_Pin_2); 						 //PE.5 输出高 

 //GPIOA configure out 			
 GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_8 ;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOA, &GPIO_InitStructure);

 GPIO_InitStructure.GPIO_Pin  = 0X000F ;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;		
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOA, &GPIO_InitStructure);

  //GPIOB configure out 	
 GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_8 | GPIO_Pin_9 | 0X000F | GPIO_Pin_4 | GPIO_Pin_7 |GPIO_Pin_3;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;		
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOB, &GPIO_InitStructure);	

 GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_10 | GPIO_Pin_11  | GPIO_Pin_12 | GPIO_Pin_13;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOB, &GPIO_InitStructure);	
 
 //GPIOC configure out 			
 GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_11 | GPIO_Pin_12 |GPIO_Pin_6 |GPIO_Pin_7 | GPIO_Pin_8 |GPIO_Pin_9;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOC, &GPIO_InitStructure);


 GPIO_InitStructure.GPIO_Pin  =  GPIO_Pin_15 | GPIO_Pin_14 |GPIO_Pin_13 |GPIO_Pin_0  ;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;		
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOC, &GPIO_InitStructure);
 //GPIOD configure out 			
 GPIO_InitStructure.GPIO_Pin  = 0xfcff;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOD, &GPIO_InitStructure);
 
// GPIO_SetBits(GPIOD,GPIO_Pin_5);
// GPIO_SetBits(GPIOD,GPIO_Pin_4);
// GPIO_SetBits(GPIOD,GPIO_Pin_3);
// GPIO_SetBits(GPIOD,GPIO_Pin_2);
// GPIO_SetBits(GPIOD,GPIO_Pin_1);
// GPIO_SetBits(GPIOD,GPIO_Pin_0);
 //GPIOE configure out 			
 GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_2 |GPIO_Pin_1 | GPIO_Pin_3 |GPIO_Pin_6 | GPIO_Pin_5 | GPIO_Pin_4 | GPIO_Pin_0;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;		
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOE, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_10 | GPIO_Pin_11 |GPIO_Pin_12 | GPIO_Pin_13 |GPIO_Pin_14  |GPIO_Pin_15 ;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOE, &GPIO_InitStructure);
 
 //GPIOF configure out 			
 GPIO_InitStructure.GPIO_Pin  = 0XFFFF;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;		
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOF, &GPIO_InitStructure);
 
 //GPIOG configure out 			
 GPIO_InitStructure.GPIO_Pin  = 0x7fcc;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOG, &GPIO_InitStructure);

 GPIO_InitStructure.GPIO_Pin  = 0x8000;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;		
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_Init(GPIOG, &GPIO_InitStructure);

 GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE); 
 
}
 
