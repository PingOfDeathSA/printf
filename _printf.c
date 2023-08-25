#include "main.h"

/**

_printf - Takes a string and its parameters to print formatted content.
@format: Input string with desired characters. Returns total count of printed characters.
*/

int _printf(const char *format, ...)
{
	int logged_charecters;
	conver_t format_type_list[] = {
		{"%", print_get_percent},
		{"d", print_get_number},
		{"i", print_get_number},
		{"c", print_get_charector},
		{"s", print_get_str},
		{"b", print_get_0_1_binary},
		{"u", print_get_u_i},
		{"o", print_get_oc},
		{"x", print_get_hexadecimal},
		{"X", print_get_Hexadecimal},
		{"S", print_get_Str},
		{"p", print_get_arrow_point},
		{"r", print_get_reverse},
		{"R", print_get_allrot13},
		{NULL, NULL},
	};
	va_list argument_list_values;

	if (format == NULL || format < 0)
		return (-1);

	va_start(argument_list_values, format);
	logged_charecters = format_reciever(format, format_type_list, argument_list_values);
	va_end(argument_list_values);
	return (logged_charecters);
}


