#include "shell.h"

typedef void (*builtin_func)(char **)
builtin_func builtins[] =
{
	&execute_exit,
	&execute_env,
	&execute_cd,
	&shell_setenv,
	&shell_unsetenv,
};

char *builtin_str[] =
{
	"exit",
	"env",
	"cd",
	"setenv",
	"unsetenv",
};

#define BUILTIN_NUM (sizeof(builtin_str) / sizeof(char *))

/**
 * execute_builtins - handles builtin functions
 * @tokens: tokenized commands
 * @env: contains values of environ
 */
void execute_builtins(char **tokens, char **env)
{
	for (int i = 0; i < BUILTIN_NUM; i++)
	{
		if(my_strcmp(tokens[0], builtin_str[i]) == 0)
		{
			builtins[i](tokens);
			break;
		}
	}
}
