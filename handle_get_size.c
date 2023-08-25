#include "main.h"
/**
 * handle_get_size - Determine the size for argument casting
 * @format: Format string for argument printing
 * @i: Argument index
 *
 * Return: Calculated size for casting
 */

int handle_get_size(const char *format, int *i_)
{
int initial_i = *i_ + 1;
int size_value = 0;
if (format[initial_i] == 'l')
size_value = S_LONG;
else if (format[initial_i] == 'h')
size_value = S_SHORT;
if (size_value == 0)
*i_ = initial_i - 1;
else
*i_ = initial_i;
return (size_value);
}

