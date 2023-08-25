#include "main.h"

/**
 * printf_char - displays a binary numeral
 * @args: input arguments for the function
 * @printed: count of characters printed
 * Return: count of printed characters
 */

int printf_char(va_list arguments, int logged)
{
	int chrec = va_arg(arguments, int);
	_putchar(chrec);
	return (logged + 1);
}
