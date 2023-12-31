#include "main.h"
/**
 * print_HEXA - Print hexadecimal upper
 * @vlist: arguments passed to print
 * @output_p: Host output
 * @o_p: output position
 *
 * Description: Fuction that print hexa
 * Return: the int
 */
int print_HEXA(va_list vlist, char *output_p, int o_p)
{
	unsigned int decimal, result;
	int x, y = 0;
	char hexa[100];

	decimal = va_arg(vlist, unsigned int);
	if (decimal == 0)
		hexa[y++] = 48;
	while (decimal)
	{
		result = decimal % 16;
		if (result < 10)
			hexa[y++] = 48 + result;
		else
			hexa[y++] = 55 + result;
		decimal = decimal / 16;
	}
	for (x = y; x > 0; x--, o_p++)
		output_p[o_p] = hexa[x - 1];
	return (o_p);
}
