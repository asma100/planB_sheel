#include "top.h" 
void inputtop (char *input, size_t s){
 ssize_t checkline;
checkline = getline(&input, &s, stdin);
 if (checkline == -1) {
  if (errno == EOF) {
   printf("The user has finished entering input.\n");
  } else {
  perror("Error reading input:");
  free(input);
 }
 }
  else if (checkline == 1 && input[0] == '\n')
 {
 /* empty input, do nothing*/
 print_top("top$");
 }
 else if (strcmp(input, "exit\n") == 0)
 {

 }
}
