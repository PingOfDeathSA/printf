#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
/**

printBinaryInt - prints a binary integer
@intNo: integer number of arguments
@logged: count of logged characters
Return: count of logged characters
*/
int printf_OT(unsigned int intNo, int logged)

{
	int oct[100], index = 0, a;

	while (intNo != 0)
	{
		int remainder = intNo % 8;

		oct[index] = 48 + remainder;
		index++;
		intNo /= 8;
	}

	if (index == 0)
	{
		_putchar('0');
		logged++;
	}
	else
	{
		for (a = index - 1; a >= 0; a--)
		{
			_putchar(oct[a]);
			logged++;
		}
	}
	return (logged);
}

