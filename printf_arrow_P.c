#include "main.h"

#define Limit_hexa_binary 16

/**
printf_arrow_P - displays a binary number
@arguments: number of arguments
@logged: count of logged characters
*/
int printf_arrow_P(va_list arguments, int logged);
{
	void *pointer = va_arg(arguments, void*);
	unsigned long nmber = (unsigned long) pointer;
	int binary = 0;
	int index;
	unsigned long onhold = nmber;
	char hex_binary[Limit_hexa_binary] = "0123456789abcdef";
	char hexa[Limit_hexa_binary];

	while (onhold != 0)
	{
		binary++;
		onhold /= 16;
	}

	logged += _putchar('0');
	logged += _putchar('x');

	if (nmber == 0)
	{
		logged += _putchar('0');
	}
	else
	{
		for (index = binary - 1; index >= 0; index--)
		{
			int digit = nmber % 16;
		hexa[index] = hex_binary[digit];
			nmber /= 16;
		}
		for (index = 0; index < binary;index++)
		{
			logged += _putchar(hexa[index]);
		}
	}
	return (logged);
}

