#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/**
 * flag_printf - prints the flag
* @format: arguments to be passed
 * Return: character count
 */

/**
int _printf(const char *format, ...)
{
	int char_count = 0, d_value;
	va_list args;
	int flag_plus, flag_space, flag_hash;
	char *s_value;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			while (*format == '+' || *format == ' ' || *format == '#')
			{
				if (*format == '+')
					flag_plus = 1;

				if (*format == ' ')
					flag_space = 1;

				if (*format == '#')
					flag_hash = 1;
			}
			switch (*format)
			{
				case 'd':
					d_value = va_arg(args, int);
					char_count += handle_decimal(d_value, flag_plus, flag_space, flag_hash);
					break;
				case 's':
					s_value = va_arg(args, char*);
					char_count += handle_str(s_value, flag_plus, flag_space, flag_hash);
					break;
			}
		}
		else
			putchar(*format);
			char_count++;

		format++;
	}
	va_end(args);
	return (char_count);
}
*/

/**
 * handle_decimal - handles decimals
 * @value: value  to check
 * @flag_plus: checks for plus flag
 * @flag_space: checks for space
 * @flag_hash: checks for hash
 * Return: 0
 */
/*
int handle_decimal(int value, int flag_plus, int flag_space, int flag_hash)
{
	int char_count = 0;
	if (flag_plus && value >= 0)
	{
		putchar('+');
		value = abs(value);
	}
	else if (flag_space && value >= 0)
	{
		putchar(' ');
	}
	printf("%d", value);

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
*/

/**
 * handle_str - handles the string
 * @value: value  to check
 * @flag_plus: checks for plus flag
 * @flag_space: checks for space
 * @flag_hash: checks for hash
 * Return: length of string
 */
/*
int handle_str(char *str, int flag_plus, int flag_space, int flag_hash)
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
*/
#include <stdio.h>
#include <stdarg.h>
#include "main.h"

void flags_printf(const char *format, ...)
{
	va_list args;
	int plus_flag = 0, space_flag = 0, hash_flag = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			while (*format == '+' || *format == ' ' || *format == '#')
			{
				if (*format == '+')
				{
					plus_flag = 1;
				}
				else if (*format == ' ')
				{
					space_flag = 1;
				}
				else if (*format == '#')
				{
					hash_flag = 1;
				}
				format++;
			}
			if (plus_flag)
			{
				int num = va_arg(args, int);
				if (num >= 0)
				{
					putchar('+');
				}
				printf("%d", num);
			}
			else if (space_flag)
			{
				int num = va_arg(args, int);
				if (num >= 0)
				{
					putchar(' ');
				}
				printf("%d", num);
			}
			else if (hash_flag)
			{
				int num = va_arg(args, int);
				if (*format == 'o')
				{
					printf("0%o", num);
				} 
				else if (*format == 'x' || *format == 'X')
				{
					printf("0%s%x", (*format == 'X') ? "X" : "x", num);
				}
			}
			else
			{
				putchar('%');
				putchar(*format);
			}
		}
		else
		{
			putchar(*format);
		}
		format++;
	}
	va_end(args);
}
