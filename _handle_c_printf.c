#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_c - function to handle the c specifier
 * @args: Arguments
 * Return: 0.
 */
int handle_c(va_list args)
{
	int arg = va_arg(args, int);

	putchar(arg);
	return (0);
}
/**
 * handle_s - funtion that print str.
 * @args: arguments.
 * Return: 0.
 */
int handle_s(va_list args)
{
	int len = 0;
	char *str = va_arg(args, char *);

	while (*str)
	{
		putchar(*str);
		len++;
		str++;
	}
	return (len);

}
/**
 * handle_percent - function that prints %
 * @args: arguments.
 * Return: 0.
 */
int handle_percent(va_list args)
{
	(void)args;
	putchar('%');
	return (0);
}
