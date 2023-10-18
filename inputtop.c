#include "top.h"
void inputtop(char *input, size_t s) {
ssize_t checkline;
 const char *delim = " \t\n";
 checkline = getline(&input, &s, stdin);
  if (checkline == -1) {
   if (feof(stdin)) {
            printf("\n");
            exit(EXIT_SUCCESS);
        } else {
      perror("Error reading input:");
      free(input);
      exit(EXIT_FAILURE);
    }}
  else if (checkline == 1 && input[0] == '\n') {
    /* empty input, do nothing*/
    free(input);
    input = NULL;
    return ;
  } else if (strcmp(input, "exit\n") == 0) {
    /* user wants to exit the program */
    free(input);
    input = NULL;
    exit(EXIT_SUCCESS);
  }
Parse(input,delim);
 /* return (input);*/
}
