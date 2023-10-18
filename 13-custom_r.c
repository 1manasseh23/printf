#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/**
 * r_printf - customs r specifier
 * @format: Arguments to be passed in
 * Return: 0
 */

int r_printf(const char *format, ...)
{
	int prt_ch = 0;
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'r')
			{
				prt_ch += handle_rev_string(va_arg(args, char*));
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
 * handle_rev_string - Handles reverse string
 * @str: The String
 * Return: 0
 */

int handle_rev_string(char *str)
{
	int prt_ch = 0;
	int length = strlen(str);
	int i;

	for (i = length - 1; i >= 0; i--)
	{
		putchar(str[i]);
		prt_ch++;
	}
	return (prt_ch);
}
