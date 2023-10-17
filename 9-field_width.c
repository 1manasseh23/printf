#include "inno.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * width_printf - Handles field width
 * @format: arguments
 * Return: character count
 */

int width_printf(const char *format, ...)
{
	int char_count = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			int width = 0;

			if (*format >= '0' && *format <= '9')
			{
				while (*farmat >= '0' && *format <= '9')
				{
					width = width * 10 + (*format - '0');
					format++;
				}
			}
			switch (*format)
			{
				case 'd':
				case 'i':
					char_count += handle_decimal(va_arg(args, int), width);
					break;
				case 's':
					char_count += handle_string(va_arg(args, char*), width);
					break;
			}
		}
		else
		{
			putchar(*format);
			char_count++;
		}
		format++;
	}
	va_end(args);
	return (char_count);
}

/**
 * handle_decimal - Handles decimal
 * @value: The value
 * @width: The width
 * Return: character count
 */

int handle_decimal(int value, int width)
{
	int char_count = 0;
	char buffer[20];
	int padding;

	int len = snprintf(buffer, sizeof(buffer), "%d", value);

	if (width > len)
	{
		padding = width - len;
		while (padding > 0)
		{
			putchar(' ');
			char_count++;
			padding--;
		}
	}
	printf("%d", value);
	char_count += len;
	return (char_count);
}

/**
 * handle_string - Handles string
 * @str: the string
 * @width: The width
 * Return: character count
 */

int handle_string(char *str, int width)
{
	int char_count = 0;
	int len = strlen(str);
	int padding;

	if (width > len)
	{
		padding = width - len;
		while (padding > 0)
		{
			putchar(' ');
			char_count++;
			padding--;
		}
	}
	printf("%s", str);
	char_count += len;
	return (char_count);
}
