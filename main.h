#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <limits.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct format
{
	const char *id;
	int (*f)(const char *, ...); 
} match;


int _printf(const char *format, ...);
int _putchar(char c);
int char_str_printf(const char *format, ...);
int id_printf(const char *format, ...);
int print_str_escaped(char *str);
int s_printf(const char *format, ...);
int print_binary(unsigned int value);
int myb_printf(const char *format, ...);
int print_pointer(void *ptr);
int myp_printf(const char *format, ...);
int print_hexadecimal(unsigned int value, int uppercase);
int print_octal(unsigned int value);
int print_unsigned_int(unsigned int value);
int uox_printf(const char *format, ...);
int handle_decimal(int value, int flag_plus, int flag_space, int flag_hash);
char handle_str(int value, int flag_plus, int flag_space, int flag_hash);
int handle_float(double value, int precision);
int handle_exponential(double value, int precision);
int hand_string(char *str, int precision);
int myhp_printf(const char *format, ...);
int hand_decimal(int value, int zero_flag);
int hndle_string(char *str, int zero_flag);
int h0_printf(const char *format, ...);
int dash_printf(const char *format, ...);
int hd_string(char *str, int left_dash);
int hd_decimal(int value, int left_dash);
int r_printf(const char *format, ...);
int handle_rev_string(char *str);
void rot_encode(char *str);
int R_printf(const char *format, ...);
int _buffer_printf(const char *format, ...);
int handle_dec(int value, int width);
int handle_st(char *str, int width);
void flags_printf(const char *format, ...);

#endif
