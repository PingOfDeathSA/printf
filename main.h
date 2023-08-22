
#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#define UNUSED_PARAMETER(x) (void)(x)
#define BUFFER_SIZE 1024

/* Flag constants */
#define FLAG_MINUS  1
#define FLAG_PLUS   2
#define FLAG_SPACE 16
#define FLAG_ZERO   4
#define FLAG_HASH   8


/* Size constants */
#define SIZE_SHORT 1
#define SIZE_LONG  2

struct FormatSpecifier {
    char format_code;
    int (*format_function)(varaible_list, char[], int, int, int, int);
};

typedef struct FormatSpecifier FormatSpecifier_t;

int _printf(const char *format, ...);
int handleprint(const char *format_code, int *index,
    varaible_list arguments, char output_buffer[], int flags_f, int width_W, int precision_P, int size_S);

/****************** FORMAT SPECIFIER FUNCTIONS ******************/

/* Functions for printing characters and strings */
int printcharacter(varaible_list arguments, char output_buffer[],
    int flags_f, int width_W, int precision_P, int size_S);
int printstring(varaible_list arguments, char output_buffer[],
    int flags_f, int width_W, int precision_P, int size_S);
int printpercentsymbol(varaible_list arguments, char output_buffer[],
    int flags_f, int width_W, int precision_P, int size_S);

/* Functions for printing numbers */
int printinteger(varaible_list arguments, char output_buffer[],
    int flags_f, int width_W, int precision_P, int size_S);
int printbinary(varaible_list arguments, char output_buffer[],
    int flags_f, int width, int precision_P, int size_S);
int printunsignedinteger(varaible_list arguments, char output_buffer[],
    int flags_f, int width_W, int precision_P, int size_S);
int print_octal(varaible_list arguments, char output_buffer[],
    int flags_f, int width_W, int precision_P, int size_S);
int printhexadecimal_lower(varaible_list arguments, char output_buffer[],
    int flags_f, int width_W, int precision_P, int size_S);
int print_hexadecimal_upper(varaible_list arguments, char output_buffer[],
    int flags_f, int width_W, int precision_P, int size_S);

int printcustomhexadecimal(varaible_list arguments, char hex_map[],
    char output_buffer[], int flags_f, char flag_character, int width_W, int precision_P, int size_S);

/* Function for printing non-printable characters */
int printnonprintablecharacters(varaible_list arguments, char output_buffer[],
    int flags_f, int width_W, int precision_P, int size_S);

/* Function for printing memory addresses */
int printmemoryaddress(varaible_list arguments, char output_buffer[],
    int flags_f, int width_W, int precision_P, int size_S);

/* Functions for handling other specifiers */
int extractflags_f(const char *format, int *index);
int extractwidth(const char *format, int *index, varaible_list arguments);
int extractprecisionP(const char *format, int *index, varaible_list arguments);
int extractsize(const char *format, int *index);

/* Function for printing reversed strings */
int print_reversed_string(varaible_list arguments, char output_buffer[],
    int flags_f, int width_W, int precision_P, int size_S);

/* Function for printing a ROT13-encoded string */
int printrot13encodedprtring(varaible_list arguments, char output_buffer[],
    int flags_f, int width_W, int precision_P, int size_S);

/* Width handler functions */
int handlecharacterwrite(char character, char output_buffer[],
    int flags_f, int width_W, int precision_P, int size_S);
int writeinteger(int is_positive, int index, char output_buffer[],
    int flags_f, int width_W, int precision_P, int size_S);
int writenumericvalue(int index, char bff[], int flags_f, int width_W, int precision_P,
    int length, char padding_character, char extra_character);
int writememoryaddress(char output_buffer[], int index, int length,
    int width_W, int flags_f, char padding_character, char extra_character, int padding_start);

int writeunsignedvalue(int is_negative, int index,
    char output_buffer[], int flags_f, int width_W, int precision_P, int size_S);

/****************** UTILITY FUNCTIONS ******************/
int ischaracterprintable(char);
int appendhexadecimalcode(char input_character, char output_array[], int index);
int ischaracterdigit(char);

long int resize_integervalue(long int number, int target_size);
long int resize_unsignedvalue(unsigned long int number, int target_size);

#endif /* MAIN_H */

