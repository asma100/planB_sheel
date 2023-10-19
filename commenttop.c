
char **comment(char **arr)
{
while(arr[i] != "#" )
{
arrc[i]=arr[i];
free(arr[i]);
i++;
}
free(arr);
return(arrc); 
}
