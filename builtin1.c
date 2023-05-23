#include "main.h"

/* builtin1 function for error messages */
void print_error(const char *command, const char *error_msg)
{
	write(STDERR_FILENO, command, get_stringlength(command));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, error_msg, get_stringlength(error_msg));
	write(STDERR_FILENO, "\n", 1);
}

/**
 * execute_exit - exitbuiltin
 * @tokens: tokenized commands
 */
void execute_exit(char **tokens)
{
	int size = 0;

	while (tokens[size] != NULL)
	{
		size++;
	}
	if (size > 2)
	{
		print_error("exit", "too many arguments");
	}
	else if (size == 2)
	{
		exit(atoi(tokens[1]));
	}
	else
	{
		exit(0);
	}
}

/**
 * execute_env - env builtin
 * @env: environment variable
 */
void execute_env(char **env)
{
	while (*env !=NULL)
	{
		size_t len = get_stringlength(*env);
		write(STDOUT_FILENO, *env, len);
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}

/**
 * execute_cd - cd builtin
 *@tokens: tokenized commands
 *Return: 0 on success
 */
int execute_cd(char **tokens)
{
	char *folder_new = getcwd(NULL, 0);
	char *folder_prev = get_env("OLDPWD");

	if (tokens[1] == NULL)
	{
		if (chdir(get_env("HOME")) !=0)
		{
			perror("cd");
		}
	}
	else if (my_strcmp(tokens[1], "-") == 0)
	{
		if (folder_prev == NULL)
		{
			print_error("cd", "OLDPWD not set");
		}
		else
		{
			if (chdir(folder_prev) != 0)
			{
				perror("cd");
			}
			write(STDERR_FILENO, folder_prev, get_stringlength(folder_prev));
			write(STDERR_FILENO, "\n", 1);
		}
	}
	else
	{
		if (chdir(tokens[1]) != 0)
		{
			perror("cd");
		}
	}
	if (folder_new == NULL)
	{
		perror("getcwd failed");
	}
	setenv("OLDPWD", get_env("PWD"), 1);
	setenv("PWD", folder_new, 1);
	free(folder_new);
	return (1);
}

/**
 * shell_setenv - setenv builtin
 * @args: tokenized commands
 * return: 0 or 1
 */
void shell_setenv(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		print_error("setenv", "invalid arguments");
	}
	else
	{
		if (setenv(args[1], args[2], 1) != 0)
		{
			print_error("setenv", "failed to set variable");
		}
	}
}

/**
 * shell_unsetenv - cd builtin
 * @args: tokenized commands
 * Return: 0 or 1
 */
void shell_unsetenv(char **args)
{
	if (args[1] == NULL)
	{
		print_error("unsetenv", "invalid arguments");
	}
	else
	{
		if (unsetenv(args[1]) != 0)
		{
			print_error("unsetenv", "failedto unset variable");
		}
	}
}
