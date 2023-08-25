#include "main.h"
void handle_print_buffer(char buffer_list[], int *buff_indexInd);
/**
_printf - Function for formatted printing
@format: The format string
Return: Number of printed characters
*/
int _printf(const char *format, ...)
{
int charecter_int, Pted = 0, P_Cha = 0;
int flags_value, width_value, precision_value, size_value, buff_indexInd = 0;
va_list argume_list;
char buffer_list[BUFF_SIZE];
if (format == NULL)
return (-1);
va_start(argume_list, format);
for (charecter_int = 0; format && format[charecter_int] != '\0'; charecter_int++)
{
if (format[charecter_int] != '%')
{
buffer_list[buff_indexInd++] = format[charecter_int];
if (buff_indexInd == BUFF_SIZE)
handle_print_buffer(buffer_list, &buff_indexInd);
P_Cha++;
}
else
{
handle_print_buffer(buffer_list, &buff_indexInd);
flags_value = handle_get_flags(format, &charecter_int);
width_value = handle_get_width(format, &charecter_int, argume_list);
precision_value = handle_get_precision(format, &charecter_int, argume_list);
size_value = handle_get_size(format, &charecter_int);
++charecter_int;
Pted = handle_print_fun(format, &charecter_int, argume_list, buffer_list,
flags_value, width_value, precision_value, size_value);
if (Pted == -1)
return (-1);
P_Cha += Pted;
}
}
handle_print_buffer(buffer_list, &buff_indexInd);
va_end(argume_list);
return (P_Cha);
}
void handle_print_buffer(char buffer_list[], int *buff_indexInd)
{
if (*buff_indexInd > 0)
write(1, &buffer_list[0], *buff_indexInd);
*buff_indexInd = 0;
}



