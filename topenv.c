#include "top.h"
/**
 * env_builtin - function for the environ
 *
 * Return: void
*/
void env_builtin(void)
{
char **env;
for (env = environ; *env != NULL; env++)
{
printf("%s\n", *env);
}
}
