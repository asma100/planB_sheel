
char **comment(char **arr)
{
while(arr[i] != "#"||arr[i] != NULL )
{
arrc[i]=arr[i];
free(arr[i]);
i++;
}
free(arr);
return(arrc); 
}
