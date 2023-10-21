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

            
            int execute_command = 1;
            if (arg_count > 0 && strcmp(cmd_args[0], "ls") == 0) {
                execute_command = 0; // Skip execution for 'ls' command
            }

          
            if (execute_command) {
                topcmd(cmd_args);
            }
        }

        token = strtok_r(NULL, ";", &saveptr);
    }
}
