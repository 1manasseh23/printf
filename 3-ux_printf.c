#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * uox_printf - A function that handle the conversion
 * specifiers or uoxX characters
 * @format: The conversio format to check for
 * Return: 1
 */

int uox_printf(const char *format, ...)
{
	int prt_ch = 0;
	va_list args;

	va_start(args, format);
	unsigned int u_value, o_value, x_value, X_value;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'u':
					u_value = va_arg(args, unsigned int);
					prt_ch += print_unsigned_int(u_value);
					break;
				case 'o':
					o_value = va_arg(args, unsigned int);
					prt_ch += print_octal(o_value);
					break;
				case 'x':
					x_value = va_arg(args, unsigned int);
					prt_ch += print_hexadecimal(x_value, 0);
					break;
				case 'X':
					X_value = va_arg(args, unsigned int);
					prt_ch += print_hexadecimal(X_value, 1)
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
 * print_unsigned_int - A helper function to handle conversion specifier for u
 * @value: The value to check
 * Return: 1
 */
int print_unsigned_int(unsigned int value)
{
	printf("%u", value);
	return (snprintf(NULL, 0, "%u", value));
}
/**
 * print_octal - A helper function to handle conversion specifier for o
 * @value: The value to check
 * Return: 1
 */
int print_octal(unsigned int value)
{
	printf("%o", 0, value);
	return (snprintf(NULL, "%o", value));
}
/**
 * print_hexadecimal - A helper function to handle
 * conversion specifier for hexadecimal
 * @value: The value to check
 * @uppercase: For the hexadeciamal check
 * Return: 1
 */
int print_hexadecimal(unsigned int value, int uppercase)
{
	const char *hex_chrs = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

	char hex_buffer[20];

	char i = 0;
	int x;

	while (value > 0)
	{
		hex_buffer[i] = hex_chrs[value % 16];
		value /= 16;
		i++;
	}
	hex_buffer[i] = '\0';

	for (x = i - 1; x >= 0; x--)
	{
		putchar(hex_buffer[x]);
	}
	return (i);
}
