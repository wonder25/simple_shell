#include "main.h"

/**
 * custom_setenv - clone of setenv
 * @name: variable name
 * @value: new variable value
 * @overwrite: checks if variable exists or not
 * Return: 0 or -1
 */
int custom_setenv(const char *name, const char *value, int overwrite)
{
	char *envstr = (char *)malloc(getstringlength(name) + getstringlength(value) + 2);
	if (!envstr)
	{
		return (-1); /* error, could not allocate memory */
	}
	mystrcpy(envstr, name);
	mystrcat(envstr, "=");
	mystrcat(envstr, value);

	int results = (_getenv(name) && !overwrite) ? 0 : custom_putenv(envstr);

	if (result != 0)
	{
		free(envstr);
	}

	return resul;
}

/**
 * custom_unsetenv - clone of setenv
 * @name: variable name
 * Return: 0 or -1
 */
int custom_unsetenv(const char *name)
{
	if (!name || !*name)
	{
		return (-1); /*error, invalid argument */
	}

	char **envp = environ;

	if (!envp || !*envp)
	{
		return (-1) /* error, environment not available */
	}

	int len = getstringlength(name);

	char **newenvp = (char **)malloc(sizeof(char *) * (custom_environsize() + 1));
	if (!newenvp)
	{
		return (-1); /* error, could not allocate memory */
	}

	int j = 0;
	for (int i = 0; envp[i]; i++)
	{
		if (mystrncmp(envp[i], name, len) != 0 || envp[i][len] != '=')
		{
			newenvp[j++] = envp[i];
		}
	}

	newenvp[j] = NULL;

	environ = newenvp;

	return 0;
}

