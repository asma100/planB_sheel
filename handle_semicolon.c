#include "top.h"

/**
 * handle_semicolon - function to handle commands separated by semicolons
 * @input: the input string containing commands separated by semicolons
 */
void handle_semicolon(char *input) {
 
    char *clean_input = comm(input);

    char *token;
    char *saveptr;

    
    token = strtok_r(clean_input, ";", &saveptr);

    while (token != NULL) {
        if (!empty(token)) {
         
            char *cmd_args[MAX_ARGS];
            int arg_count = 0;

           
            char *arg = strtok(token, " \t\n");
            while (arg != NULL) {
                cmd_args[arg_count++] = arg;
                arg = strtok(NULL, " \t\n");
            }
            cmd_args[arg_count] = NULL; 

           
            topcmd(cmd_args);
        }

       
        token = strtok_r(NULL, ";", &saveptr);
    }
}
