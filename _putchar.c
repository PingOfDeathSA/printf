#include "main.h"

/**

_putchar - prints a character to the output
@character: The character to be displayed
Return: 1 if successful, -1 on encountering an error
*/
int _putchar(char charTor)
{
	return (write(1, &charTor, 1));
}

