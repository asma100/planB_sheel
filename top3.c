#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "top.h"



int main(void) {
 char *input = NULL;
/*char *input_cp = NULL;*/
if (isatty (STDIN_FILENO)) {
/* shell is running in interactive mode */
/* display prompt and accept input from user */
 while (1) {
 print_top("top$");
 inputtop (input,sizeof(input));



 }
 free(input);
/* free(input_cp);*/
} else {
/* shell is running in non-interactive mode */
/* execute commands from script or batch file*/






inputtop (input,sizeof(input));

free(input);


 return (0);
}
}
