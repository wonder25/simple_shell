#include "main.h"
/**
 * main - takes one argument from stdin
 * @ac: argument count
 * @av:argument vector
 * @env: environment variable
 *
 * Return: 0 if pass
 */
int main(int ac, char **av, char **env)
{
	if (ac == 1)
	{
		display_prompt(av, env);
	}
	return (0);
}
