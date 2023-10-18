#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <unistd.h>

/**
 * _buffer_printf - local buffer
 * @format: Argumentts to be passed
 * Return: 0
 *
 */

int _buffer_printf(const char *format, ...)
{
	char buffer[1024];
	int buffer_index = 0;
	int prt_ch = 0;
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
		}
		else
		{
			if (buffer_index < 1023)
			{
				buffer[buffer_index++] = *format;
			}
			else
			{
				write(STDOUT_FILENO, buffer, buffer_index);
				buffer_index = 0;
				prt_ch += 1023;
				buffer[buffer_index++] = *format;
			}
			prt_ch++;
		}
		format++;
	}
	write(STDOUT_FILENO, buffer, buffer_index);
	va_end(args);
	return (prt_ch);
}

