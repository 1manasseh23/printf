#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int print_binary(unsigned int value);

/**
 * myb_printf - A function to print binary
 * @format: Arguments
 * Return: 0
 */

int myb_printf(const char *format, ...)
{
	int prt_ch = 0, value;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'b')
			{
				value = va_arg(args, unsigned int);
				prt_ch += print_binary(value);
			}
			else
			{
				continue;
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
 * print_binary - A helper function to print binary
 * @value: The value to check for
 * Return: 0
 */

int print_binary(unsigned int value)
{
	int prt_ch = 0;
	unsigned int mask;
	int lead_z = 1;

	if (value == 0)
	{
		putchar(0);
		prt_ch++;
	}
	else
	{
		mask = 1 << (sizeof(value) * 8 - 1);

		while (mask > 0)
		{
			if ((value & mask) || !lead_z)
			{
				putchar((value & mask) ? '1' : '0');
				prt_ch++;
				lead_z = 0;
			}
			mask >>= 1;
		}
	}
	return (prt_ch);
}
