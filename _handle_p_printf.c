#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_p - function to handle the p specifier
 * @args: Arguments
 * Return: 0
 */

int handle_p(va_list args)
{
	void *ptr = va_arg(args, void *);
	char buffer[32];
	int printed = snprintf(buffer, sizeof(buffer), "%p", ptr);

	if (printed >= 0)
	{
		fputs(buffer, stdout);
		return (printed);
	}
	return (0);
}
