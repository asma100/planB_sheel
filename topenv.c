#include "top.h"
void env_builtin(char **argv) {

 extern char **environ;
  
  while (*envp != NULL) {
    printf("%s\n", *envp);
    envp++;
  }
}
