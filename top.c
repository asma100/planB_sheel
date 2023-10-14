#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "top.h"
int _strlen(char *s)
{
int cou = 0;
while (*s != '\0')
{
s++;
cou++;
}
return (cou);
}
int main(void)
{
    char *input = NULL;
    ssize_t checkline;
    size_t s = 0;
    char *input_cp = NULL;
    char *tok;
    int tok_counter = 0;
    char **argv = NULL;
    int u = 0;
    int j;
    const char *delim = " \n";

    while (1)
    {
        print_top("top$");
        checkline = getline(&input, &s, stdin);
        if (checkline == -1)
        {
            perror("Error reading input:");
            free(input);
            free(input_cp);
            free(argv); 
            return (-1);
        }

        input_cp = malloc(sizeof(char) * (checkline + 1));
        if (input_cp == NULL)
        {
            perror("Error allocating memory:");
            free(input);
            free(argv); 
            return (-1);
        }
        strcpy(input_cp, input);

        tok = strtok(input, delim);
        while (tok != NULL)
        {
            tok_counter++;
            tok = strtok(NULL, delim);
        }
        tok_counter++;
        
        argv = malloc(sizeof(char *) * tok_counter);
        if (argv == NULL)
        {
            perror("Error allocating memory for argv:");
            free(input);
            free(input_cp);
            return (-1);
        }
        
        tok = strtok(input_cp, delim);
        for (u = 0; tok != NULL; u++)
        {
            argv[u] = malloc(sizeof(char) * (strlen(tok) + 1));
            if (argv[u] == NULL)
            {
                perror("Error allocating memory for argv[u]:");
                for (j = 0; j < u; j++)
                {
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
        
        for (u = 0; u < tok_counter; u++)
        {
            free(argv[u]);
        }
        free(argv);
    }

    free(input);
    free(input_cp);
    return (0);
}
