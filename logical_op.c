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
            /* Execute the previous command */
            if (execvp(new_argv[0], new_argv) == -1) {
                perror("execvp");
                return;
            }
            /* Reset the argument vector for the next command */
            k = 0;
            continue;
        }

        new_argv[k++] = strdup(argv[i]);
    }

    /* Execute the last command */
    if (execvp(new_argv[0], new_argv) == -1) {
        perror("execvp");
        return;
    }

    /* Free the memory allocated for the new argument vector.*/
    for (i = 0; i < k; i++) {
        free(new_argv[i]);
    }
    free(new_argv);
}
