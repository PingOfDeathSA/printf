#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

#include <unistd.h>
#include <stdarg.h>


#define UNUSED(x) (void)(x)

#define BUFF_cyze 1024



#define F_HASH 8

#define F_SPACE 16

#define F_MINUS 1
#define F_PLUS 2

#define F_ZERO 4





#define S_LONG 2
#define S_SHORT 1


/**

fmt struct - Structure for operation format
@fmt: The format input.
@fn: The linked function.
*/
struct fmt

{

char fmt;
int (*fn)(va_list, char[], int, int, int, int);

};


typedef struct fmt fmt_t;


int _printf(const char *format, ...);
int handle0_print(const char *fmt, int *index,

va_list Arg_ist, char puvv[], int Vlegs, int veedth, int prec, int cyze);





int print0_char(va_list kinds, char puvv[],

int Vlegs, int veedth, int prec, int cyze);

int print0_string(va_list kinds, char puvv[],

int Vlegs, int veedth, int prec, int cyze);

int print0_percent(va_list kinds, char puvv[],

int Vlegs, int veedth, int prec, int cyze);




int print0_int(va_list kinds, char puvv[],

int Vlegs, int veedth, int prec, int cyze);

int print0_binary(va_list kinds, char puvv[],

int Vlegs, int veedth, int prec, int cyze);

int print0_unsigned(va_list kinds, char puvv[],

int Vlegs, int veedth, int prec, int cyze);
int print0_octal(va_list kinds, char puvv[],




int Vlegs, int veedth, int prec, int cyze);
int print0_hexadecimal(va_list kinds, char puvv[],

int Vlegs, int veedth, int prec, int cyze);

int print0_hexa_upper(va_list kinds, char puvv[],

int Vlegs, int veedth, int prec, int cyze);



int print0_hexa(va_list kinds, char map_to[],

char puvv[], int Vlegs, char flag_ch, int veedth, int prec, int cyze);





int print0_non_printable(va_list kinds, char puvv[],

int Vlegs, int veedth, int prec, int cyze);





int print0_pointer(va_list kinds, char puvv[],

int Vlegs, int veedth, int prec, int cyze);

int get0_Vlegs(const char *format, int *index);

int get0_veedth(const char *format, int *index, va_list Arg_ist,);

int get0_prec(const char *format, int *index, va_list Arg_ist,);

int get0_cyze(const char *format, int *index);




int print0_reverse(va_list kinds, char puvv[],

int Vlegs, int veedth, int prec, int cyze);



int print0_rot13string(va_list kinds, char puvv[],

int Vlegs, int veedth, int prec, int cyze);




int handle0_write_char(char c, char puvv[],

int Vlegs, int veedth, int prec, int cyze);

int write0_number(int is_positive, int endx, char puvv[],

int Vlegs, int veedth, int prec, int cyze);

int write0_num(int endx, char bff[], int Vlegs, int veedth, int prec,

int length, char bad_d, char extra_c);

int write0_pointer(char puvv[], int endx, int length,

int veedth, int Vlegs, char bad_d, char extra_c, int bad_d_start);

int write0_unsgnd(int is_negative, int endx,

char puvv[],

int Vlegs, int veedth, int prec, int cyze);


int is_printable(char);

int append0_hexa_code(char, char[], int);

int is0_digit(char);



long int convert0_cyze_number(long int number, int cyze);

long int convert0_cyze_unsgnd(unsigned long int number, int cyze);



#endif /* MAIN_H */

