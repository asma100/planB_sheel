#include "top.h" 
char *inputtop(char *input) {
  ssize_t checkline;
  const char *delim = " \t\n";
  size_t len = 0;

  checkline = getline(&input, &len, stdin);
  if (checkline == -1) {
    if (feof(stdin)) {
      printf("The user has finished entering input.\n");
    } else {
      perror("Error reading input:");
    }
    return NULL;
  } else if (checkline == 1 && input[0] == '\n') {
    /* empty input, do nothing */
    return NULL;
  } else if (strcmp(input, "exit\n") == 0) {
    /* user wants to exit the program */
    exit(EXIT_SUCCESS);
  }

  return input;
}
