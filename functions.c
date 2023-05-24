#include "main.h"

/**
 * print_str - writes string to stdin
 * @str: string to be written
 */

void print_str(char *str)
{
	size_t len = get_stringlength(str);

	write(STDOUT_FILENO, str, len);
}

/**
 * get_stringlength - gets characters in a string
 * @str: string length calculated
 * Return: length of string
 */

int get_stringlength(const char *str)
{
	int length = 0;

	while (*str != '\0')
	{
		length++;
		str++;
	}
	return (length);
}

/**
 * write_str - writes string to stderr
 * @str: Error message to be printed
 */

void write_str(char *str)
{
	size_t len = get_stringlength(str);

	write(STDERR_FILENO, str, len);
}

/**
 * my_strcmp - compares two strings
 * @str1: string one
 * @str2: string two
 * Return: the difference btwn the ASCII of the characters
 */

int my_strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

/**
 * read_input - reads input from stdin
 * Return: returns input from stdout
 */

char *read_input()
{
	char *input = NULL;
	size_t input_size = 0;

	if (getline(&input, &input_size, stdin) == -1)
	{
		free(input);
		return (NULL);
	}
	return (input);
}
