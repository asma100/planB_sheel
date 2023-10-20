#include "top.h"
/*char **comment(char **arr, int tok_counter)
{
  int i = 0, count = 0, a = 0; 
  char **ar = malloc(sizeof(char*) * (tok_counter + 1));
  while(arr[i] != NULL )
  {
    int j = 0;
    while(arr[i][j] != '\0')
    {
      if(arr[i][j] == '#')
      {
        a = 1;
        break;
      }
      j++;
    }
    if(arr[i][j] != '#' && arr[i] != NULL) 
    {
      ar[count] = strdup(arr[i]);
      count++;
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
}*/

char **comment(char **argv, int argc) {
  int i, j, k;
  char **new_argv;


  for (i = 0; argv[i] != NULL; i++) {
    ;
  }


  new_argv = malloc(sizeof(char *) * (i + 1));

 
  k = 0;
  for (i = 0; i < argc; i++) {
    for (j = 0; argv[i][j] != '\0' && argv[i][j] != '#'; j++) {
      ;
    }
    if (argv[i][j] == '\0') {
      new_argv[k++] = strdup(argv[i]);
    }
  }

 
  new_argv[k] = NULL;

  return new_argv;
}
