#include <stdarg.h>
#include "main.h"

/**
 * _printf - Prints the content %s and %c format specifiers
 * @format: The format to check for
 * Return: character count
 */

int _printf(const char *format, ...)
{
	va_list arguments;
	char *str;

	va_start(arguments, format);

	while (*format)
	{

		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					_putchar(va_arg(arguments, int));
					break;
				case 's':
					str = va_arg(arguments, char*);

					while (*str)
					{
						_putchar(*str);
						str++;
					}
					break;
			}
		}
		else
			_putchar(*format);
		format++;
	}
	va_end(arguments);
	return (0);
}
