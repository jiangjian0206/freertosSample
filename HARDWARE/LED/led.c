#include "led.h"

//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEKս��STM32������
//LED��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/2
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	   

//��ʼ��PB5��PE5Ϊ�����.��ʹ���������ڵ�ʱ��		    
//LED IO��ʼ��
void LED_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
	
		
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO |RCC_APB2Periph_GPIOA |RCC_APB2Periph_GPIOB |\
 	RCC_APB2Periph_GPIOC |RCC_APB2Periph_GPIOD |RCC_APB2Periph_GPIOE |RCC_APB2Periph_GPIOF |RCC_APB2Periph_GPIOG, ENABLE);	 //ʹ��PA,PB�˿�ʱ��

	
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOD, ENABLE);	 //ʹ��PB,PE�˿�ʱ��
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;				 //LED0-->PB.5 �˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOB.5
 GPIO_SetBits(GPIOA,GPIO_Pin_8);						 //PB.5 �����

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;	    		 //LED1-->PE.5 �˿�����, �������
 GPIO_Init(GPIOD, &GPIO_InitStructure);	  				 //������� ��IO���ٶ�Ϊ50MHz
 GPIO_SetBits(GPIOD,GPIO_Pin_2); 						 //PE.5 ����� 

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
 
