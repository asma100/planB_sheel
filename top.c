#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "top.h"
int _strlen(char *s)
{
int cou = 0;
while (*s != '\0')
{
s++;
cou++;
}
return (cou);
}
int main(void)
{
  char *input = NULL;
  ssize_t checkline;
  size_t s = 0;
  char *input_cp = NULL;
  char **argv;
  char *tok;
  int tok_counter =0;
  int u = 0;
const char *delim = " \n";
  while (1)
  {
print_top("top$");
checkline = getline(&input, &s, stdin);
if(checkline == -1)
 {  
return (-1); 
}
input_cp = malloc(sizeof(char) * checkline);
if (input_cp == NULL){
return (-1);
}
 strcpy(input_cp,input);
 if (checkline == -1){
print_top("Exiting shell....\n");
return (-1);
}
else {
tok = strtok(input, delim);
while (tok != NULL){
tok_counter++;
tok = strtok(NULL, delim);
}
tok_counter++;
argv = malloc(sizeof(char *) * tok_counter);
tok = strtok(input_cp, delim);
for (u=0; tok != NULL; u++){
argv[u] = malloc(sizeof(char) * strlen(tok));
strcpy(argv[u], tok);
tok = strtok(NULL, delim);
        }
argv[u] = NULL;
topcmd(argv);
if (access("usr/bin/input", F_OK) != 0){
print_top("Command does not exist.\n");
}
}
}
free(argv); 
free(input);
free(input_cp);
  return (0);
}
