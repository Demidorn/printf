#include "main.h"

/**
 * print_char - prints char
 * @args: list a of arguments
 * @buffer: buffer array to handle print
 * @flags: this calculates active flags
 * @width: displays width
 * @precision: give precision specification
 * @size: specifier of size
 * Return: Number of characters printed
 */

int print_char(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	char c = va_arg(args, int);

	return (handle_write_char(c, buffer, width, precision, size, flags));
}

/**
 * print_string - prints a string
 * @args: list a of arguments
 * @buffer: bugger array to handle print
 * @flags: this calculates active flags
 * @width: gets the width
 * @precision: gives precision specification
 * @size: specifier of size
 * Return: Number of printed characters
 */

int print_string(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = 0, d;
	char *str = va_arg(args, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	{
		str = "(null)";

		if (precision >= 6)
			str = "  ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (d = width - length; d > 0; d--)
				write(1, "", 1);

			write(1, &str[0], length);

			return (width);
		}
	}
	return (write(1, str, length));
}

/**
 * print_percent - prints a percent sign
 * @args: list of arguments
 * @buffer: buffer array to handle print
 * @flags: this calculates active flags
 * @width: gets width
 * @precision: precision specification
 * @size: size of specifier
 * Return: Number of printed chars
 */

int print_percent(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(args);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	return (write(1, "%%", 1));
}

/**
 * print_int - prints integer
 * @args: list of arguments
 * @buffer: buffer array to handle print
 * @flags: this calculates active flags
 * @width: gets width
 * @size: size of specifier
 * @precision: precision specification
 * Return: Nmuber of chars printed
 */

int print_int(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	int d = BUFF_SIZE - 2;
	int is_neg = 0;
	long int n = va_arg(args, long int);
	unsigned long int number;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[d--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	number = (unsigned long int)n;

	if (n < 0)
	{
		number = (unsigned long int)((-1) * n);
		is_neg = 1;
	}

	while (number > 0)
	{
		buffer[d--] = (number % 10) + '0';
		number /= 10;
	}
	d++;
	return (write_number(is_neg, d, buffer, flags, width, precision, size));
}

/**
 * print_binary - prints unsigned number
 * @args: list of arguments
 * @buffer: buffer to handle print
 * @flags: this calculates active flags
 * @width: get width
 * @size: size of specifier
 * @precision: precision specification
 * Return: Numbes of printed characters
 */

int print_binary(va_list args, char buffer[],
		int width, int flags, int size, int precision)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(width);
	UNUSED(flags);
	UNUSED(size);
	UNUSED(precision);

	n = va_arg(args, unsigned int);
	m = 2147483648; /* 2^31 */
	a[0] = n / m;

	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];

		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}