#include "top.h"
#include <stdlib.h>
#include <stdio.h>

int _strlen(char *s) {
  int cou = 0;
  while (*s != '\0') {
    s++;
    cou++;
  }
  return (cou);
}

int main(void) {
  char **arr = NULL;
  char *input = NULL;
  const char *delim = " \t\n";
  
  if (isatty(STDIN_FILENO)) {
    /* shell is running in interactive mode */
    /* display prompt and accept input from the user */
    while (1) {
      print_top("top$");
      input = inputtop(input);
      
      
      if (input == NULL) {
        continue;
      }
      
      
      arr = Parse(input, delim);
      if (arr != NULL) {
        topcmd(arr);
        free(arr);
      }
      
     
      free(input);
    }
  } else {
    /* shell is running in non-interactive mode */
    /* execute commands from a script or batch file */
    char *line = NULL;
    size_t len = 0;
    ssize_t checkline;
    
    while ((checkline = getline(&line, &len, stdin)) != -1) {
      /* read each line from standard input */
      if (checkline == 1 && line[0] == '\n') {
        /* empty line, do nothing */
        continue;
      } else {
        arr = Parse(line, delim);
        if (arr != NULL) {
          topcmd(arr);
          free(arr);
        }
      }
    }
    
    free(line);
  }
  
  return (0);
}
