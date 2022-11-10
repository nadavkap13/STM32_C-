#include <stdio.h>
#include "mymain.h"
#include "main.h"
#include "myTime.h"
#include <stdlib.h>

Time::Time(int sec, int min, int hour):
			sec(sec),min(min),hour(hour)
{
	memset(buff, 0, sizeof(buff));
}

Time::Time():
			sec(0),min(0),hour(0)
{
	memset(buff, 0, sizeof(buff));
}
const char* Time::toString()
{
	sprintf(buff,"%02d:%02d:%02d",hour,min,sec);
	return buff;
}

