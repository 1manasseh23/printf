#include <stdarg.h>
#include "main.h"

/**
 * str_char_printf - Prints the content %s and %c format specifiers
 * @format: The format to check for
 * Return: character count
 */

int str_char_printf(const char *format, ...)
{
	va_list arguments;

	va_start(arguments, format);

	int char_count = 0;

	while (*format)
	{

		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					_putchar(va_arg(arguments, int));
					char_count++;
					break;
				case 's':
					char *str = va_arg(arguments, char*);

					while (*str)
					{
						_putchar(*str);
						char_count++;
						str++;
					}
					break;
			}
		}
		else
			_putchar(*format);
			char_count++;
		format++;
	}
	va_end(arguments);
	return (char_count);
}
