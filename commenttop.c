#include "top.h"
char **comment(char **arr)
{
    int i = 0;
    char **arrc = malloc(sizeof(char*) * (MAX_ARGS + 1)); 
    while(arr[i] != NULL && strcmp(arr[i], "#") != 0)
    {
        arrc[i] = arr[i];
        i++;
    }
    arrc[i] = NULL; 
    return arrc; 
}
