#include "main.h"
#include <ctype.h>

void terminate_buffer(ssize_t len, char *buf)
{
	buf[len] = '\0';
}
