#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_u - function to handle the u specifiers
 * @args: Arguments
 * Return: 0
 */

int handle_u(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[32];
	int printed = snprintf(buffer, sizeof(buffer), "%u", num);

	if (printed >= 0)
	{
		fputs(buffer, stdout);
		return (printed);
	}
	return (0);
}
