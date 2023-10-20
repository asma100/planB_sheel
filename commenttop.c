#include "top.h"
char **comment(char **arr)
{
    int i = 0, j = 0;
    char **arrc = malloc(sizeof(char*) * (MAX_ARGS + 1)); 
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
    arrc[i] = NULL; 
    return arrc; 
}
