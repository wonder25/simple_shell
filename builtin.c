#include "main.h"

typedef struct
{
	char *name;
	void (*func)(char **, char **);
}
builtin_func;

builtin_func builtin_commands[] = {
	{"exit", execute_exit},
	{"env", execute_env},
	{"cd", execute_cd},
	{"setenv", shell_setenv},
	{NULL, NULL}
};

/**
 * execute_builtins - handles builtin functions
 * @tokens: tokenized commands
 * @env: contains values of environ
 */
void execute_builtins(char **tokens, char **env)
{
	for (int i = 0; builtin_commands[i].name != NULL; i++)
	{
		if (my_strcmp(tokens[0], builtin_commands[i].name) == 0)
		{
			builtin_commands[i].func(tokens, env);
			break;
		}
	}
}
