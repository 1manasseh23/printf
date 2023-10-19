#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _vprintf - handler file for cases of format specifiers
 * @format: Arguments to be passed
 * @args: Argument list
 * Return: length
 */

int _vprintf(const char *format, va_list args)
{
	int length = 0;
	int printed;

	while (*format)
	{
		if (*format != '%')
		{
			putchar(*format);
			length++;
		}
		else
		{
			format++;
			printed = 0;
			switch (*format)
			{
				case 'c':
					printed = handle_c(args);
					break;
				case 's':
					printed = handle_s(args);
					break;
				case 'd':
				case 'i':
					printed = handle_d(args);
					break;
				case 'u':
					printed = handle_u(args);
					break;
				case 'x':
				case 'X':
					printed = handle_x(args);
					break;
				case 'o':
					printed = handle_o(args);
					break;
				case 'p':
					printed = handle_p(args);
					break;
				default:
					putchar('%');
					putchar(*format);
					length += 2;
			}
			length += printed;
		}
		format++;
	}
	return (length);
}
