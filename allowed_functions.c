#include "top.h"
size_t _strlen(const char *s) {
 int cou = 0;
 while (*s != '\0') {
 s++;
 cou++;
 }
 return (cou);
}

void print_error(const char *message) {
  size_t len = strlen(message);
  write(STDERR_FILENO, message, len);

}

parsetok(char *input_cp, const char *delim)
{
char *tok;
char *input;
char **arr = NULL;
int u, i, j;
tok = strtok(input_cp, delim);
for (u = 0; tok != NULL; u++)
{
arr[u] = malloc(sizeof(char) * (strlen(tok) + 2));
if (arr[u] == NULL)
{
perror("Error allocating memory for arr[u]:");
for (j = 0; j < u; j++)
free(arr[j]);
free(arr);
free(input);
free(input_cp);
return;
}

tok = strtok(NULL, delim);
}
arr[u] = NULL;
topcmd(arr);
for (i = 0; i < u; i++)
free(arr[i]);
free(arr);
free(input_cp);
}
