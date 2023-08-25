#include "main.h"

/**

computePrintingWidth - Calculate the width for output formatting
@format: Format string used for argument printing
@i_: Index of the argument
@list: List of arguments
Returns: Calculated width for formatting purposes
*/

int handle_get_width(const char *format, int *i_, va_list argum_list)
{
int initial_i;
int width_value = 0;
for (initial_i = *i_ + 1; format[initial_i] != '\0'; initial_i++)
{
if (handle_is_digit(format[initial_i]))
{
width_value *= 10;
width_value += format[initial_i] - '0';
}
else if (format[initial_i] == '*')
{
initial_i++;
width_value = va_arg(argum_list, int);
break;
}
else
break;
}
*i_ = initial_i - 1;
return (width_value);
}

