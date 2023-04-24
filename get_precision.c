#include "main.h"

 /*---------------------------------------*/
 /* Authors:                              */
 /* Yassine Labhar: @YassineLabhar        */
 /* Muhammad Ali: @mu9222                 */
 /*---------------------------------------*/

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: Pointer to the current position in the format string
 * @list: list of arguments
 * Return: The precision value, or -1 if it is not specified
 */

int get_precision(const char *format, int *i, va_list list)
{
	int precision = -1;

	if (format[*i] == '.')
	{
		precision = 0;
		++(*i);

		if (format[*i] == '*')
		{
			precision = va_arg(list, int);
			++(*i);
		}
		else
		{
			while (format[*i] >= '0' && format[*i] <= '9')
			{
				precision = precision * 10 + (format[*i] - '0');
				++(*i);
			}
		}
	}

	return (precision);
}
