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
