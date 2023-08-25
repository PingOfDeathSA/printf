#include "main.h"

/**

_printf - custom implementation of the built-in printf function
@format: the format string that specifies the output format
Return: the formatted string as per the specified format
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
			logged = Pointer_S(format, arguments, logged);
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

