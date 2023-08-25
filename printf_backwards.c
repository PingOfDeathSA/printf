#include "main.h"

/**
 *printf_backwards - displays a binary number in reverse order
 * @args: num of args
 */


int printf_backwards(va_list arguments, int logged)
{
	char *string = va_arg(arguments, char *);
	int l_ngth = 0, index;

	while (string[l_ngth])
	{
		l_ngth++;
	}

	for (index = l_ngth - 1; index >= 0; index--)
	{
		_putchar(string[index]);
		logged++;
	}

	return (logged);
}

