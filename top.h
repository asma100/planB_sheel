#ifndef TOP
#define TOP
#include <sys/stat.h> 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
void print_top(char *top);
void topcmd(char **argv);
int _strlen(char *s);
char *finding_path(char *command);
/*void read_command(char *command, size_t size);
  void execute_command(const char *command);*/


#endif
