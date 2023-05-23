#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <errno.h>
#include "main.h"

#define INIT_BUF_SIZE 128

ssize_t my_getline(char **lineptr, size_t *n, int fd)
{
	ssize_t len = 0;
	char c = 0;
	size_t buf_size = (*n > 0) ? *n : INIT_BUF_SIZE;

	/* Error handling for invalid pointers */
	if (lineptr == NULL || n == NULL)
	{
		errno = EINVAL;
		return (-1);
	}

	/* Allocate buffer if not already allocated */
	if (*lineptr == NULL)
	{
		*lineptr = malloc(buf_size);
		if (*lineptr == NULL)
		{
			return (-1);
		}
	}
	while (read(fd, &c, 1) > 0)
	{
		/* Expand buffer if needed */
		if (len + 1 >= (ssize_t)buf_size)
		{
			buf_size *= 2;
			*lineptr = realloc(*lineptr, buf_size);
			if (*lineptr == NULL)
			{
				return (-1);
			}
		}

		(*lineptr)[len++] = c;
		/* End of line reached */
		if (c == '\n')
		{
			break;
		}
	}
/* check for errors or end of file without any characters read */
	if (len == 0)
	{
		return (-1);
	}

	/* Null-terminate the string */
	if (len + 1 >= (ssize_t)buf_size)
	{
		buf_size += 1;
		*lineptr = realloc(*lineptr, buf_size);
		if (*lineptr == NULL)
		{
			return (-1);
		}
	}
	(*lineptr)[len] = '\0';
	*n = buf_size;
	return len;
}
