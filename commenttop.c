#include "top.h"
char **comment(char **arr)
{
int i = 0;
char **arrc = NULL;
while(arr[i] != "#"||arr[i] != NULL )
{
arrc[i]=arr[i];
free(arr[i]);
i++;
}
free(arr);
return(arrc); 
}
