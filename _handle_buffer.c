#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * write_char - defined function for buffer
 * @c: character
 */

static char output_buffer[BUFFER_SIZE];
static int buffer_index;

void write_char(char c)
{
	if (buffer_index < BUFFER_SIZE - 1)
	{
		output_buffer[buffer_index++] = c;
	}
}

/**
 * flush_buffer - defined function for buffer
 */

void flush_buffer(void)
{
	output_buffer[buffer_index] = '\0';
	printf("%s", output_buffer);
	buffer_index = 0;
}
