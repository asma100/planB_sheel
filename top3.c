#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "top.h"
int main(void)
{
char **arr = NULL;
char *input = NULL;
/*char *input_cp = NULL;*/
const char *delim = " \t\n";
if (isatty (STDIN_FILENO))
{
/* shell is running in interactive mode */
while (1)
{
print_top("top$");
/*input= */inputtop (input,sizeof(input));
/*Parse(input,delim);*/
}
free(input);
}
else
{
/* shell is running in non-interactive mode */
char *line = NULL;
size_t len = 0;
ssize_t checkline;
while ((checkline = getline(&line, &len, stdin)) != -1)
{
/*read each line from standard input*/
if (checkline == 1 && line[0] == '\n')
{
/* empty line, do nothing*/
free(line);
continue;
}
else
{
Parse(line,delim);
free(arr);
free(line);
}
}
}
return (0);
}
