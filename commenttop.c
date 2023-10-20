#include "top.h"
char **comment(char **arr,int tok_counter)
{
    int i = 0, j = 0;
    char **arrc = malloc(sizeof(char*) * tok_counter);
    
    while(arr[i] != NULL)
    {
        j = 0;
        while(arr[i][j] != '\0')
        {
            if(arr[i][j] == '#')
            {
                arrc[i] = NULL;
                goto next;
            }
            j++;
        }
        arrc[i] = strdup(arr[i]);
        i++;
    next:
        i++; 
    }
    while( i < tok_counter) {
  arrc[i] = NULL;
        i++;
}
    
   
    return arrc; 
}
