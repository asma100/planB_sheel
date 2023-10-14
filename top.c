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
int main(int ac, char **argv)
{
  char *input = NULL;
  ssize_t checkline;
  size_t s = 0;
  (void) ac;
  (void) argv;
  while (1)
  {
print_top("top$");
checkline = getline(&input, &s, stdin);
if(checkline == -1)
  {  free(input);
   return (-1); 
}

}
free(input); 
  return (0);
}
