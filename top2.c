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
 

 char *input = NULL;
 ssize_t checkline;
 size_t s = 0;
 char *input_cp = NULL;
 char *tok;
 int tok_counter = 0;
 char **argv = NULL;
 int u = 0;
 int j;
 const char *delim = " \t\n";
if (isatty (STDIN_FILENO)) {
/* shell is running in interactive mode */
/* display prompt and accept input from user */
 while (1) {
 print_top("top$");
 inputtop (input,sizeof(input));

 Parse(input,delim);
 topcmd(argv);
 }

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
      
      
       Parse(input,delim);
      
   /* execute command*/

   topcmd(argv);
}
}
}

 return (0);
}
