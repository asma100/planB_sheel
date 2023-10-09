#include "top.h"

void topcmd(char **argv){
    const char *cmd = NULL;
    if (argv){
        /* get the command */
        cmd = argv[0];
        /* execute the command with execve */
        if (execve(cmd, argv, NULL) == -1){
            perror("not found");
        };
    }
}
