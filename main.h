#ifndef MAIN_H
#define MAIN_H
#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

int putchar(char charTor);
int printf_char(va_list arguments, int logged);
int printf_OT(unsigned int intNo, int logged);
int Clacter(const char *format, va_list arguments, int logged);
int printf_undefiend(unsigned int intNo, int logged);
int printf_arrow_P(va_list arguments, int logged);
int printf_list_str(va_list arguments, int logged);
int printf_backwards(va_list arguments, int logged);
int printf_number(va_list arguments, int logged);
int printf_0_1_bina(unsigned int intNo, int logged);
int _printf(const char *format, ...);
int ex_values(unsigned int intNo, int logged, int uppercase);

#endif

