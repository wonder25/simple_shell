#include "main.h"

/**
 * main - Entry point of the shell program
 * @argc: Number of command line arguments
 * @argv: Array of command line arguments
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	char *input = NULL;

	if (argc > 1 && compare_strings(argv[0], "./hsh") == 0)
	{
		file_input(argc, argv);
		exit(0);
	}

	while (1)
	{
		prompt();
		input = read_input();
		handle_input(input);
	}

	return (0);
}

/**
 * command_checker - checks if command is bultin or in path
 * @tokens: pointer to commands
 * Return: path of command
 */

char *command_checker(char **tokens)
{
	char *path;
	LL *pathLL;
	char *builtins[6] = {"exit", "env", "cd", "unsetenv", "setenv", NULL};
	int j = 0;

	while (builtins[j])
	{
		if (compare_strings(tokens[0], builtins[j]) == 0)
		{
			run_builtins(tokens, environ);
			return (NULL);
		}
		j++;
	}

	if (access(tokens[0], X_OK) == 0)
	/* checks commands are full path or shorthand */
	{
		path = tokens[0];
		return (path);
	}

	else if (access(tokens[0], X_OK) != 0)
	{
		pathLL = path_list();
		path = find_executable(tokens[0], pathLL);

		if (path == NULL)
		{
			perror(myStrcat(tokens[0], ": command not found\n"));
		}
		else
		{
			return (path);
		}
	}
	return (NULL);
}

/**
 * handle_semicolon - handles input containing multiple commands
 * separated by semicolons
 * @input: input strings of commands
 */

void handle_semicolon(char *input)
{
	char *command;
	char *saveptr;

	command = strtok_r(input, ";", &saveptr);
	while (command != NULL)
	{
		char *tokens[MAX_NUM_TOKENS];
		int num_tokens = tokenize(command, tokens, MAX_NUM_TOKENS);

		if (num_tokens > 0 && strcmp(tokens[0], "alias") != 0)
			execute(tokens);
		command = strtok_r(NULL, ";", &saveptr);
	}
}
