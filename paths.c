#include "main.h"

/**
 * get_env - gets value stored in a specific var name
 * @name: variable name
 * Return: values stored in the var
 */

char *get_env(const char *name)
{
	int len, j = 0;
	char *env_val;

	len = get_stringlength(name);

	while (environ[j] != NULL)
	{
		if (myStrncmp(name, environ[j], len) == 0 && environ[j][len] == '=')
		{
			env_val = &environ[j][len + 1];
			return (env_val);
		}
		j++;
	}
	return (NULL);
}

/**
 * find_executable - checks if file exists and can be executable
 * @command: command being executed
 * @path_list: list of directories to check
 *  Return: exe path for command
 */

char *find_executable(char *command, LL *path_list)
{
	char *executable_path = NULL;
	char *path = NULL;
	int command_len = get_stringlength(command);
	int path_len;
	int new_len;
	char *new_path;

	while (path_list != NULL)
	{
		path = path_list->str;
		path_len = get_stringlength(path);
		new_len = path_len + command_len + 2;
		new_path = malloc(new_len * sizeof(char));

		if (new_path == NULL)
		{
			executable_path = new_path;
		break;
		}
		free(new_path);
		path_list = path_list->next;
	}
	return (executable_path);
}
