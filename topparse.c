 #include "top.h"
void Parse(char * input, const char *delim)
{
char *tok;
char **arr = NULL;
int u, i, j, tok_counter = 0;
char *input_cp = strdup(input);
if (input_cp == NULL)
{
perror("Error allocating memory:");
free(input);
return;
}
if (input[0] == '\0')
{
free(input_cp);
return ;
}
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
return ;
}
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
strcpy(arr[u], tok);
tok = strtok(NULL, delim);
}
arr[u] = NULL;
topcmd(arr);
for (i = 0; i < u; i++)
free(arr[i]);
free(arr);
free(input_cp);
}
