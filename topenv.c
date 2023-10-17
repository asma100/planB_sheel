#include "top.h"
void env_builtin() {
   extern char **environ;
 char **env;
    for (env = environ; *env != NULL; env++) {
        printf("%s\n", *env);
    }
}
