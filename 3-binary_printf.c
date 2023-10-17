#include <stdarg.h>
#include "main.h"

/**
 * binary_recursion - recursion to print binary numbers
 * @num: number to convert
 * Return: 0
 */
int binary_recursion(unsigned int num)
{
	if (num > 1)
		binary recursion(num / 2);
	_putchar('0' + (num % 2));
	char_count++;
}

/**
 * binary_printf - converts argument to binary
 * @format: arguments to be passed
 * Return: Character count
 */

int binary_printf(const char *format, ...)
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
				case 'b':
					unsigned int value;

					value = (va_arg(arguments, unsigned int));
					binary_recursion(value);
					break;
			}
		}
		else
		{
			_putchar(*format);
			char_count++;
		}
		format++;
	}
	va_end(arguments);
	return (char_count);
}
