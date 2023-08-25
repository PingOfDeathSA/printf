#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
/**

The Clacter function is responsible for selecting the suitable specifiers.
@param arguments: Count of arguments
@param logged: The characters that have been logged
@param format: The format specifier
@return: The characters that were logged
*/
int Clacter(const char *format, va_list arguments, int logged)

{
	switch (*format)
	{
		case 'd':
		case 'i':
			logged = printf_number(arguments, logged);
			break;
		case 'c':
			_putchar(va_arg(arguments, int));
			logged++;
			break;
		case 's':
			logged = printf_list_str(arguments, logged);
			break;
		case '%':
			_putchar('%');
			logged++;
			break;
		case 'b':
			logged = printf_0_1_bina(va_arg(arguments, unsigned int), logged);
		case 'x':
		case 'X':
			logged = ex_values(va_arg(arguments, unsigned int), logged, (*format == 'X') ? 1 : 0);
			break;
		case 'o':
			logged = printf_OT(va_arg(arguments, unsigned int), logged);
			break;
		case 'u':
			logged = printf_undefiend(va_arg(arguments, unsigned int), logged);
			break;
		case 'r':
			logged = printf_backwards(arguments, logged);
			break;
		case 'p':
			logged = printf_arrow_P(arguments, logged);
			break;
		default:
			break;
	}
	return (logged);
}

