#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_o - function to handle the o specifier
 * @args: Arguments
 * Return: 0
 */

int handle_o(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[32];
	int printed = snprintf(buffer, sizeof(buffer), "%o", num);

	if (printed >= 0)
	{
		fputs(buffer, stdout);
		return (printed);
	}
	return (0);
}
