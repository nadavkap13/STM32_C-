#ifndef INC_MYTIME_H_
#define INC_MYTIME_H_
#include "main.h"
#include <stdio.h>
#include <string.h>

class Time{
private:
	int sec;
	int min;
	int hour;
	char buff[9];
public:
	Time();
	Time(int sec, int min, int hour);
	Time(const Time & tmp):
		sec(tmp.sec),min(tmp.min),hour(tmp.hour)
	{
		memset(buff, 0, sizeof(buff));
	}

	Time & operator=(const Time & tmp){
		 if(&tmp != this){
			 sec = tmp.sec;
			 min = tmp.min;
			 hour = tmp.hour;
			 strcpy(buff,tmp.buff);
		 }
		 return *this;
	}
	bool operator==(const Time & other) {
		return sec == other.sec && min == other.min && hour == other.hour;
	}

	bool operator<=(const Time & other) {
		return *this == other && *this < other;
	}

	bool operator<(const Time & other) {
		if(hour > other.hour)
			return false;
		if(hour < other.hour)
			return true;

		if(min > other.min)
			return false;
		if(min < other.min)
			return true;

		if(sec > other.sec)
			return false;
		if(sec < other.sec)
			return true;

		return false;
	}

	bool operator>=(const Time & other) {
		return !(*this < other);
	}

	bool operator>(const Time & other) {
		return !(*this <= other);
	}

	bool operator!=(const Time & other) {
	        return !(*this == other);
	    }

	Time operator+=(const Time & other) {
		sec += other.sec;
		min += other.min;
		hour += other.hour;

		if(sec > 59){
			sec %= 60;
			min++;
		}
		if(min > 59){
			min %= 60;
			hour++;
		}
		if(hour > 23){
			hour %= 24;
		}
		return *this;
	}

	Time operator+(const Time & other) {
		Time res(*this);
		res+= other;
		return res;
	}

	Time operator-=(const Time & other) {
		sec -= other.sec;
		min -= other.min;
		hour -= other.hour;

		if(sec < 0){
			sec += 60;
			min--;
		}

		if(min < 0){
			min += 60;
			hour--;
		}

		if(hour < 0){
			hour += 24;
		}
		return *this;
	}

	Time operator-(const Time & other) {
		Time res(*this);
		res-= other;
		return res;
	}

	Time operator++() {
		*this+=Time(1,0,0);
		return *this;
	}

	Time operator--() {
		*this-=Time(1,0,0);
		return *this;
	}
	const char* toString();

};


#endif /* INC_MYTIME_H_ */
