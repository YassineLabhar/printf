#include "main.h"

 /*---------------------------------------*/
 /* Authors:                              */
 /* Yassine Labhar: @YassineLabhar        */
 /* Muhammad Ali: @mu9222                 */
 /*---------------------------------------*/

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: Index of the current character in the format string
 * @list: List of arguments
 *
 * Return: The precision
 */
int get_precision(const char *format, int i, va_list list)
{
    int precision = -1;

    if (format[i] != '.')
        return (precision);

    precision = 0;
    i++;

    if (format[i] == '*')
    {
        precision = va_arg(list, int);
        i++;
    }
    else
    {
        while (is_digit(format[i]))
        {
            precision = precision * 10 + (format[i] - '0');
            i++;
        }
    }

    return (precision);
}
