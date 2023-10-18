#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * dash_printf - handles the (-) character
 * @format: arguments to be passed
 * Return: 0
 */

int dash_printf(const char *format, ...)
{
	int prt_ch = 0, left_dash = 0;
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '-')
			{
				left_dash = 1;
				format++;
			}
			switch (*format)
			{
				case 'd':
				case 'i':
					prt_ch += hd_decimal(va_arg(args, int), left_dash);
					break;
				case 's':
					prt_ch += hd_string(va_arg(args, char*), left_dash);
					break;
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
 * hd_decimal - Handles decimal
 * @value: inputted value
 * @left_dash: left dash
 * Return: 0
 */

int hd_decimal(int value, int left_dash)
{
	int prt_ch = 0;

	if (left_dash)
	{
		printf("%d", value);
		prt_ch += snprintf(NULL, 0, "%d", value);
	}
	else
	{
		printf("%5d", value);
		prt_ch += snprintf(NULL, 0, "%5d", value);
	}
	return (prt_ch);
}
/**
 * hd_string - Handles string
 * @str: inputted string
 * @left_dash: left dash
 * Return: 0
 */

int hd_string(char *str, int left_dash)
{
	int prt_ch = 0;

	if (left_dash)
	{
		printf("%s", str);
		prt_ch += strlen(str);
	}
	else
	{
		printf("%20s", str);
		prt_ch += strlen(str) + 5;
	}
	return (prt_ch);
}
