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
	int printed = 0, i;

	if (str == NULL)
	{
		return (fputs("(null)", stdout));
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			printed += printf("\\x%02X", (unsigned char)str[i]);
		}
		else
		{
			printed += putchar(str[i]);
		}
	}
	return (printed);
}
