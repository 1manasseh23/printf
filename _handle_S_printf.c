#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_S - function to handle the S specifier
 * @args: Arguments
 * Return: 0
 */

int handle_S(va_list args)
{
	char *str = va_arg(args, char *);
	int printed = 0;

	while (*str)
	{
		if ((*str >= 1 && *str <= 31) || *str >= 127)
		{
			printf("\\x%02X", (unsigned char)*str);
			printed += 4;
		}
		else
		{
			putchar(*str);
			printed++;
		}
		str++;
	}
	return (printed);
}
