#ifndef TOP
#define TOP
#include <stddef.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void print_top(char *top);
void topcmd(char **argv);
int _strlen(char *s);
char **Parse(char *input, const char *delim);
char *finding_path(char *command);
char *inputtop(char *input);

#endif
