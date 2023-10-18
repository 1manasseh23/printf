#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * myhp_printf - handles precision
 * @format: arguments passed
 * Return: 0
 */

int myhp_printf(const char *format, ...)
{
	int prt_ch = 0, precision = 1;
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '.')
			{
				format++;
				if (*format >= '0' && *format <= '9')
				{
					precision = 0;
					while (*format >= '0' && *format <= '9')
					{
						precision = precision * 10 + (*format - '0');
						format++;
					}
				}
			}
			switch (*format)
			{
				case 's':
					prt_ch += hand_string(va_arg(args, char*), precision);
					break;
				case 'f':
					prt_ch += handle_float(va_arg(args, double), precision);
					break;
				case 'e':
					prt_ch += handle_exponential(va_arg(args, double), precision);
					break;
			}
		}
		else
		{
			putchar(*format);
			prt_ch++;
		}
		format++;
	}
	va_end(args);
	return (prt_ch);
}

/**
 * hand_string - handles string precision
 * @precision: The conversion specifier to handle
 * @str: string to be handled
 * Return: 0
 */

int hand_string(char *str, int precision)
{
	int prt_ch = 0;
	int len;

	if (precision >= 0)
	{
		len = strlen(str);
		printf("%.*s", len, str);
		prt_ch += len;
	}
	else
	{
		printf("%s", str);
		prt_ch += strlen(str);
	}
	return (prt_ch);
}

/**
 * handle_float - handles float precision
 * @precision: The conversion specifier to handle
 * @value: An input double value
 * Return: 0
 */

int handle_float(double value, int precision)
{
	int prt_ch = 0;

	if (precision >= 0)
	{
		printf("%.*f", precision, value);
		prt_ch = snprintf(NULL, 0, "%.*f", precision, value);
	}
	else
	{
		printf("%f", value);
		prt_ch = snprintf(NULL, 0, "%f", value);
	}
	return (prt_ch);
}

/**
 * handle_exponential - handles exponential precision
 * @precision: The conversion specifier to handle
 * @value: An input double value
 * Return: 0
 */

int handle_exponential(double value, int precision)
{
	int prt_ch = 0;

	if (precision >= 0)
	{
		printf("%.*e", precision, value);
		prt_ch = snprintf(NULL, 0, "%.*e", precision, value);
	}
	else
	{
		printf("%e", value);
		prt_ch = snprintf(NULL, 0, "%e", value);
	}
	return (prt_ch);
}
