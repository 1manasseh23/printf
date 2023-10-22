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
	int length = 0, i;
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
					{
						char *str = va_arg(args, char *);
						if (str == NULL)
						{
							for (i = 0; "(null)"[i] != '\0'; i++)
							{
								putchar("(null)"[i]);
							}
							length += 6;
						}
						else
						{
							while (*str)
							{
								putchar(*str);
								length++;
								str++;
							}
						}
						break;
					}
				case 'd':
				case 'i':
					printed = handle_d(args);
					break;
				case 'u':
					printed = handle_u(args);
					break;
				case 'x':
					printed = handle_x(args);
					break;
				case 'X':
					printed = handle_X(args);
					break;
				case 'o':
					printed = handle_o(args);
					break;
				case 'p':
					printed = handle_p(args);
					break;
				case 'r':
					printed = handle_r(args);
					break;
				case 'S':
					printed = handle_S(args);
					break;
				case '%':
					putchar('%');
					printed = 1;
					break;
				default:
					putchar('%');
					putchar(*format);
					printed = 2;
			}
			length += printed;
		}
		format++;
	}
	return (length);
}
