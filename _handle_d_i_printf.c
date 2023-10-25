#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * handle_d - function to handle the d and i specifiers
 * @args: Arguments
 * Return: 0
 */

int handle_d(va_list args)
{
	int num = va_arg(args, int);
	char buffer[32];
	int printed = snprintf(buffer, sizeof(buffer), "%d", num);

	if (printed >= 0)
	{
		fputs(buffer, stdout);
		return (printed);
	}
	return (0);
}
