#include "main.h"

 /*---------------------------------------*/
 /* Authors:                              */
 /* Yassine Labhar: @YassineLabhar        */
 /* Muhammad Ali: @mu9222                 */
 /*---------------------------------------*/

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
    va_list args;
    int len = 0;
    const char *str;
    int precision;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            precision = 0;

            // check for precision
            if (*format == '.')
            {
                format++;
                while (*format >= '0' && *format <= '9')
                {
                    precision = (precision * 10) + (*format - '0');
                    format++;
                }
            }

            switch (*format)
            {
                case 's':
                    str = va_arg(args, const char *);
                    if (str == NULL)
                    {
                        len += _print("(null)");
                        break;
                    }
                    
                    // check if the string is shorter than the specified precision
                    if (precision == 0 || precision >= _strlen(str))
                        len += _print(str);
                    else
                        len += _printn(str, precision);
                    
                    break;

                // Handle other cases here
                
                default:
                    len += _print_char('%');
                    len += _print_char(*format);
                    break;
            }
        }
        else
        {
            len += _print_char(*format);
        }
        format++;
    }

    va_end(args);

    return (len);
}
