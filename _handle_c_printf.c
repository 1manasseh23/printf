#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_c - function to handle the c specifier
 * @args: Arguments
 * Return: 0
 */

int handle_c(va_list args)
{
	int c = va_arg(args, int);

	return (putchar(c));
}
