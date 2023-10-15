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
 
size_t len;
char *line;
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
    checkline = getline(&input, &s, stdin);
    if (checkline == -1) {
      perror("Error reading input:");
      free(input);
      free(input_cp);
      free(argv);
      return (-1);
    }
      else if (checkline == 1 && input[0] == '\n')
  {
    /* empty input, do nothing*/
    continue;
  }
  else if (strcmp(input, "exit\n") == 0)
  {
    /* user entered "exit", quit program */
    free(input);
    free(input_cp);
    free(argv); 
    return (0);
  }

    input_cp = malloc(sizeof(char) * (checkline + 1));
    if (input_cp == NULL) {
      perror("Error allocating memory:");
      free(input);
      free(argv);
      return (-1);
    }
    strcpy(input_cp, input);

    tok = strtok(input, delim);
    while (tok != NULL) {
      tok_counter++;
      tok = strtok(NULL, delim);
    }
    tok_counter++;

    argv = malloc(sizeof(char *) * tok_counter);
    if (argv == NULL) {
      perror("Error allocating memory for argv:");
      free(input);
      free(input_cp);
      return (-1);
    }

    tok = strtok(input_cp, delim);
    for (u = 0; tok != NULL; u++) {
      argv[u] = malloc(sizeof(char) * (strlen(tok) + 1));
      if (argv[u] == NULL) {
        perror("Error allocating memory for argv[u]:");
        for (j = 0; j < u; j++) {
          free(argv[j]);
        }
        free(argv);
        free(input);
        free(input_cp);
        return (-1);
      }
      strcpy(argv[u], tok);
      tok = strtok(NULL, delim);
    }
    argv[u] = NULL;

    topcmd(argv);
  }

  free(input);
  free(input_cp);
} else {
/* shell is running in non-interactive mode */
/* execute commands from script or batch file*/
FILE *fp = fopen("script.txt", "r"); /*open script file for reading*/
    if (fp == NULL) {
        perror("Error opening script file:");
        return (-1);
    }

    line = NULL;
     len = 0;
   

    while ((checkline = getline(&line, &len, fp)) != -1) {
        /* read each line from script file */
        if (checkline == 1 && line[0] == '\n') {
            /* empty line, do nothing*/
            continue;
        }
        else {
            /* execute command*/
            char **argv = NULL;
            int tok_counter = 0;
            char *tok;
            const char *delim = " \n";

            tok = strtok(line, delim);
            while (tok != NULL) {
                tok_counter++;
                tok = strtok(NULL, delim);
            }
            tok_counter++;

            argv = malloc(sizeof(char *) * tok_counter);
            if (argv == NULL) {
                perror("Error allocating memory for argv:");
                free(line);
                fclose(fp);
                return (-1);
            }

            tok = strtok(line, delim);
            
            for (u = 0; tok != NULL; u++) {
                argv[u] = malloc(sizeof(char) * (strlen(tok) + 1));
                if (argv[u] == NULL) {
                    perror("Error allocating memory for argv[u]:");
                    for ( j = 0; j < u; j++) {
                        free(argv[j]);
                    }
                    free(argv);
                    free(line);
                    fclose(fp);
                    return (-1);
                }
                strcpy(argv[u], tok);
                tok = strtok(NULL, delim);
            }
            argv[u] = NULL;

            topcmd(argv);

            /* free memory allocated for argv*/
            for ( j = 0; j < u; j++) {
                free(argv[j]);
            }
            free(argv);
        }
    }

    /*close script file and free memory*/
    free(line);
    fclose(fp);
}


  return (0);
}


