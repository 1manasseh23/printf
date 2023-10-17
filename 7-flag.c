#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * flag_printf - prints the flag
 * @format: arguments to be passed
 * Return: character count
 */

int flag_printf(const char *format, ...)
{
	int char_count = 0;
	va_list args;

	va_start(args, format);
	int d_value;
	char *s_value;

	while (*format)
		if (*format == '%')
			format++;
			int flag_plus = 0;
			int flag_space = 0;
			int flag_hash = 0;

			while (*format == '+' || *format == ' ' || *format == '#')
				if (*format == '+')
					flag_plus = 1;

				if (*format == ' ')
					flag_space = 1;

				if (*format == '#')
					flag_hash = 1;
			switch (*format)
				case 'd':
					d_value = va_arg(args, int);
					char_count += handle_decimal(d_value, flag_plus, flag_space, flag_hash);
					break;
				case 's':
					s_value = va_arg(args, char*);
					char_count += handle_string(s_value, flag_plus, flag_space, flag_hash);
					break;
		else
			putchar(*format);
			char_count++;

		format++;
	va_end(args);
	return (char_count);
}

/**
 * handle_decimal - handles decimals
 * @value: value  to check
 * @flag_plus: checks for plus flag
 * @flag_space: checks for space
 * @flag_hash: checks for hash
 * Return: 0
 */

int handle_decimal(int value, int flag_plus, int flag_space, int flag_hash)
{
	char_count = 0;
	if (flag_plus && value >= 0)
	{
		putchar('+');
		value = abs(value);
	}
	else if (flag_space && value >= 0)
	{
		putchar(' ');
	}
	printf("%d", d_value);

	if (flag_hash)
	{
		if (value != 0)
		{
			putchar('0');
			putchar(uppercase ? 'X' : 'x');
			char_count += 2;
		}
	}
	return (snprintf(NULL, 0, "%d", value));

}

/**
 * handle_str - handles the string
 * @value: value  to check
 * @flag_plus: checks for plus flag
 * @flag_space: checks for space
 * @flag_hash: checks for hash
 * Return: length of string
 */

char handle_str(int value, int flag_plus, int flag_space, int flag_hash)
{
	if (flag_plus)
	{
		putchar('+');
	}
	else if (flag_space)
		putchar(' ');
	printf("%s", str);
	return (strlen(str));
}
