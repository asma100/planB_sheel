#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "top.h"

int main(void)
{
    char **arr = NULL;
    char *input = NULL;
    const char *delim = " \t\n";

    if (isatty(STDIN_FILENO))
    {
        /* shell is running in interactive mode */
        while (1)
        {
            print_top("top$");
            input = inputtop(input, sizeof(input));
            if (input[0] == '\0') {
                /* empty input, do nothing */
                continue;
            }
            Parse(input, delim);
        }
        free(input);
    }
    else
    {
        /* shell is running in non-interactive mode */
        char *line = NULL;
        size_t len = 0;
        ssize_t checkline;

        checkline = getline(&line, &len, stdin);
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
                free(line);
                exit(EXIT_FAILURE);
            }
        }

        while (checkline != -1)
        {
            /* read each line from standard input */
            if (checkline == 1 && line[0] == '\n')
            {
                /* empty line, do nothing */
                free(line);
                continue;
            }
            else if (strcmp(line, "exit\n") == 0)
            {
                /* user wants to exit the program */
                free(line);
                line = NULL;
                exit(EXIT_SUCCESS);
            }
            else
            {
                if (line[0] != '\0') {
                    Parse(line, delim);
                }
                free(arr);
                free(line);
            }

            checkline = getline(&line, &len, stdin);
        }
    }

    return 0;
}
