#include "main.h"

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
			putchar(*conv);
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
				putchar(*conv);
				num_char++;
			}
			else if (*conv == 'c')
			{
				char c = va_arg(num_args, int);
				putchar(c);
				num_char++;
			}
			else if (*conv == 's')
			{
				char *str = va_arg(num_args, char*);
				int strlen = 0;
				while (str[strlen] != '\0')
				{
					strlen++;
				}
				write(1, str, strlen);
				num_char += strlen;
			}
		}
		conv++;
	}
	va_end(num_args);

	return num_char;
}

