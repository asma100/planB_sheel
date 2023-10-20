#include "top.h"
void handle_logicalop(char **argv) {
    int i = 0;
    int j = 0;
    int k = 0;
    int count = 0;
    char **new_argv;

    /*Count the number of arguments.*/
    for (count = 0; argv[count] != NULL; count++) {
        ;
    }

    /* Allocate space for the new argument vector.*/
    new_argv = malloc(sizeof(char *) * (count + 1));

    /*Copy the arguments into the new argument vector, skipping any logical operators.*/
    for (i = 0; i < count; i++) {
        if (strcmp(argv[i], "&&") == 0 || strcmp(argv[i], "||") == 0) {
            /* Skip over logical operators */
            continue;
        }

        new_argv[k++] = strdup(argv[i]);
    }

    /* Terminate the argument vector with a NULL pointer.*/
    new_argv[k] = NULL;

    /* Execute the command with the new argument vector.*/
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
