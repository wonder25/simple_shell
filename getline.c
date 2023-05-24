#include <ctype.h>
#include "main.h"

#define INIT_BUF_SIZE 128

char *allocate_buffer(size_t size)
{
	char *buf = malloc(size);

	if (buf == NULL)
	{
		perror("unable to allocate buffer");
	}
	return (buf);
}

char *expand_buffer(char *buf, size_t size)
{
	char *newBuf = realloc(buf, size * 2);

	if (newBuf == NULL)
	{
		free(buf);
		perror("unable to expand buffer");
	}
	return (newBuf);
}

int is_empty_line(ssize_t len, char *buf)
{
	ssize_t i;

	for (i = 0; i < len; i++)
	{
		if (!isspace(buf[i]))
			return (0);
	}
	return (1);
}

ssize_t handle_empty_line(char *buf, char **lineptr)
{
	(void)buf;
	(void)lineptr;
	return (-1);
}

/**
 * getline - custom version of getline()
 * @lineptr: buffer for storing strings
 * @n: size of buffer
 * @fd: source to read from
 *
 *Return: -1 or number of char's read
 */
ssize_t my_getline(char **lineptr, size_t *n, int fd)
{
	ssize_t len = 0;
	size_t buf_size = *n;
	char *buf = *lineptr;
	char c = 0;

	if (lineptr == NULL || n == NULL)
	{
		errno = EINVAL;
		return (-1);
	}
	if (buf == NULL)
	{
		buf_size = INIT_BUF_SIZE;
		buf = allocate_buffer(buf_size);
		if (buf == NULL)
			return (-1);
		*lineptr = buf;
		*n = buf_size;
	}
	while (read(fd, &c, 1) > 0)
	{
		if (len + 1 >= (ssize_t)buf_size)
		{
			buf_size *= 2;
			buf = expand_buffer(buf, buf_size);
			if (buf == NULL)
				return (-1);
			*lineptr = buf;
			*n = buf_size;
		}
		buf[len++] = c;
		if (c == '\n')
			break;
	}
	if (is_empty_line(len, buf))
	{
		return (handle_empty_line(buf, lineptr));
		close_buffer(len, buf);
	}
	return (len);
}
