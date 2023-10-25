#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_x - function to handle the x and X specifiers
 * @args: Arguments
 * Return: 0
 */

int handle_X(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[32];
	int printed = snprintf(buffer, sizeof(buffer), "%X", num);

	if (printed >= 0)
	{
		fputs(buffer, stdout);
		return (printed);
	}
	return (0);
}
