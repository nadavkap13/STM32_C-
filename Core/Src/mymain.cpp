#include <stdio.h>
#include "mymain.h"
#include "main.h"
#include "BUTTON.h"
#include "LED.h"
#include "myTime.h"
#include "Cli.h"
#include "comtask.h"


LED ledblue = LED(LD1_GPIO_Port,LD1_Pin,0,0,0,LED_STATE_OFF);
BUTTON pb3 = BUTTON(buttonPB3_GPIO_Port,buttonPB3_Pin);
BUTTON pa10 = BUTTON(buttonPA10_GPIO_Port,buttonPA10_Pin);
Time time1 = Time(50, 30, 14);
Time time2 = Time(22,34,2);
Time times[10];
CliContainer container[10];
int blinkOn = 0;
int _write(int fd, char* ptr, int len)
{
	HAL_UART_Transmit(&huart2, (uint8_t *) ptr, len, HAL_MAX_DELAY);
	return len;
}
void mymain(){
	initCLI();
//	Time time3 = time1+(time2);
//	printf("time1 is %s \r\n",time1.toString());
//	printf("time1 is %s \r\n",time3.toString());
}
void myloop(){
	if (commTask()){
		 handleCommand();
	}
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(blinkOn== 1){
		ledblue.Led_Blink();
	}
}

//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
//{
//	if(pa10.Change_State() == 0){
//		ledblue.LEDchangeState();
//	}
//}

