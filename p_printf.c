#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * myp_printf - A function that handile convrsion specifier p
 * @format: The format to check
 * Return: 1
 */

int myp_printf(const char *format, ...)
{
	int prt_ch = 0;

	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'p')
			{
				void *ptr;

				ptr = va_arg(args, void*);
				prt_ch += print_pointer(ptr);
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
 * print_pointer - A helpper function that handle p conversion specifier
 * @ptr: The format specifier to check
 * Return: 1
 */
int print_pointer(void *ptr)
{
	int prt_ch;

	prt_ch = printf("%p", ptr);

	return (prt_ch);
}
