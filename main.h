#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**

Structure representing a format specifier with its associated handling function.
*/
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/** 
 * Defines a structure fmt_t, which represents a format and its associated function.
 *
 * @fmt: The format data.
 * @fm_t: The corresponding associated function.
 */

typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print_fun(const char *fmt, int *indexInd,
va_list argum_list, char buffer_list[], int flags_value, int width_value, int precision_value, int size_value);



/* Functions for printing characters and strings */
int handle_print_char(va_list value_types, char buffer_list[],
	int flags_value, int width_value, int precision_value, int size_value);
int handle_print_string(va_list value_types, char buffer_list[],
	int flags_value, int width_value, int precision_value, int size_value);
int handle_print_percent(va_list value_types, char buffer_list[],
	int flags_value, int width_value, int precision_value, int size_value);

/* Functions for printing numerical values */
int handle_print_int(va_list value_types, char buffer_list[],
	int flags_value, int width_value, int precision_value, int size_value);
int handle_print_binary(va_list value_types, char buffer_list[],
	int flags_value, int width_value, int precision_value, int size_value);
int handle_print_unsigned(va_list value_types, char buffer_list[],
	int flags_value, int width_value, int precision_value, int size_value);
int handle_print_octal(va_list value_types, char buffer_list[],
	int flags_value, int width_value, int precision_value, int size_value);
int handle_print_hexadecimal(va_list value_types, char buffer_list[],
	int flags_value, int width_value, int precision_value, int size_value);
int handle_print_hexa_upper(va_list value_types, char buffer_list[],
	int flags_value, int width_value, int precision_value, int size_value);

int handle_print_hexa(va_list value_types, char map_to[],
char buffer_list[], int flags_value, char flag_ch, int width_value, int precision_value, int size_value);

/* Function for printing non-printable characters */
int handle_non_printable(va_list value_types, char buffer_list[],
	int flags_value, int width_value, int precision_value, int size_value);
int handle_print_pointer(va_list value_types, char buffer_list[],
	int flags_value, int width_value, int precision_value, int size_value);
int handle_get_flags(const char *format, int *i_);
int handle_get_width(const char *format, int *i_, va_list argum_list);
int handle_get_precision(const char *format, int *i_, va_list argum_list);
int handle_get_size(const char *format, int *i_);

int handle_print_reverse(va_list value_types, char buffer_list[],
	int flags_value, int width_value, int precision_value, int size_value);

int handle_print_rot13string(va_list value_types, char buffer_list[],
	int flags_value, int width_value, int precision_value, int size_value);

int handle_handle_write_char(char c, char buffer_list[],
	int flags_value, int width_value, int precision_value, int size_value);
int handle_handle_write_number(int is_positive, int indexInd, char buffer_list[],
	int flags_value, int width_value, int precision_value, int size_value);
int handle_write_num(int indexInd, char buff[], int flags_value, int width_value, int precision_value,
	int length, char pading_padd, char ex_charec);
int handle_write_pointer(char buffer_list[], int indexInd, int length,
	int width_value, int flags_value, char pading_padd, char ex_charec, int pading_start);

int handle_write_unsgnd(int true_negative, int indexInd,
char buffer_list[],
	int flags_value, int width_value, int precision_value, int size_value);

/****************** UTILS ******************/
int handle_is_printable(char);
int handle_append_hexa_code(char, char[], int);
int handle_is_digit(char);

long int handle_convert_size_number(long int number, int size_value);
long int handle_convert_size_unsgnd(unsigned long int number, int size_value);

#endif /* MAIN_H */

