#include "top.h"

void topcmd(char **argv){
    char *cmd = NULL, *acmd = NULL;

    pid_t pid ;
    if (argv){
        /* get the command */
        cmd = argv[0];

        /* generate the path to this command before passing it to execve */
        acmd = finding_path(cmd);

        /* create a child process to execute the command */
        pid = fork();
        if (pid == -1){
            perror("Error:");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0) {
            /* Child process*/
            if (execve(acmd, argv, NULL) == -1) {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        } else {
            /* Parent process*/
            int status;
            if (wait(&status) == -1) {
                perror("wait");
                exit(EXIT_FAILURE);
            }
            if (WIFEXITED(status)) {
                printf("Child process exited with status %d\n", WEXITSTATUS(status));
            } else if (WIFSIGNALED(status)) {
                printf("Child process terminated by signal %d\n", WTERMSIG(status));
            }
        }
    }
}
