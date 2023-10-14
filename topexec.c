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
       else if (child_pid == 0) {
        // Child process
        execlp(command, command, (char *)NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        wait(NULL);
    }
}
}
