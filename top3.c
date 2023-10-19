#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "top.h"

/**
 * main-function for the shell
 * Return: the coun number
*/


int main(void)
{
char *input = NULL;
int status = 0;
while (1)
{
if (isatty(STDIN_FILENO))
print_top("top$");
inputtop(input, sizeof(input), status);
status++;
}
free(input);

return (0);

}
