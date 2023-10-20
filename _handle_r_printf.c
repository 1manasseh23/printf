#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <string.h>

/**
 * handle_r - function to handle the c specifier
 * @args: Arguments
 * Return: 0
 */

int handle_r(va_list args)
{
	char *str = va_arg(args, char *);
	int printed = 0;
	int len, i;

	len = strlen(str);
	for (i = len - 1; i >= 0; i--) 
		
	{
		write_char(str[i]);
		printed++;
	}
	return printed;
}

