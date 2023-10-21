#include "top.h"
/**
 * handle_logicalop - function  handlel ogical op
 * @argv: pointer to the command value
 * Return: void
 */
void handle_logicalop(char **argv) {
  int i = 0;
  int k = 0;
  int count = 0;
  char **new_argv;

  /*Count the number of arguments.*/
  for (count = 0; argv[count] != NULL; count++) {
    ;
  }

  /* Allocate space for the new argument vector.*/
  new_argv = malloc(sizeof(char *) * (count + 1));

  /* Loop through all commands separated by logical operators */
  while (i < count) {
    k = 0;

    /* Copy new argument vector, skipping any logical operators */
    while (argv[i] != NULL && strcmp(argv[i], "&&") != 0 && strcmp(argv[i], "") != 0) {
      new_argv[k++] = strdup(argv[i++]);
    }

    /* Add null pointer to end of argument vector */
    new_argv[k] = NULL;

    /* Execute the command */
    if (execvp(new_argv[0], new_argv) == -1) {
      perror("execvp");
      return;
    }

    /* Skip over logical operator */
    i++;
  }
}
