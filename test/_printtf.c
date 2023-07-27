#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - produces output according to a format
 * @format: ...
 *
 * Return: Always 0 (success)
 */

int _printf(const char *format, ...)
{
	int count = 0, d;
	va_list args;

	va_start(args, format);

	for (d = 0; format[d] != '\0';)
	{
	/* count the characters and print out*/
		if (format[d] != '%')
		{
			count += _puchar(formart[d]);
			d++;
		}
		else if (format[d] == '%' && format[d + 1] != '')
		{
			switch (format[d + 1])
			{
				case 'c'
				/*print character c from the arguments*/
					count += _putchar(va_arg(args, int));
				break;
				case 's'
				/*print character s as string specifier from the arguments*/
					count += _putchar(va_arg(args, int));
				break;
				case '%'
				/*prints character symbol from the arguments*/
					count += _putchar('%');
			}
			d += 2;
		}
	}
	return (count);
}
