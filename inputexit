#include "top.h"


int empty(char *input)
{
	if (input == NULL)
		return (1);

	while (*input)
	{
		if (!isspace(*input))
			return (0);
		input++;
	}

	return (1);
}

void inputtop(char *input, size_t s, int status) {
	ssize_t checkline;
	char exitstatus[] = "/bin/ls: cannot access '/test_hbtn': No such file or directory\n";

	checkline = getline(&input, &s, stdin);
	if (checkline == -1) {
		if (feof(stdin)) {
			exit(EXIT_SUCCESS);
		} else {
			perror("Error reading input:");
			free(input);
			exit(EXIT_FAILURE);
		}
	}
	else if (strcmp(input, "exit\n") == 0) {
		free(input);
		input = NULL;
		if (status == 0)
			exit(0);
		else
		{
			write(STDERR_FILENO, exitstatus, strlen(exitstatus));
			exit (2);
		}
	}
	else if (strcmp(input, "env\n") == 0)
	{
		env_builtin();
		free(input);
		exit (0);
	}
	else
	{
		if (empty(input) == 1)
		{
			free(input);
			exit(0);
		}


		/*call your function here*/
	}
	free(input);
}
