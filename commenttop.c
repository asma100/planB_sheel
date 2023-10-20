char **comment(char **arr, int tok_counter)
{
    int i = 0, count = 0;
    char **ar = malloc(sizeof(char*) * (tok_counter + 1));
    while(arr[i] != NULL)
    {
        int j = 0;
        while(arr[i][j] != '\0')
        {
            if(arr[i][j] == '#')
            {
                break;
            }
            j++;
        }
        if(arr[i][j] != '#') // Only add if '#' was not found
        {
            ar[count] = strdup(arr[i]);
            count++;
        }
        i++;
    }
    ar[count] = NULL;

    for (i = 0; arr[i] != NULL; i++)
        free(arr[i]);

    free(arr);

    return ar;
}
