#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "Cli.h"
#include "LED.h"
#include "comtask.h"
#include "TimerTask.h"


extern int blinkOn;
TimerTask * taskcontainer[10];
int MainTimer_funcounter = 0;
void RegisterCallbacks(TimerTask * Task){
	taskcontainer[MainTimer_funcounter] = Task;
	MainTimer_funcounter++;
}
void MainTimer_UnregisterCallback(TimerTask * Task) {
	int remove = 0;
	int boolcount = 0;

	for (int j = 0; j < MainTimer_funcounter; j++) {
		if (taskcontainer[j].TIMER_Func == TIMER_Func && MainTimer_arry[j].obj == obj) {
			taskcontainer[j].TIMER_Func = NULL;
			remove = 1;
			boolcount = j;
			break;
		}
	}

	if (remove == 1 && MainTimer_funcounter > 0) {
		MainTimer_funcounter--;
		taskcontainer[boolcount].TIMER_Func = taskcontainer[MainTimer_funcounter].TIMER_Func;
		taskcontainer[boolcount].obj = taskcontainer[MainTimer_funcounter].obj;
	}
}
void MainTimerInterrupt() {
	for (int j = 0; j < MainTimer_funcounter; j++) {

		taskcontainer[j]->doInterrupt();
	}

}

class ledOnInterrupt : public TimerTask{
private:
	LED * _led;
public:
	void doInterrupt() override{
		blinkOn = 1;
		_led->Led_Blink();
	}
};
