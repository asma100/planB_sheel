#include "top.h"

/**
 * handle_semicolon - function to handle commands separated by semicolons
 * @input: the input string containing commands separated by semicolons
 */
void handle_semicolon(char *input) {
  char *token;
  char **commands = malloc(sizeof(char *) * MAX_ARGS);
  int i = 0;

  /* Tokenize input based on semicolons */
  token = strtok(input, ";");
  while (token != NULL) {
    commands[i++] = strdup(token);
    token = strtok(NULL, ";");
  }
  commands[i] = NULL;

  /* Execute each command */
  for (int j = 0; j < i; j++) {
    Parse(commands[j], " \t\n");
    topcmd(argv);
  }

  /* Free memory */
  for (int j = 0; j < i; j++) {
    free(commands[j]);
  }
  free(commands);
}
