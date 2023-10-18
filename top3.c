#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "top.h"



int main(void) {
char **arr = NULL;
 char *input = NULL;
/*char *input_cp = NULL;*/
 const char *delim = " \t\n";
if (isatty (STDIN_FILENO)) {
/* shell is running in interactive mode */
/* display prompt and accept input from user */
 while (1) {
 print_top("top$");
input= inputtop (input,sizeof(input));
 Parse(input,delim);


 }
 free(input);
/* free(input_cp);*/
} else {
/* shell is running in non-interactive mode */
/* execute commands from script or batch file*/


 char *line = NULL;
 size_t len = 0;
 ssize_t checkline;

input= inputtop (input,sizeof(line));
 Parse(line,delim);
free(arr);
free(line);


 return (0);
}
