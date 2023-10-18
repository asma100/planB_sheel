#include "top.h"
void topcmd(char **argv)
{
    char *cmd = NULL, *acmd = NULL;
    pid_t pid;
    int fd_in, fd_out, i;

    if (argv)
    {
        cmd = argv[0];
        acmd = finding_path(cmd);
        if (acmd == NULL)
        {
            perror("Error:");
            return;
        }

        /*check for input/output redirection symbols*/
        for ( i = 1; argv[i] != NULL; i++) {
            if (strcmp(argv[i], "<") == 0) {
                /* redirect input from file*/
                fd_in = open(argv[i+1], O_RDONLY);
                if (fd_in == -1) {
                    perror("Error:");
                    return;
                }
                dup2(fd_in, STDIN_FILENO);
                close(fd_in);
                argv[i] = NULL;
                argv[i+1] = NULL;
            } else if (strcmp(argv[i], ">") == 0) {
                /* redirect output to file*/
                fd_out = open(argv[i+1], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
                if (fd_out == -1) {
                    perror("Error:");
                    return;
                }
                dup2(fd_out, STDOUT_FILENO);
                close(fd_out);
                argv[i] = NULL;
                argv[i+1] = NULL;
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
            else if (execve(acmd, argv, NULL) == -1)
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
