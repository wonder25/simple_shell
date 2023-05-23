#include "main.h"

/**
 * custom_putenv - clone of putenv
 * @str: name value pair to be added
 * Return: 1
 */

int custom_putenv(char *str)
{
	int i;

	if (!str || !*str || strchr(str, '=') == NULL)
		return (-1); /* err, invalid input string */

	/* calculate size of new environ array */
	int new_environ_size = custom_environSize() + 2;

	/* allocate mem for new environ array */
	char **new_environ = malloc(sizeof(char *) * new_environ_size);

	if (!new_environ)
		return (-1);
	/* copy current environ to new array */
	int j = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (myStrncmp(environ[i], str, custom_strchr(str, '=') - str) != 0)
			new_environ[j++] = environ[i];
	}
	/* appends new environ string to new array */
	new_environ[j++] = str;
	/* adds terminating pointer to new array */
	new_environ[j] = NULL;
	/* sets new environ array */
	environ = new_environ;
	return (1);
}

/**
 * custom_environSize - environment size
 * Return: size of current environment
 */

int custom_environSize(void)
{
	int size = 0;
	char **envp = environ;

	while (*envp != NULL)
	{
		size++;
		envp++;
	}

	return (size);
}

/**
 * custom_strchr - custom strchr
 * @str: search string
 * @c: search char
 * Return: NULL or pointer to c
 */

char *custom_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}

	if (*str == c)
		return ((char *)str);

	return (NULL);
}
