#include "top.h"
void topcmd(char **arr)
{
    char *cmd = NULL, *acmd = NULL;
    pid_t pid;
    int fd_in, fd_out, i;

    if (arr)
    {     
        
        cmd = arr[0];
          if (cmd == '\0') {
         return ;
            }
        acmd = finding_path(cmd);
        if (acmd == NULL)
        {
            perror("Error:");
            return;
        }

        /*check for input/output redirection symbols*/
        for ( i = 1; arr[i] != NULL; i++) {
            if (strcmp(arr[i], "<") == 0) {
                /* redirect input from file*/
                fd_in = open(arr[i+1], O_RDONLY);
                if (fd_in == -1) {
                    perror("Error:");
                    return;
                }
                dup2(fd_in, STDIN_FILENO);
                close(fd_in);
                arr[i] = NULL;
                arr[i+1] = NULL;
            } else if (strcmp(arr[i], ">") == 0) {
                /* redirect output to file*/
                fd_out = open(arr[i+1], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
                if (fd_out == -1) {
                    perror("Error:");
                    return;
                }
                dup2(fd_out, STDOUT_FILENO);
                close(fd_out);
                arr[i] = NULL;
                arr[i+1] = NULL;
            }
        }

        pid = fork();
        if (pid == -1)
        {
            perror("Error:");
        }
        else if (pid == 0)
        {
            if (strcmp(cmd, "env") == 0)
            {
                env_builtin();
            }
            else if (execve(acmd, arr, NULL) == -1)
            {
                perror("Error:");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            int status;
            if (waitpid(pid, &status, 0) == -1)
            {
                perror("Error:");
            }
        }
    }
    if (cmd != acmd)
        free(acmd);
}
