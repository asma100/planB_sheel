#include "top.h"
void topcmd(char **argv){
    char *cmd = NULL, *acmd = NULL;
 
  
    pid_t pid ;
   if (argv){
        /* get the command */
        cmd = argv[0];

        /* generate the path to this command before passing it to execve */
        acmd = finding_path(cmd);

   if (acmd == NULL) {
          perror("Error:");
          return;
        }
        /* create a child process to execute the command */
         pid = fork();
        if (pid == -1){
            perror("Error:");
        }
        else if (pid == 0){ /* child process */
            /* execute the actual command with execve */
            if(strcmp(cmd, "env") == 0){
                env_builtin();
            }   
            else if (execve(acmd, argv, NULL) == -1){
                perror("Error:");
                exit(EXIT_FAILURE);
            }
        }
        else { /* parent process */
            /* wait for the child process to finish */
            int status;
            if (waitpid(pid, &status, 0) == -1){
                perror("Error:");
            }
            
        }
    }

    if(cmd != acmd){
    free(acmd);    
    }
                        
             
                
   acmd = NULL;
}
