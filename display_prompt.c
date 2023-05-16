#include "main.h"
/**
 * display_prompt - displays a prompt & waits for user command
 * @av: argument vector
 * @env: environment variable
 */
void display_prompt(char **av, char **env)
{
	char *string = NULL;
	char *argv[MAX_COMMAND];
	int i, stat;
	size_t n = 0;
	ssize_t num_char;
	pid_t prompt_pid;

	while (1)
	{
		printf("cisfun$ ");
		num_char = getline(&string, &n, stdin);
		if (num_char == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		for (i = 0; string[i]; i++)
		{
			if (string[i] == '\n')
				string[i] = 0;
		}
		argv[0] = string;
		prompt_pid = fork();
		if (prompt_pid == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		if (prompt_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				printf("%s: No such file or directory\n", av[0]);
		}
		else
			wait(&stat);
	}
}
