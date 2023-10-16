#include "top.h" 
void inputtop(char *input, size_t s) {
  ssize_t checkline;

  checkline = getline(&input, &s, stdin);
  if (checkline == -1) {
    if (errno == EOF) {
      printf("The user has finished entering input.\n");
    } else {
      perror("Error reading input:");
      free(input);
      exit(EXIT_FAILURE);
    }
  } else if (checkline == 1 && input[0] == '\n')
  {
    /* empty input, do nothing*/
 return;
  }
  else if (strcmp(input, "exit\n") == 0) {
    /* user wants to exit the program */
    exit(EXIT_SUCCESS);
  }
  else
  {
     Parse(input,delim);
  }
}
