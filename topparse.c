 #include "top.h"
 void Parse(char * input, const char *delim)
{
  /*  size_t s;
   ssize_t checkline;
   */
    char *tok;
    int tok_counter = 0;
    char **arr = NULL;
    int u = 0; 
   int j;
  int i;
    char *input_cp = strdup(input);

 /*   checkline = getline(&input, &s, stdin);
 input_cp = malloc(sizeof(char) * (checkline + 1));
    strcpy(input_cp, input);*/
    if (input_cp == NULL) {
        perror("Error allocating memory:");
        free(input);
        return;
    }
    
  /* Check for an empty input string */
  if (input[0] == '\0') {
    free(input_cp);
    return ;
  }
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
        return ;
    }

    tok = strtok(input_cp, delim);
    for (u = 0; tok != NULL; u++) {
        arr[u] = malloc(sizeof(char) * (strlen(tok) + 2));
        if (arr[u] == NULL) {
            perror("Error allocating memory for arr[u]:");
         for (j = 0; j < u; j++) {
                free(arr[j]);
            }
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
 
   for (i = 0; i < u; i++) {
        free(arr[i]);
    }  
   

    free(arr);
 
   free(input_cp);


 
}
