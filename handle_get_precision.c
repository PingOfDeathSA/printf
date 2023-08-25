#include "main.h"


/**

computePrintingPrecision - Calculate print precision
@format: Format string used for argument printing
@i: Index of the argument
@argum_list: List of arguments
Returns: Calculated precision value
*/
int handle_get_precision(const char *format, int *i_, va_list argum_list)
{
	int initial_i = *i_ + 1;
	int precision_value = -1;

	if (format[initial_i] != '.')
		return (precision_value);

	precision_value = 0;

	for (initial_i += 1; format[initial_i] != '\0'; initial_i++)
	{
		if (handle_is_digit(format[initial_i]))
		{
			precision_value *= 10;
			precision_value += format[initial_i] - '0';
		}
		else if (format[initial_i] == '*')
		{
			initial_i++;
			precision_value = va_arg(argum_list, int);
			break;
		}
		else
			break;
	}

	*i_ = initial_i - 1;

	return (precision_value);
}

