#ifndef INC_TIMERTASK_H_
#define INC_TIMERTASK_H_

class TimerTask{
public:
	virtual void doInterrupt() = 0;
	virtual ~TimerTask(){}
};
void RegisterCallbacks(TimerTask * Task);
void MainTimer_UnregisterCallback(TimerTask * Task);

#endif /* INC_TIMERTASK_H_ */
