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

  /*Copy new argument vector, skipping any logical operators.*/
  for (i = 0; i < count; i++) {
    if (strcmp(argv[i], "&&") == 0 || strcmp(argv[i], "||") == 0) {
      continue;
    }

    new_argv[k++] = strdup(argv[i]);
  }

  /* Add null pointer to end of last argument vector */
  new_argv[k] = NULL;

  /* Execute the last command */
  if (execve(new_argv[0], new_argv, NULL) == -1) {
    perror("execve");
    return;
  }

  /* Free the memory allocated for the new argument vector.*/
  for (i = 0; i < k; i++) {
    free(new_argv[i]);
  }
  free(new_argv);
}
