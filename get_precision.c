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
int get_precision(const char *format, int start, va_list args) {
    int precision = -1;
    bool found_precision = false;
    int i;

    for (i = start; format[i] != '\0'; i++) {
        if (format[i] == '.') {
            found_precision = true;
            continue;
        }

        if (found_precision && isdigit(format[i])) {
            if (precision == -1) {
                precision = 0;
            }
            precision = (precision * 10) + (format[i] - '0');
        } else if (found_precision) {
            break;
        }
    }

    if (precision == -1) {
        precision = va_arg(args, int);
    }

    return precision;
}
