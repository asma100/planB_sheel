#include "top.h"
char **comment(char **arr, int tok_counter)
{
    int i = 0, j = 0, count = 0;
    char **ar = malloc(sizeof(char*) * (tok_counter + 1));
    while(arr[i] != NULL)
    {
        j = 0;
        while(arr[i][j] != '\0')
        {
            if(arr[i][j] == '#')
            {
                goto next;
            }
            j++;
        }
        ar[count] = strdup(arr[i]);
        count++;
    next:
        i++;
    }
    ar[count] = NULL;
   
    free(arr);
   
  
    return ar; 
}
