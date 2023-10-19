#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - A function that tfunctions like printf
 * @format: Arguments
 * Return: 0
 */
int _printf(const char *format, ...)
{
	int length;
	va_list args;

	va_start(args, format);
	length = _vprintf(format, args);
	va_end(args);
	return (length);
}

