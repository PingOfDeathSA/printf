#include "main.h"

/**

print_character - Prints a character
@arguments: List of arguments
@output_buffer: Buffer array for printing
@flags: Active flags calculation
@width: Width specification
@precision: Precision specification
@size: Size specifier
Return: Number of characters printed
*/
int printcharacter(varaible_list arguments, char output_buffer[],
	int flags_f, int width_W, int precision_P, int size_S)
{
	char character = va_arg(arguments, int);

	return (handlecharacterwrite(character, output_buffer, flags_f, width_W, precision_P, size_S));
}
/************************* PRINT_start*************************/

int printstring(varaible_list arguments, char output_buffer[],
    int flags_f, int width_W, int precision_P, int size_S);
{
	int len = 0, index;
	char *string = va_arg(arguments, char *);

	UNUSED_PARAMETER(output_buffer);
	UNUSED_PARAMETER(flags_f);
	UNUSED_PARAMETER(width_W);
	UNUSED_PARAMETER(precision_P);
	UNUSED_PARAMETER(size_S);
	if (string == NULL)
	{
		string = "(null)";
		if (precision_P >= 6)
			string = "      ";
	}

	while (string[len] != '\0')
		len++;

	if (precision_P >= 0 && precision_P < len)
		len = precision_P;

	if (width_W > len)
	{
		if (flags_f & FLAG_MINUS)
		{
			write(1, &string[0], len);
			for (index = width_W - len; index > 0; index--)
				write(1, " ", 1);
			return (width_W);
		}
		else
		{
			for (index = width_W - len; index > 0; index--)
				write(1, " ", 1);
			write(1, &string[0], len);
			return (width_W);
		}
	}

	return (write(1, str, len));
}
/************************* PRINT *************************/

int printpercentsymbol(varaible_list arguments, char output_buffer[],
    int flags_f, int width_W, int precision_P, int size_S);
{
	UNUSED_PARAMETER(arguments);
		UNUSED_PARAMETER(arguments);
	UNUSED_PARAMETER(flags_f);
	UNUSED_PARAMETER(width_W);
	UNUSED_PARAMETER(precision_P);
	UNUSED_PARAMETER(size_S);
	return (write(1, "%%", 1));
}

/************************* PRINT Num*************************/

int printinteger(varaible_list arguments, char output_buffer[],
    int flags_f, int width_W, int precision_P, int size_S);
{
	int index = BUFFER_SIZE - 2;
	int is_negative = 0;
	long int number = va_arg(arguments, long int);
	unsigned long int number;

	nnum = resize_integervalue(number, target_size);

	if (nnum == 0)
		output_buffer[index--] = '0';

	output_buffer[BUFFER_SIZE - 1] = '\0';
	number = (unsigned long int)nnum;

	if (nnum < 0)
	{
		number = (unsigned long int)((-1) * nnum);
		is_negative = 1;
	}

	while (number > 0)
	{
	output_buffer[index--] = (number % 10) + '0';
	number /= 10;
	}

	i++;

	return (writeinteger(is_negative, index, output_buffer, flags_f, width_W, precision_P, size_S));
}


int printbinary(varaible_list arguments, char output_buffer[],
    int flags_f, int width, int precision_P, int size_S);
{
	unsigned int numbers, mid, index, suming;
	unsigned int arrae[32];
	int counting;


		UNUSED_PARAMETER(arguments);
	UNUSED_PARAMETER(flags_f);
	UNUSED_PARAMETER(width_W);
	UNUSED_PARAMETER(precision_P);
	UNUSED_PARAMETER(size_S);

	numbers = va_arg(arguments, unsigned int);
	mid = 2147483648;
	arrae[0] = numbers / mid;
	for (index = 1; index < 32; index++)
	{
		mid /= 2;
		arrae[index] = (numbers / mid) % 2;
	}
	for (i = 0, suming = 0, counting = 0; index < 32; index++)
	{
		suming += arrae[index];
		if (suming || index == 31)
		{
			char ad = '0' + arrae[index];

			write(1, &ad, 1);
			counting++;
		}
	}
	return (counting);
}

