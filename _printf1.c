#include "main.h"

/**
 * _printf - functions like printf
 * @format: The format string
 *
 * Description: This function prints formatted output for integers.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
    int num_char = 0;
    const char *conv = format;
    va_list num_args;

    if (conv == NULL)
    {
        return (-1);
    }

    va_start(num_args, format);

    while (*conv)
    {
        if (*conv != '%')
        {
            write(1, conv, 1);
            num_char++;
        }
        else
        {
            conv++;

            if (*conv == '\0')
            {
                break;
            }
            if (*conv == '%')
            {
                write(1, conv, 1);
                num_char++;
            }

            if (*conv == 'd' || *conv == 'i')
            {
                int x = va_arg(num_args, int);

                // Handle negative numbers
                if (x < 0)
                {
                    write(1, "-", 1);
                    x = -x;
                }

                // Convert and print the integer
                char buffer[12]; // Maximum 10 digits for int + sign and null terminator
                int index = 0;

                if (x == 0)
                {
                    buffer[index++] = '0';
                }
                else
                {
                    int temp = x;
                    while (temp > 0)
                    {
                        buffer[index++] = '0' + (temp % 10);
                        temp /= 10;
                    }
                }

                // Print the digits in reverse order
                while (index > 0)
                {
                    write(1, &buffer[--index], 1);
                    num_char++;
                }
            }
        }
        conv++;
    }

    va_end(num_args);
    return (num_char);
}
