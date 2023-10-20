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
    
    for (i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    
    free(arr);
   
  
    return ar; 
}
