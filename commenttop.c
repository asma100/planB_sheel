#include "top.h"
char **comment(char **arr, int tok_counter)
{
  int i = 0, count = 0, a = 0; 
  char **ar = malloc(sizeof(char*) * (tok_counter + 1));
  while(arr[i] != NULL )
  {
    int j = 0;
   while(arr[i][j] != '\0' && arr[i][j] != '#')
    {
       if(arr[i][j] != '#' && arr[i] != NULL) 
    {
      ar[count] = strdup(arr[i]);
      count++;
    }
      
        a = 1;
        
      j++;
    }
 
    if (a == 1)
    {
      break;
    }
    i++;
  }
  ar[count] = NULL;
for (i = 0; arr[i] != NULL; i++)
    free(arr[i]);
free(arr);
return ar;
}


