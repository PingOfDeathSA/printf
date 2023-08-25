#include "main.h"

/**

printCharacter - Display a character
@value_types: List of arguments
@buffer_list: Array for printing content
@flags_value: Active flags set
@width_value: Width specification
@precision_value: Precision specification
@size_value: Size indicator
Return: Count of displayed characters
*/


int handle_print_charec(va_list value_types, char buffer_list[],
	int flags_value, int width_value, int precision_value, int size_value)
{
	char charec = va_arg(value_types, int);

	return (handle_handle_write_char(charec, buffer_list, flags_value, width_value, precision_value, size_value));
}

int handle_print_string(va_list value_types, char buffer_list[],
	int flags_value, int width_value, int precision_value, int size_value)
{
	int lenG = 0, index;
	char *string = va_arg(value_types, char *);

	UNUSED(buffer_list);
	UNUSED(flags_value);
	UNUSED(width_value);
	UNUSED(precision_value);
	UNUSED(size_value);
	if (string == NULL)
	{
		string = "(null)";
		if (precision_value >= 6)
			string = "      ";
	}

	while (string[lenG] != '\0')
		lenG++;

	if (precision_value >= 0 && precision_value < lenG)
		lenG = precision_value;

	if (width_value > lenG)
	{
		if (flags_value & Flag_MINUS)
		{
			write(1, &string[0], lenG);
			for (index = width_value - lenG; index > 0; index--)
				write(1, " ", 1);
			return (width_value);
		}
		else
		{
			for (index = width_value - lenG; index > 0; index--)
				write(1, " ", 1);
			write(1, &string[0], lenG);
			return (width_value);
		}
	}

	return (write(1, string, lenG));
}

int handle_print_percent(va_list value_types, char buffer_list[],
	int flags_value, int width_value, int precision_value, int size_value)
{
	UNUSED(value_types);
	UNUSED(buffer_list);
	UNUSED(flags_value);
	UNUSED(width_value);
	UNUSED(precision_value);
	UNUSED(size_value);
	return (write(1, "%%", 1));
}


int handle_print_int(va_list value_types, char buffer_list[],
	int flags_value, int width_value, int precision_value, int size_value)
{ 
	int index = BUFF_SIZE - 2;
	int true_negative = 0;
	long int num = va_arg(value_types, long int);
	unsigned long int number;

	num = handle_convert_size_number(num, size_value);

	if (num == 0)
		buffer_list[index--] = '0';

	buffer_list[BUFF_SIZE - 1] = '\0';
	number = (unsigned long int)num;

	if (num < 0)
	{
		number = (unsigned long int)((-1) * num);
		true_negative = 1;
	}

	while (number > 0)
	{
		buffer_list[index--] = (number % 10) + '0';
		number/= 10;
	}

	index++;

	return (handle_handle_write_number(true_negative, index, buffer_list, flags_value, width_value, precision_value, size_value));
}


int handle_print_binary(va_list value_types, char buffer_list[],
	int flags_value, int width_value, int precision_value, int size_value)
{
	unsigned int x_, z_, indexA, mary_;
	unsigned int b[32];
	int coud;

	UNUSED(buffer_list);
	UNUSED(flags_value);
	UNUSED(width_value);
	UNUSED(precision_value);
	UNUSED(size_value);

	x_ = va_arg(value_types, unsigned int);
	z_ = 2147483648;
	b[0] = x_ / z_;
	for (indexA = 1; indexA < 32; indexA++)
	{
		z_ /= 2;
		b[indexA] = (x_ / z_) % 2;
	}
	for (indexA = 0, mary_ = 0, coud = 0; indexA < 32; indexA++)
	{
		mary_ += b[indexA];
		if (mary_ || indexA == 31)
		{
			char zD = '0' + b[indexA];

			write(1, &zD, 1);
			coud++;
		}
	}
	return (coud);
}

