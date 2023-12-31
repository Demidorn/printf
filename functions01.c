#include "main.h"

/**
 * print_unsigned - Prints an unsigned number
 * @args: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */

int print_unsigned(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);

	num = convert_size_unsigned(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_unsignd(0, i, buffer, flags,
				width, precision, size));
}

/**
 * print_octal - prints an unsigned number in octal notation
 * @args: list of arguments
 * @buffer: array to handle print
 * @flags: claculates active flags
 * @width: ....
 * @precision: ....
 * @size: ....
 * Return: Number of chars printed
 */

int print_octal(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsigned(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)

	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';
	i++;
	return (write_unsignd(0, i, buffer, flags, width, precision, size));
}


/**
 * print_hexadecimal - prints an unsigned number in hexadecimal notation
 * @args: list of arguments
 * @buffer: array to handle print
 * @flags:this calculates active flags
 * @width: ....
 * @precision: ...
 * @size: ...
 * Return: Number of chars printed
 */

int print_hexadecimal(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(args, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));

}

/**
 * print_hexa - prints a hexadecimal number in lower or upper
 * @args: lists of arguments
 * @map_to: array of values to map number to
 * @buffer: .....
 * @flags: ...
 * @flag_ch: ...
 * @width: ...
 * @size: ....
 * @precision: ...
 * Return: Numbers of chars printed
 */

int print_hexa(va_list args, char map_to[],
		char buffer[], int flags, char flag_ch, int width,
		int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);
	num = convert_size_unsigned(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;
	return (write_unsignd(0, i, buffer, flags,
				width, precision, size));
}

/**
 * print_hexa_upper - prints an unsigned number in upper hexadecimal
 * @args: list of arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: gets width
 * @precision: specification of precision
 * @size: size of specifier
 * Return: Number of printed chars
 */

int print_hexa_upper(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(args, "0123456789ABCEDF", buffer,
				flags, 'X', width, precision, size));
}
