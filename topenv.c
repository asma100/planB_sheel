#include "top.h"
void env_builtin(char **argv) {

  char **envp = environ;

  while (*envp != NULL) {
    printf("%s\n", *envp);
    envp++;
  }
}