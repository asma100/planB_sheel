#include "top.h"
/**
 * empty - function for the user input handlin
 * @input: size of the input
 * Return: int
*/
int empty(char *input)
{
if (input == NULL)
return (1);
while (*input)
{
if (!isspace(*input))
return (0);
input++;
}
return (1);
}
/**
 * inputtop - function for the user input handling
 * @s: size of the input
 * @input: value
 * @status:0,1
 * Return: null
*/
void inputtop(char *input, size_t s, int status)
{
const char *delim = " \t\n";
int i = 0;
ssize_t checkline = getline(&input, &s, stdin);
if (checkline == -1)
{
free(input);
exit(EXIT_SUCCESS);
}
else if (strcmp(input, "exit\n") == 0)
{
free(input);
if (status == 0)
exit(0);
else
exit(2);
}
else if (strcmp(input, "env\n") == 0)
{
env_builtin();
free(input);
exit(0);
}
else
{
if (empty(input) == 1)
{
newline(input);
}
while (input[i] != '\0')
{
if (input[i] == '#')
{
input[i] = '\0';
break;
}
i++;
}
Parse(input, delim);
}
free(input);
}

void newline(char *input)
{
free(input);
return;
}
