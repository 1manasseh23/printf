#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - _printf function
 * @format: Arguments to be passed
 * Return: 0
 */

int _printf(const char *format, ...)
{
	int i = 0, x, length = 0;
	va_list args;

	match m[] = {
		{"%c", char_str_printf}, {"%s", char_str_printf},
		{"%%", char_str_printf}, {"%d", id_printf}, {"%i", id_printf},
		{"%r", r_printf}, {"%b", myb_printf}, {"%u", uox_printf},
		{"%o", uox_printf}, {"%x", uox_printf}, {"%X", uox_printf},
		{"%R", R_printf}, {"%S", s_printf}, {"%p", myp_printf}
	};

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
Here:
	while (format[i] != '\0')
	{
		x = 12;
		while (x >= 0)
		{
			if (m[x].id[0] == format[i] && m[x].id[1] == format[i + 1])
			{
				length = length + m[x].f(m[x].id, args);
				i = i + 2;
				goto Here;
			}
			x--;
		}
		putchar(format[i]);
		i++;
		length++;
	}
	va_end(args);
	return (length);
}
