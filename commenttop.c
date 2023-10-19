#include "top"
char **comment(char **arr)
{
  int i = 0;
  char **arrc = malloc(sizeof(char*) * (MAX_ARGS + 1));

  while(arr[i] != NULL)
  {
    int j = 0;
    while(arr[i][j] != '\0')
    {
      if(arr[i][j] == '#')
      {
        arrc[i] = NULL;
        break; 
      }
      j++;
    }
    arrc[i] = arr[i];
    i++;
  }

  arrc[i] = NULL;

  return arrc;
}
