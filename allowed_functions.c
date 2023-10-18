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

char **parsetok(char * input_cp, const char *delim)
{
 char **arr = NULL;
int u, j, tok_counter = 0;
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
return(NULL);
}
strcpy(arr[u], tok);
tok = strtok(NULL, delim);
}
 retrun (arr);
}
