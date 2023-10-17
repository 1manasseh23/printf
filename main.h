#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
int _putchar(char c);
int id_printf(const char *format, ...);
int print_str_escaped(char *str);
int s_printf(const char *format, ...);
int print_binary(unsigned int value);
int myb_printf(const char *format, ...);
int print_pointer(str);
int myp_printf(const char *format, ...);
int print_hexadecimal(unsigned int value, int uppercase);
int print_octal(unsigned int value);
int print_unsigned_int(unsigned int value);
int uox_printf(const char *format, ...);
int flag_printf(const char *format, ...);
int handle_decimal(int value, int flag_plus, int flag_space, int flag_hash);
char handle_str(int value, int flag_plus, int flag_space, int flag_hash);

#endif
