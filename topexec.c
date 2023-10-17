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
   print_error("Error:\n");
   return;
  }
  /* create a child process to execute the command */
   pid = fork();
  if (pid == -1){
   print_error("Error:\n");
  }
  else if (pid == 0){ /* child process */
   /* execute the actual command with execve */
   if(strcmp(cmd, "env") == 0){
    env_builtin();
   }  
   else if (execve(acmd, argv, NULL) == -1){
    print_error("Error:\n");
    exit(EXIT_FAILURE);
   }
  }
  else { /* parent process */
   /* wait for the child process to finish */
   int status;
   if (waitpid(pid, &status, 0) == -1){
    print_error("Error:\n");
   }
    
  }
 }

 if(cmd != acmd){ 
 free(acmd);   
 }
       
    
     
 acmd = NULL;
}
