#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * h0_printf - Handles 0 flag character
 * @format: arguments to be passed
 * Return: 0
 */

int h0_printf(const char *format, ...)
{
	int prt_ch = 0, zero_flag = 0;
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '0')
			{
				zero_flag = 1;
				format++;
			}
			switch (*format)
			{
				case 'd':
				case 'i':
					prt_ch += hand_decimal(va_arg(args, int), zero_flag);
					break;
				case 's':
					prt_ch += hndle_string(va_arg(args, char*), zero_flag);
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
 * hand_decimal - handles decimals
 * @value: inputted value
 * @zero_flag: zero flag
 * Return: 0
 */

int hand_decimal(int value, int zero_flag)
{
	int prt_ch = 0;

	if (zero_flag)
	{
		printf("%03d", value);
		prt_ch += 3;
	}
	else
	{
		printf("%d", value);
		prt_ch += snprintf(NULL, 0, "%d", value);
	}
	return (prt_ch);
}

/**
 * hndle_string - handles decimals
 * @str: inputted string
 * @zero_flag: zero flag
 * Return: 0
 */

int hndle_string(char *str, int zero_flag)
{
	int prt_ch = 0;

	if (zero_flag)
	{
		int len = strlen(str);
		int padding = 5 - len;

		while (padding > 0)
		{
			putchar('0');
			prt_ch++;
			padding--;
		}
	}
	printf("%s", str);
	prt_ch += strlen(str);
	return (prt_ch);
}
