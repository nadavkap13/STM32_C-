#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "Cli.h"
#include "LED.h"
#include "comtask.h"

extern LED ledblue;
extern int blinkOn;
class ledOn : public Cli{
private:
	LED * _led;
public:
	ledOn(LED * led){
		_led = led;
	}
	void doCommand(const char * param) override{
		blinkOn = 0;
		_led->Led_On();
	}
};
class ledOff : public Cli{
private:
	LED * _led;
public:
	ledOff(LED * led){
		_led = led;
	}
	void doCommand(const char * param) override{
		blinkOn = 0;
		_led->Led_Off();
	}
};
class ledBlink : public Cli{
private:
	LED * _led;
public:
	ledBlink(LED * led){
		_led = led;
	}
	void doCommand(const char * param) override{
		blinkOn = 1;
		_led->Led_Blink();
	}
};
class ledSetDelay : public Cli{
private:
	LED * _led;
public:
	ledSetDelay(LED * led){
		_led = led;
	}
	void doCommand(const char * param) override{
		blinkOn = 0;
		int _param = atoi(param);
		_led->LED_delay(_param);
	}
};

void initCLI(){
	RegisterCommand("ledon",new ledOn(&ledblue));
	RegisterCommand("ledoff",new ledOff(&ledblue));
	RegisterCommand("ledblink",new ledBlink(&ledblue));
	RegisterCommand("setdelay",new ledSetDelay(&ledblue));
}






















