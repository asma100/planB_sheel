#include "top.h"
char *inputtop(char *input, size_t s)
{
    ssize_t checkline;
    checkline = getline(&input, &s, stdin);
    if (checkline == -1)
    {
        if (feof(stdin))
        {
            printf("\n");
            exit(EXIT_SUCCESS);
        }
        else
        {
            perror("Error reading input:");
            free(input);
            exit(EXIT_FAILURE);
        }
    }
    else if (checkline == 1 && input[0] == '\n')
    {
        /* empty input, return an empty string */
        free(input);
        input = strdup("");
        return (input);
    }
    else if (strcmp(input, "exit\n") == 0)
    {
        /* user wants to exit the program */
        free(input);
        input = NULL;
        exit(EXIT_SUCCESS);
    }
    return (input);
}
