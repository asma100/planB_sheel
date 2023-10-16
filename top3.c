#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "top.h"

int _strlen(char *s) {
 int cou = 0;
 while (*s != '\0') {
 s++;
 cou++;
 }
 return (cou);
}

int main(void) {
 char *fp=NULL;
 char **arr = NULL;
 char *input = NULL;
char *input_cp = NULL;
 const char *delim = " \t\n";
if (isatty (STDIN_FILENO)) {
/* shell is running in interactive mode */
/* display prompt and accept input from user */
 while (1) {
 print_top("top$");
input= inputtop (input,sizeof(input));
 Parse(input,delim);

 
 }
 free(fp);
 free(input);
 free(input_cp);
} else {
/* shell is running in non-interactive mode */
/* execute commands from script or batch file*/


 char *line = NULL;
 size_t len = 0;
 ssize_t checkline;

 while ((checkline = getline(&line, &len, stdin)) != -1) {
 /*read each line from standard input*/
 if (checkline == 1 && line[0] == '\n') {
  /* empty line, do nothing*/
  continue;
 }
  
 else {
    
    
    Parse(line,delim);
    
  /* execute command*/

  topcmd(arr);
}
}
}

 return (0);
}
