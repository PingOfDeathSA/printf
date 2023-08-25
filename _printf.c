
#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - implementation of the inbuilt printf
 * @format: the format specifier
 * Return: the formated string
 */



int _printf(const char *format, ...) {
    va_list arg_list;
    va_start(arg_list, format);

    int printed_chars = 0;
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            if (format[i] == 'c') {
                char c = va_arg(arg_list, int);
                _putchar(c);
                printed_chars++;
            } else if (format[i] == 's') {
                char *str = va_arg(arg_list, char *);
                for (int j = 0; str[j] != '\0'; j++) {
                    _putchar(str[j]);
                    printed_chars++;
                }
            } else if (format[i] == '%') {
                _putchar('%');
                printed_chars++;
            }
        } else {
            _putchar(format[i]);
            printed_chars++;
        }
    }

    va_end(arg_list);

    return printed_chars;
}




