void inputtop (char *input, size_t s){

checkline = getline(&input, &s, stdin);
 if (checkline == -1) {
  if (errno == EOF) {
   printf("The user has finished entering input.\n");
  } else {
  perror("Error reading input:");
  free(input);
  free(input_cp);
  free(argv);
  return (-1);
 }
 }
  else if (checkline == 1 && input[0] == '\n')
 {
 /* empty input, do nothing*/
 continue;
 }
 else if (strcmp(input, "exit\n") == 0)
 {

 return (0);
 }
}
