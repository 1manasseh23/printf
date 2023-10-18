#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/**
 * rot_encode - rot13 function
 * @str: Inputted string
 * Return: 0
 */

void rot_encode(char *str)
{
	int j;

	for (j = 0; str[j]; j++)
	{
		char c = str[j];

		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		{
			char base = (c >= 'a' && c <= 'z') ? 'a' : 'A';

			str[j] = (c - base + 13) % 26 + base;
		}
	}
}
/**
 * R_printf - Handles the custom R specifier
 * @format: arguments to be pased
 * Return: 0
 */

int R_printf(const char *format, ...)
{
	int prt_ch = 0;
	char *str;
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'R')
			{
				str = va_arg(args, char*);
				rot_encode(str);
				printf("%s", str);
				prt_ch += strlen(str);
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
