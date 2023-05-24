#include "main.h"

/**
 * str_dup - copies contents of input str to new memory
 * @str: string to be copied
 * Return: pouinter to new string
 */

char *str_dup(const char *str)
{
	size_t len = get_stringlength(str) + 1;
	char *new_str = malloc(len);

	if (new_str == NULL)
	{
		return (NULL);
	}
	memcpy(new_str, str, len);
	return (new_str);
}

/**
 * myStrncmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * @n: compares first n chracters of s1 and s2
 * Return: 0 on success
 */

int myStrncmp(const char *s1, const char *s2, size_t n)
{
	size_t j = 0;

	while (j < n)
	{
		if (*s1 == '\0' || *s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
		j++;
	}
	return (0);
}

/**
 * str_cat - concats two strings
 * @dest: destination
 * @src: string source
 * Return: joined string
 */

char *str_cat(char *dest, const char *src)
{
	char *firstdest = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (firstdest);
}

/**
 * str_cpy - copies contents of string to other string
 * @dest: copying destination
 * @src: string copied
 * Return: string copied
 */

char *str_cpy(char *dest, const char *src)
{
	char *firstdest = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (firstdest);
}

/**
 * concatenateStrings - joins two strings
 * @str1: string 1
 * @str2: joined to string 1
 * Return: str1 and str2
 */

char *concatenateStrings(char *str1, char *str2)
{
	int len1 = get_stringlength(str1);
	int len2 = get_stringlength(str2);
	char *result = malloc(len1 + len2 + 1);

	if (result == NULL)
	{
		perror("Failed to allocate memory for concatenated string");
		exit(1);
	}

	result = str_cpy(result, str1);
	result = str_cat(result, str2);
	return (result);
}
