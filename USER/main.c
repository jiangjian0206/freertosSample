#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "timer.h"
#include "lcd.h"
#include "FreeRTOS.h"
#include "task.h"
/************************************************
 ALIENTEK Mini STM32F103������ FreeRTOSʵ��6-2
 FreeRTOS���񴴽���ɾ��(��̬����)-�⺯���汾
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/

//�������������ջ
static StackType_t IdleTaskStack[configMINIMAL_STACK_SIZE];
//����������ƿ�
static StaticTask_t IdleTaskTCB;

//��ʱ�����������ջ
static StackType_t TimerTaskStack[configTIMER_TASK_STACK_DEPTH];
//��ʱ������������ƿ�
static StaticTask_t TimerTaskTCB;

//�������ȼ�
#define START_TASK_PRIO		1
//�����ջ��С	
#define START_STK_SIZE 		128  
//�����ջ
StackType_t StartTaskStack[START_STK_SIZE];
//������ƿ�
StaticTask_t StartTaskTCB;
//������
TaskHandle_t StartTask_Handler;
//������
void start_task(void *pvParameters);

//�������ȼ�
#define TASK1_TASK_PRIO		2
//�����ջ��С	
#define TASK1_STK_SIZE 		128  
//�����ջ
StackType_t Task1TaskStack[TASK1_STK_SIZE];
//������ƿ�
StaticTask_t Task1TaskTCB;
//������
TaskHandle_t Task1Task_Handler;
//������
void task1_task(void *pvParameters);

//�������ȼ�
#define TASK2_TASK_PRIO		3
//�����ջ��С	
#define TASK2_STK_SIZE 		128 
//�����ջ
StackType_t Task2TaskStack[TASK2_STK_SIZE];
//������ƿ�
StaticTask_t Task2TaskTCB;
//������
TaskHandle_t Task2Task_Handler;
//������
void task2_task(void *pvParameters);

//LCDˢ��ʱʹ�õ���ɫ
int lcd_discolor[14]={	WHITE, BLACK, BLUE,  BRED,      
						GRED,  GBLUE, RED,   MAGENTA,       	 
						GREEN, CYAN,  YELLOW,BROWN, 			
						BRRED, GRAY };

//��ȡ��������������ջ��������ƿ��ڴ棬��Ϊ������ʹ�õ�
//��̬�ڴ棬��˿�������������ջ��������ƿ���ڴ��Ӧ��
//���û����ṩ��FreeRTOS�ṩ�˽ӿں���vApplicationGetIdleTaskMemory()
//ʵ�ִ˺������ɡ�
//ppxIdleTaskTCBBuffer:������ƿ��ڴ�
//ppxIdleTaskStackBuffer:�����ջ�ڴ�
//pulIdleTaskStackSize:�����ջ��С
void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer, 
								   StackType_t **ppxIdleTaskStackBuffer, 
								   uint32_t *pulIdleTaskStackSize)
{
	*ppxIdleTaskTCBBuffer=&IdleTaskTCB;
	*ppxIdleTaskStackBuffer=IdleTaskStack;
	*pulIdleTaskStackSize=configMINIMAL_STACK_SIZE;
}

//��ȡ��ʱ����������������ջ��������ƿ��ڴ�
//ppxTimerTaskTCBBuffer:������ƿ��ڴ�
//ppxTimerTaskStackBuffer:�����ջ�ڴ�
//pulTimerTaskStackSize:�����ջ��С
void vApplicationGetTimerTaskMemory(StaticTask_t **ppxTimerTaskTCBBuffer, 
									StackType_t **ppxTimerTaskStackBuffer, 
									uint32_t *pulTimerTaskStackSize)
{
	*ppxTimerTaskTCBBuffer=&TimerTaskTCB;
	*ppxTimerTaskStackBuffer=TimerTaskStack;
	*pulTimerTaskStackSize=configTIMER_TASK_STACK_DEPTH;
}

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);//����ϵͳ�ж����ȼ�����4	 
	delay_init();	    				//��ʱ������ʼ��	 
	uart_init(115200);					//��ʼ������
	LED_Init();		  					//��ʼ��LED
	LCD_Init();							//��ʼ��LCD
	
    POINT_COLOR = RED;
	LCD_ShowString(30,10,200,16,16,"ATK STM32F103/407");	
	LCD_ShowString(30,30,200,16,16,"FreeRTOS Examp 6-2");
	LCD_ShowString(30,50,200,16,16,"Task Creat and Del");
	LCD_ShowString(30,70,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(30,90,200,16,16,"2016/11/25");
	
    //������ʼ����
	StartTask_Handler=xTaskCreateStatic((TaskFunction_t	)start_task,		//������
										(const char* 	)"start_task",		//��������
										(uint32_t 		)START_STK_SIZE,	//�����ջ��С
										(void* 		  	)NULL,				//���ݸ��������Ĳ���
										(UBaseType_t 	)START_TASK_PRIO, 	//�������ȼ�
										(StackType_t*   )StartTaskStack,	//�����ջ
										(StaticTask_t*  )&StartTaskTCB);	//������ƿ�              
    vTaskStartScheduler();          //�����������
}

//��ʼ����������
void start_task(void *pvParameters)
{
    taskENTER_CRITICAL();           //�����ٽ���
    //����TASK1����
	Task1Task_Handler=xTaskCreateStatic((TaskFunction_t	)task1_task,		
										(const char* 	)"task1_task",		
										(uint32_t 		)TASK1_STK_SIZE,	
										(void* 		  	)NULL,				
										(UBaseType_t 	)TASK1_TASK_PRIO, 	
										(StackType_t*   )Task1TaskStack,	
										(StaticTask_t*  )&Task1TaskTCB);	
    //����TASK2����
	Task2Task_Handler=xTaskCreateStatic((TaskFunction_t	)task2_task,		
										(const char* 	)"task2_task",		
										(uint32_t 		)TASK2_STK_SIZE,	
										(void* 		  	)NULL,				
										(UBaseType_t 	)TASK2_TASK_PRIO, 	
										(StackType_t*   )Task2TaskStack,	
										(StaticTask_t*  )&Task2TaskTCB);
    vTaskDelete(StartTask_Handler); //ɾ����ʼ����
    taskEXIT_CRITICAL();            //�˳��ٽ���
}

//task1������
void task1_task(void *pvParameters)
{
	
	
	

	
	while(1)
	{
		
		 LED1=!LED1;
		
		
        vTaskDelay(1000);                           //��ʱ1s��Ҳ����1000��ʱ�ӽ���	
	}
}

//task2������
void task2_task(void *pvParameters)
{
	u8 task2_num=0;
	
	while(1)
	{
	    LED0=!LED0;
		vTaskDelay(1000);    
	}
}

