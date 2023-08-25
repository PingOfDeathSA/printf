#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/**

_printf - implementation of the built-in printf function
@format: the format string used for formatting
Return: the formatted output string
*/


int _printf(const char *format, ...)
{
	int logged = 0;

	va_list arguments;

	va_start(arguments, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			logged = Clacter(format, arguments, logged);
			format++;
		}
		else
		{
			_putchar(*format);
			logged++;
			format++;
		}
	}
	va_end(arguments);
	return (logged);
}

