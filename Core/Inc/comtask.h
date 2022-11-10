#ifndef INC_COMTASK_H_
#define INC_COMTASK_H_
#include "Cli.h"

typedef struct CliContainer{
	char* CommandName;
	Cli* command;
}CliContainer;
int commTask();
void handleCommand();

//void RegisterCallbacks(HandlerFunc onFunc, HandlerFunc offFunc,void* object);
void RegisterCommand(char* CommandName, Cli * clicommand);

#endif /* INC_COMTASK_H_ */
