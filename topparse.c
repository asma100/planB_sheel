#include "top.h" 
char  **Parse(char * input, const char *delim)
{     
    ssize_t checkline;
    char *input_cp = NULL;
 char *tok;
 int tok_counter = 0;
 char **arr = NULL;
 int u = 0;
 int j;
    input_cp = malloc(sizeof(char) * (checkline + 1));
 if (input_cp == NULL) {
  perror("Error allocating memory:");
  free(input);

 }
 strcpy(input_cp, input);

 tok = strtok(input, delim);
 while (tok != NULL) {
  tok_counter++;
  tok = strtok(NULL, delim);
 }
 tok_counter++;

 arr = malloc(sizeof(char *) * tok_counter);
 if (arr == NULL) {
  perror("Error allocating memory for arr:");
  free(input);
  free(input_cp);

 }

 tok = strtok(input_cp, delim);
 for (u = 0; tok != NULL; u++) {
  arr[u] = malloc(sizeof(char) * (strlen(tok) + 1));
  if (arr[u] == NULL) {
  perror("Error allocating memory for arr[u]:");
  for (j = 0; j < u; j++) {
   free(arr[j]);
  }
  free(arr);
  free(input);
  free(input_cp);

  }
  strcpy(arr[u], tok);
  tok = strtok(NULL, delim);
 }
 arr[u] = NULL;

    return (arr);
}
