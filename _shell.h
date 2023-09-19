#ifndef SHELL_H
#define SHELL_H

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void displayPrompt(void);
char *getVariableValue(char *variable);
char *replaceVariables(char *command);
char **parseCommand(char *command);
void setVariable(char *variable);
void executeCommand(char **args);
void executeCommandsFromFile(char *filename);
void runInteractiveShell(void);
int main(int argc, char *argv[]);

#endif
