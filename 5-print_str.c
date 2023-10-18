#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int print_str_escaped(char *str);
/**
 * s_printf - prints a string
 * @format: arguments passed in to print
 * Return: prt_ch
 */

int s_printf(const char *format, ...)
{
	int prt_ch = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'S')
			{
				char *str;

				str = va_arg(args, char*);
				prt_ch += print_str_escaped(str);
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
	return (prt_ch);
}


/**
 * print_str_escaped - prints custom string
 * @str: custom string
 * Return: prt_ch
 */

int print_str_escaped(char *str)
{
	int prt_ch = 0;

	while (*str)
	{
		if ((*str >= 1 && *str <= 31) || *str >= 127)
		{
			printf("\\x%02X", (unsigned char)*str);
			prt_ch += 4;
		}
		else
		{
			putchar(*str);
			prt_ch++;
		}
		str++;
	}
	return (prt_ch);
}
