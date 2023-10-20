#include "top.h"
/*int _strlen(char *s) {
 int cou = 0;
 while (*s != '\0') {
 s++;
 cou++;
 }
 return (cou);
}*/

void print_error(const char *message) {
  size_t len = strlen(message);
  write(STDERR_FILENO, message, len);

}

void parsetok(char *input_cp,char *input)
{
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
}

void freea(void)
{
 
}


