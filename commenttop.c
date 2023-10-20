#include "top.h"
char **comment(char **arr,int tok_counter)
{
    int i = 0, j = 0,m = 0;
    char **ar = malloc(sizeof(char*) * tok_counter);
     char **arrc;
    while(arr[i] != NULL)
    {
        j = 0;
        while(arr[i][j] != '\0')
        {
            if(arr[i][j] == '#')
            {
                ar[i] = NULL;
                goto next;
            }
            j++;
        }
        ar[i] = strdup(arr[i]);
        i++;
    next:
        i++; 
    }
     arrc = malloc(sizeof(char*) * i);
    while (m<i)
       {  if (ar[m] != NULL) 
       {
           ar[m] = strdup(arr[m]); 
       }
       m++;
       }
    
    free(arr);
    free(ar);
    
   
    return arrc; 
}
