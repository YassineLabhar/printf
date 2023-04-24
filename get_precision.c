#include "main.h"

 /*---------------------------------------*/
 /* Authors:                              */
 /* Yassine Labhar: @YassineLabhar        */
 /* Muhammad Ali: @mu9222                 */
 /*---------------------------------------*/

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int i, va_list list)
{
	int precision = -1;

	if (format[i] != '.')
		return (precision);

	i++;

	if (format[i] == '*')
	{
		precision = va_arg(list, int);
		if (precision < 0)
			precision = -1;
		return (precision);
	}

	precision = 0;

	while (is_digit(format[i]))
	{
		precision *= 10;
		precision += (format[i] - '0');
		i++;
	}

	if (precision == 0)
		precision = -1;

	return (precision);
}
