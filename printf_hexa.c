#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
/**

displayBinaryValue - shows a binary number
@num: numerical argument
@printed: count of exhibited characters
@upperCase: corresponding uppercase representation
Returns: count of displayed characters
*/
int ex_values(unsigned int intNo, int logged, int uppercase)

{
	int hexa[100], index = 0, A;

	while (intNo != 0)
	{
		int modular = intNo % 16;

		if (modular < 10)
		{
			hexa[index] = 48 + modular;
		}
		else
		{
			if (uppercase)
			{
				hexa[index] = 65 + (modular - 10);
			}
			else
			{
				hexa[index] = 97 + (modular - 10);
			}
		}
		index++;
		intNo /= 16;
	}
	if (index == 0)
	{
		_putchar('0');
	logged++;
	}
	else
	{
		for (A = index - 1; A >= 0; A--)
	{
		_putchar(hexa[A]);
		logged++;
		}
	}
	return (logged);
}

