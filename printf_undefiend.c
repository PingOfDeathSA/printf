#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
/**

/**
 * printUnspecified - displays a binary intNober
 * @intNo: count of arguments
 * @displayed: quantity of shown characters
 * Return: count of displayed characters
 */

int printf_undefiend(unsigned int intNo, int logged)

{
	int binanry = 0;
	unsigned int T_int = intNo;

	do {
		binanry++;
		T_int /= 10;
	} while (T_int != 0);

	if (intNo == 0)
	{
		_putchar('0');
		logged++;
	}
	else
	{
		char undefined_string[11];
		int index = 0;

		while (intNo != 0)
		{
			undefined_string[index] = (intNo % 10) + '0';
			intNo /= 10;
			index++;
		}
		for (index = binanry - 1; index >= 0; index--)
		{
			_putchar(undefined_string[index]);
			logged++;
		}
	}
	return (logged);
}

