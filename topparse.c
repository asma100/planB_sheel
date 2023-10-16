char  **Parse(char * input, const char *delim)
{
    
    input_cp = malloc(sizeof(char) * (checkline + 1));
 if (input_cp == NULL) {
  perror("Error allocating memory:");
  free(input);
  free(argv);
  return (-1);
 }
 strcpy(input_cp, input);

 tok = strtok(input, delim);
 while (tok != NULL) {
  tok_counter++;
  tok = strtok(NULL, delim);
 }
 tok_counter++;

 argv = malloc(sizeof(char *) * tok_counter);
 if (argv == NULL) {
  perror("Error allocating memory for argv:");
  free(input);
  free(input_cp);
  return (-1);
 }

 tok = strtok(input_cp, delim);
 for (u = 0; tok != NULL; u++) {
  argv[u] = malloc(sizeof(char) * (strlen(tok) + 1));
  if (argv[u] == NULL) {
  perror("Error allocating memory for argv[u]:");
  for (j = 0; j < u; j++) {
   free(argv[j]);
  }
  free(argv);
  free(input);
  free(input_cp);
  return (-1);
  }
  strcpy(argv[u], tok);
  tok = strtok(NULL, delim);
 }
 argv[u] = NULL;
}
