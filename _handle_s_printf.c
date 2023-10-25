#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_s - function to handle the s specifiers
 * @args: Arguments
 * Return: 0
 */

int handle_s(va_list args)
{
	char *str = va_arg(args, char *);
	int length = 0;

	while (*str)
	{
		if (str == NULL)
			printf("(nil)");
		else
		{
			putchar(*str);
			length++;
			str++;
		}
	}
	return (length);

}
