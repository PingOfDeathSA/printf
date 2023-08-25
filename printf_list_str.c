#include "main.h"


/**

printf_list_str - displays a string
@printed: count of displayed characters
@args: number of arguments
Return: count of displayed characters
*/
int printf_list_str(va_list arguments, int logged)
{
	char *str = va_arg(arguments, char *);

	while (*str != '\0')
	{
		_putchar(*str);
		logged++;
		str++;
	}
	return (logged);
}

