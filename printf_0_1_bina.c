#include "main.h"

/**
printf_0_1_bina - displays a binary number
@num: numeric argument
@printed: count of characters printed
Return: count of printed characters
*/

int printf_0_1_bina(unsigned int intNo, int logged)
{
	int binary_0_1[32] = {0};
	int index = 0;

	if (intNo == 0)
	{
		_putchar('0');
		logged++;
		return (logged);
	}

	while (intNo > 0)
	{
		binary_0_1[i] = intNo % 2;
		intNo /= 2;
		index++;
	}

	while (index > 0)
	{
		index--;
		_putchar('0' + binary_0_1[index]);
		logged++;
	}

	return (logged);
}

