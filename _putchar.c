#include "main.h"

/** _putchar - Outputs character 'c' to stdout. Returns 1 on success, -1 on error with errno set. */

int _putchar(char charector)
{
return (write(1, &charector, 1));
}

/**
 * _enter - Writes the string pointed to by 'str' to stdout.
 * @str: Pointer to the string to be printed.
 * Return: Number of characters written.
 */
int _enter(char *string)
{
register short index;
for (index = 0; string[index]; index++)
_putchar(string[index]);
return (index);
}

