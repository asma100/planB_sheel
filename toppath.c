#include "top.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

char *finding_path(const char *command) {
    char *command_copy;
    char *token;
    size_t path_len;
    size_t cmd_len;
    char *full_path;
    
    const char *path = getenv("PATH");
    if (path == NULL || command == NULL || command[0] == '\0') {
        return NULL;
    }

  
    command_copy = strdup(command);

    if (command_copy == NULL) {
        return NULL;
    }

   token = strtok(command_copy, ":");
    
    while (token != NULL) {
        struct stat s_buff;
       path_len = strlen(token);
        cmd_len = strlen(command);
        full_path = (char *)malloc(path_len + cmd_len + 2); 

        if (full_path == NULL) {
            free(command_copy);
            return NULL;
        }

        strcpy(full_path, token);
        strcat(full_path, "/");
        strcat(full_path, command);

        if (stat(full_path, &s_buff) == 0 && S_ISREG(s_buff.st_mode) && (s_buff.st_mode & S_IXUSR)) {
            free(command_copy);
            return full_path;
        }

        free(full_path);
        token = strtok(NULL, ":");
    }

    free(command_copy);

 
    if (access(command, X_OK) == 0) {
        return strdup(command);
    }

    return NULL;
}
