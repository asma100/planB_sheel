#include "top.h"

/**
 * handle_semicolon - function to handle commands separated by semicolons
 * @input: the input string containing commands separated by semicolons
 */
void handle_semicolon(char *input) {
    char *token;
    char *saveptr;

    token = strtok_r(input, ";", &saveptr);

    while (token != NULL) {
        char *command = comm(token);

        if (!empty(command)) {
            char *cmd_args[MAX_ARGS];
            int arg_count = 0;

            char *arg = strtok(command, " \t\n");
            while (arg != NULL) {
                cmd_args[arg_count++] = arg;
                arg = strtok(NULL, " \t\n");
            }
            cmd_args[arg_count] = NULL;

            pid_t pid = fork();
            if (pid == -1) {
                perror("fork");
            } else if (pid == 0) {
                topcmd(cmd_args);
                exit(EXIT_SUCCESS);
            } else {
                int status;
                waitpid(pid, &status, 0); 
            }
        }

        token = strtok_r(NULL, ";", &saveptr);
    }
