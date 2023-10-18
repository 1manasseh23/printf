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
int handle_float(double value, int precision);
int handle_exponential(double value, int precision);
int handle_string(char *str, int precision);
int myhp_printf(const char *format, ...);
int handle_decimal(int value, int zero_flag);
int handle_string(char *str, int zero_flag);
int h0_printf(const char *format, ...);
int dash_printf(const char format, ...);
int handle_decimal(int value, int left_dash);
int handle_string(char *str, int left_dash);
int r_printf(const char *format, ...);
int handle_rev_string(char *str);
void rot_encode(char *str);
int R_printf(const char *format, ...);
int _buffer_printf(const char *format, ...);

#endif
