#ifndef MAIN_H
#define MAIN_H

typedef int (*format_handler)(va_list args);
int handle_c(va_list args);
int handle_s(va_list args);
int handle_d(va_list args);
int handle_u(va_list args);
int _vprintf(const char *format, va_list args);
int _printf(const char *format, ...);
int handle_o(va_list args);
int handle_x(va_list args);
int handle_p(va_list args);
#endif
