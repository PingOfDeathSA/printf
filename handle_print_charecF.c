#include "main.h"
/**
print_argument - Displays an argument based on its data type
@format: Formatted string for printing arguments.
@argum_list: List of arguments to print.
@indexInd: Current index in the argument list.
@buffer_list: Buffer array used for printing.
@flags_value: Flags indicating active formatting options.
@width_value: Width specification for formatting.
@precision_value: Precision specification for formatting.
@size_value: Size specifier for numeric conversions.
Return: Returns 1 or 2.
*/
int handle_print_fun(const char *fmt, int *indexInd, va_list argum_list, char buffer_list[],
	int flags_value, int width_value, int precision_value, int size_value)
{
	int index, UnKnwn_Length = 0, P_Cha = -1;
	fmt_t fmt_typs_[] = {
		{'c', handle_print_char}, {'s', handle_print_string}, {'%', handle_print_percent},
		{'i', handle_print_int}, {'d', handle_print_int}, {'b', handle_print_binary},
		{'u', handle_print_unsigned}, {'o', handle_print_octal}, {'x', handle_print_hexadecimal},
		{'X', handle_print_hexa_upper}, {'p', handle_print_pointer}, {'S', handle_non_printable},
		{'r', handle_print_reverse}, {'R', handle_print_rot13string}, {'\0', NULL}
	};
	for (index = 0; fmt_typs_[index].fmt != '\0'; index++)
		if (fmt[*indexInd] == fmt_typs_[index].fmt)
			return (fmt_typs_[index].fn(argum_list, buffer_list, flags_value, width_value, precision_value, size_value));
	if (fmt_typs_[index].fmt == '\0')
	{
		if (fmt[*indexInd] == '\0')
return (-1);
		UnKnwn_Length += write(1, "%%", 1);
		if (fmt[*indexInd - 1] == ' ')
			UnKnwn_Length += write(1, " ", 1);
		else if (width_value)
		{
			--(*indexInd);
			while (fmt[*indexInd] != ' ' && fmt[*indexInd] != '%')
				--(*indexInd);
			if (fmt[*indexInd] == ' ')
				--(*indexInd);
			return (1);
		}
		UnKnwn_Length += write(1, &fmt[*indexInd], 1)
		return (UnKnwn_Length);
	}
	return (P_Cha);
}

