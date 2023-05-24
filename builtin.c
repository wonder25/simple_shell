#include "main.h"

/**
 * run_builtins - handles builtin functions
 * @tokens: tokenized commands
 * @env: contains values of environ
 */
void run_builtins(char **tokens, char **env)
{
	if (my_strcmp(tokens[0], "exit") == 0) /* check if command is "exit" */
	{
		run_exit(tokens);
	}
	else if (my_strcmp(tokens[0], "env") == 0) /* env built-in command */
	{
		run_env(env);
	}

}
