#include "top.h"
/**
 * Parse - function for the parsing
 * @input: input from the cmd
 * @delim: value of the delimeter
 * Return: the coun number
*/
void Parse(char *input, const char *delim)
{
char *tok;
int tok_counter = 0;
char **arr = NULL;
int  u = 0;
char *input_cp = strdup(input);
empchack(input, input_cp);
tok = strtok(input, delim);
while (tok != NULL)
{
tok_counter++;
tok = strtok(NULL, delim);
}
tok_counter++;
arr = malloc(sizeof(char *) * tok_counter);
if (arr == NULL)
{
perror("Error allocating memory for arr:");
free(input);
free(input_cp);
return;
}
tok = strtok(input_cp, delim);
for (u = 0; tok != NULL; u++)
{
arr[u] = malloc(sizeof(char) * (strlen(tok) + 2));
if (arr[u] == NULL)
{
perror("Error allocating memory for arr[u]:");
freep(arr, input_cp, u);
free(input);
return;
}
strcpy(arr[u], tok);
tok = strtok(NULL, delim);
}
arr[u] = NULL;
topcmd(arr);
freep(arr, input_cp, u);
}

/**
 * freep - free
 *@arr: array
 *@input_cp: input
 *@u: counter
 * Return: void
*/
void freep(char **arr, char *input_cp, int u)
{
int i;
for (i = 0; i < u; i++)
free(arr[i]);
free(arr);
free(input_cp);
}
/**
 * empchack - function for the environ
 *@input: input
 *@input_cp: copy of input
 *
 * Return: void
*/
void empchack(char *input, char *input_cp)
{
if (input_cp == NULL)
{
perror("Error allocating memory:");
free(input);
return;
}
if (input[0] == '\0')
{
free(input_cp);
return;
}
}
