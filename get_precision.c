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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int get_precision(char *format) {
    int precision = -1;  // initialize to -1 (undefined)
    int len = strlen(format);

    for (int i = 0; i < len; i++) {
        if (format[i] == '.') {
            if (i < len - 1 && isdigit(format[i+1])) {
                // precision is specified with digits after '.'
                precision = atoi(&format[i+1]);
            } else {
                // precision is specified without digits after '.'
                precision = 0;
            }
            break;  // stop searching for precision
        }
    }

    return precision;
}
