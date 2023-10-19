#include "main.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * flags_printf - prints the flag
 * @format: arguments to be passed
 * Return: character count
 */

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
					putchar('+');
				printf("%d", num);
			}
			else if (space_flag)
			{
				int num = va_arg(args, int);

				if (num >= 0)
					putchar(' ');
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
