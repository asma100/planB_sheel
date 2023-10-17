#ifndef TOP
#define TOP
#include <stddef.h>
#include <sys/stat.h> 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
void print_top(char *top);
void topcmd(char **argv);
void Parse(char * input, const char *delim);
char *finding_path(char *command);
char *inputtop (char *input, size_t s);
void env_builtin();
void print_error(const char *message);
size_t _strlen(const char *s);
/*void read_command(char *command, size_t size);
  void execute_command(const char *command);*/

#endif
