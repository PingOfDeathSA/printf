#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
/**

displayInteger - prints an integer number
@arguments: number of arguments
@logged: count of logged characters
Return: count of logged characters
*/

int printf_number(va_list arguments, int logged)
{
	int number = va_arg(arguments, int);
	int binary_int = 0;
	int onhold_num = number;
	int single_binary;

	if (number < 0)
	{
		logged += _putchar('-');
		number = -number;

		onhold_num = number;
	}

	do {
		binary_int++;
		onhold_num /= 10;
	} while (onhold_num != 0);

	while (binary_int > 0)
	{
		int ten1 = 1;
		int index;

		for (index = 1; index < binary_int; index++)
		{
			ten1 *= 10;
		}
		single_binary = number / ten1;
		logged += _putchar(single_binary + '0');
		number -= single_binary * ten1;
		binary_int--;
	}
	return (logged);
}

