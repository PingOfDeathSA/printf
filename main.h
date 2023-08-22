
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
    int (*format_function)(va_list, char[], int, int, int, int);
};

typedef struct FormatSpecifier FormatSpecifier_t;

int _printf(const char *format, ...);
int handle_print(const char *format_code, int *index,
    va_list arguments, char output_buffer[], int flags, int width, int precision, int size);

/****************** FORMAT SPECIFIER FUNCTIONS ******************/

/* Functions for printing characters and strings */
int print_character(va_list arguments, char output_buffer[],
    int flags, int width, int precision, int size);
int print_string(va_list arguments, char output_buffer[],
    int flags, int width, int precision, int size);
int print_percent_symbol(va_list arguments, char output_buffer[],
    int flags, int width, int precision, int size);

/* Functions for printing numbers */
int print_integer(va_list arguments, char output_buffer[],
    int flags, int width, int precision, int size);
int print_binary(va_list arguments, char output_buffer[],
    int flags, int width, int precision, int size);
int print_unsigned_integer(va_list arguments, char output_buffer[],
    int flags, int width, int precision, int size);
int print_octal(va_list arguments, char output_buffer[],
    int flags, int width, int precision, int size);
int print_hexadecimal_lower(va_list arguments, char output_buffer[],
    int flags, int width, int precision, int size);
int print_hexadecimal_upper(va_list arguments, char output_buffer[],
    int flags, int width, int precision, int size);

int print_custom_hexadecimal(va_list arguments, char hex_map[],
    char output_buffer[], int flags, char flag_character, int width, int precision, int size);

/* Function for printing non-printable characters */
int print_non_printable_characters(va_list arguments, char output_buffer[],
    int flags, int width, int precision, int size);

/* Function for printing memory addresses */
int print_memory_address(va_list arguments, char output_buffer[],
    int flags, int width, int precision, int size);

/* Functions for handling other specifiers */
int extract_flags(const char *format, int *index);
int extract_width(const char *format, int *index, va_list arguments);
int extract_precision(const char *format, int *index, va_list arguments);
int extract_size(const char *format, int *index);

/* Function for printing reversed strings */
int print_reversed_string(va_list arguments, char output_buffer[],
    int flags, int width, int precision, int size);

/* Function for printing a ROT13-encoded string */
int print_rot13_encoded_string(va_list arguments, char output_buffer[],
    int flags, int width, int precision, int size);

/* Width handler functions */
int handle_character_write(char character, char output_buffer[],
    int flags, int width, int precision, int size);
int write_integer(int is_positive, int index, char output_buffer[],
    int flags, int width, int precision, int size);
int write_numeric_value(int index, char bff[], int flags, int width, int precision,
    int length, char padding_character, char extra_character);
int write_memory_address(char output_buffer[], int index, int length,
    int width, int flags, char padding_character, char extra_character, int padding_start);

int write_unsigned_value(int is_negative, int index,
    char output_buffer[], int flags, int width, int precision, int size);

/****************** UTILITY FUNCTIONS ******************/
int is_character_printable(char);
int append_hexadecimal_code(char input_character, char output_array[], int index);
int is_character_digit(char);

long int resize_integer_value(long int number, int target_size);
long int resize_unsigned_value(unsigned long int number, int target_size);

#endif /* MAIN_H */

