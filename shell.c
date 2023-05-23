#include "main.h"

/**
 * main - Entry point of the shell program
 * @argc: Number of command line arguments
 * @argv: Array of command line arguments
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	char *input = NULL;

	if (argc > 1 && my_strcmp(argv[0], "./hsh") == 0)
	{
		file_input(argc, argv);
		exit(0);
	}

	while (1)
	{
		prompt();
		input = read_input();
		handle_input(input);
	}

	return (0);
}
