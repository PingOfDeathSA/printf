#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 * @...: Variable arguments
 *
 * Return: Number of characters printed
 */
int handle_conversion(const char *format, va_list args)
{
    if (*format == 'c')
        return print_char(args);
    else if (*format == 's')
        return print_string(args);
    else if (*format == '%')
        return print_percent(args);

    return 0; // Invalid specifier
}

int print_char(va_list args)
{
    char c = (char)va_arg(args, int);
    write(1, &c, 1);
    return 1;
}

int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;

    while (*str)
    {
        write(1, str, 1);
        str++;
        count++;
    }

    return count;
}

int print_percent(va_list args)
{
    write(1, "%", 1);
    return 1;
}

int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;

    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
        {
            write(1, format, 1);
            count++;
        }
        else
        {
            format++; // Move past '%'
            count += handle_conversion(format, args);
        }

        format++;
    }

    va_end(args);
    return count;
}
