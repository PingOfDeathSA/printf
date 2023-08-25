#include "main.h"

/**

detectActiveFlags - Identify enabled flags
@format: Formatted string used for argument printing
@i: Parameter under consideration
Return: Flags that are currently active
*/

int handle_get_flags(const char *format, int *i_)
{

	int F_, initial_i;
	int flags_value = 0;
	const char FLAGS_Charec_value[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_argument_value[] = {Flag_MINUS, Flag_PLUS, Flag_ZERO, Flag_HASH,Flag_SPACE, 0};

	for (initial_i = *i_ + 1; format[initial_i] != '\0'; initial_i++)
	{
		for (F_ = 0; FLAGS_Charec_value[F_] != '\0'; F_++)
			if (format[initial_i] == FLAGS_Charec_value[F_])
			{
				flags_value |= FLAGS_argument_value[F_];
				break;
			}

		if (FLAGS_Charec_value[F_] == 0)
			break;
	}

	*i_ = initial_i - 1;

	return (flags_value);
}


