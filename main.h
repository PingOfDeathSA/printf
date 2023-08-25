#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

#define NULL_STRING "(null)"
#define NUL '\0'

/** struct convert - Defines a structure for symbols and associated functions. @sym: The symbol, @f: Associated function. */

struct convert
{
	char *sym;
	int (*f)(va_list);
};
typedef struct convert conver_t;

int _printf(const char *format, ...);
int _putchar(char charector);
int format_reciever(const char *format, conver_t format_type_list[], va_list argument_list_values);
int print_get_percent(va_list);
int print_get_number(va_list);
int print_get_charector(va_list);
int print_get_str(va_list);
int print_get_0_1_binary(va_list);
int print_get_u_i(va_list);
int print_get_oc(va_list argument_list);
int print_get_hexadecimal(va_list argument_list);
int print_get_Hexadecimal(va_list argument_list);
int print_get_Str(va_list output_);
int print_get_arrow_point(va_list output_);
int print_get_reverse(va_list l);
int print_get_allrot13(va_list argument_list);

int print_get_in(va_list Argument);
unsigned int B_length(unsigned int, int);
char *backward_string(char *);
void print_B(char *string);
char *dublicate_memo(char *destination_, char *source, unsigned int n);
int print_undefied_in(unsigned int n);
int hexadecimal_iterate(int number, char x_value);
int print_get_hexadecimal_aux(unsigned long int number);
int unfound_Alph(char c); 
int _enter(char *string);
char *convert(unsigned long int number, int byse, int LC);
#endif

