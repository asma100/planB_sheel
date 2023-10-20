#include "top.h"
void topcmd(char **argv)
{
char *cmd = NULL, *acmd = NULL;
pid_t pid;
if (argv)
{
cmd = argv[0];
acmd = finding_path(cmd);
if (acmd == NULL)
{
perror("Error:");
return;
}
pid = fork();
if (pid == -1)
{
perror("Error:");
}
else if (pid == 0)
{
if (strcmp(cmd, "env") == 0)
{
env_builtin();
}
else if (execve(acmd, argv, NULL) == -1)
{
perror("Error:");
exit(EXIT_FAILURE);
}
}
else
{
int status;
if (waitpid(pid, &status, 0) == -1)
{
perror("Error:");
}
}
}
if (cmd != acmd)
free(acmd);
}
