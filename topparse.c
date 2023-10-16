#include "top.h"
char **Parse(char *input, const char *delim) {
  char *tok;
   int u;
  int j;
  char *input_cp = strdup(input); 
  if (input_cp == NULL) {
    perror("Error allocating memory for input_cp:");
    return NULL;
  }

  
  int tok_counter = 0;
  char **arr = NULL;

  tok = strtok(input_cp, delim);
  while (tok != NULL) {
    tok_counter++;
    tok = strtok(NULL, delim);
  }
  tok_counter++;

  arr = (char **)malloc(sizeof(char *) * tok_counter);
  if (arr == NULL) {
    perror("Error allocating memory for arr:");
    free(input_cp);
    return NULL;
  }

  tok = strtok(input_cp, delim);
 
  for (u = 0; tok != NULL; u++) {
    arr[u] = strdup(tok); 
    if (arr[u] == NULL) {
      perror("Error allocating memory for arr[u]:");
      for ( j = 0; j < u; j++) {
        free(arr[j]);
      }
      free(arr);
      free(input_cp);
      return NULL;
    }
    tok = strtok(NULL, delim);
  }
  arr[u] = NULL;

  free(input_cp);

  return arr;
}
