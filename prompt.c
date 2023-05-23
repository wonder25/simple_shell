#include "main.h"

/**
 * prompt - displays the shell prompt
 */

void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "#cisfun$ ", 9);
}

/**
 * handle_input - handles the user input
 * @input: user input string
 */

void handle_input(char *input)
{
	char *tokens[MAX_NUM_TOKENS];
	int num_tokens;

	if (input == NULL)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}

	if (strchr(input, ';') != NULL)
		handle_semicolon(input);
	else
	{
		num_tokens = tokenize(input, tokens, MAX_NUM_TOKENS);
		if (num_tokens > 0 && strcmp(tokens[0], "alias") != 0)
			execute(tokens);
	}
	free(input);
}

/**
 * tokenize - breaks string into tokens using strtok()
 * @input: input string that needs to be tokenized
 * @tokens: array that will hold the resulting tokens
 * @max_tokens: max number of tokens that can be extracted
 * Return: Number of tokens
 */

int tokenize(char *input, char **tokens, int max_tokens)
{
	int num_tokens = 0;
	char *token = strtok(input, " \n");

	while (token != NULL && num_tokens < max_tokens)
	{
		if (token[0] == '#')
			break;
		tokens[num_tokens] = token;
		num_tokens++;
		token = strtok(NULL, " \n");
	}

	tokens[num_tokens] = NULL;
	return (num_tokens);
}

/**
 * execute - creates child process using folk() and executes command
 * @tokens: commands to execute
 */

void execute(char **tokens)
{
	pid_t pid;
	int status;
	char *path = command_checker(tokens);

	if (path == NULL)
		return;

	if (strcmp(path, "error") == 0)
	{
		write(STDERR_FILENO, "Invalid command\n", strlen("Invalid command\n"));
	return;
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(path, tokens, environ) == -1)
		{
			perror("execve failure");
			exit(1);
		}
	}
	else if (pid > 0)
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid failed");
			exit(1);
		}
	}
	else
	{
		perror("fork failed");
		exit(1);
	}
}
