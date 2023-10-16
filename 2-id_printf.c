#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * id_printf - A function that handle i, d, conversation specifiers
 * @format: The format to check
 * Return: 1
 */

int id_printf(const char *format, ...)
{
	int prt_ch = 0;

	va_list arg;

	va_start(args, format);

	int value;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' || *format == 'i')
			{
				value = va_arg(args, int);
				printf("%d", value);
				prt_ch += snprintf(NULL, 0, "%d", value);
			}
		}
		else
		{
			putchar(*format);
			prt_ch++;
		}
		format++;
	}
	va_end(args);
	return (ptr_ch);
}
