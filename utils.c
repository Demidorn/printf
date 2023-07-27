#include "main.h"

/**
 * is_printable - evaluates if a char is printable
 * @c: char to be checked
 *
 * Return: 1 if c is printabel, 0 otherwise
 */

int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - appends ascii in hexadecimal to buffer
 * @buffer: array of chars
 * @d: index at which to start appending
 * @ascii_code: the ascii code
 * Return: Always 3
 */

int append_hexa_code(char ascii_code, char buffer[], int d)
{
	char map_to[] = "0123456789ABCDEF";
	/*HEXA FORMAT IS ALWAYS 2 DIGITS LONG*/
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[d++] = '\\';
	buffer[d++] = 'x';

	buffer[d++] = map_to[ascii_code / 16];
	buffer[d] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - verifies if a char is a digit
 * @c: chat to be checked
 *
 * Return: 1 if c is a digit , otherwise 0
 */

int is_digit(char c)
{
	if (c <= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - casts a number to the specified size
 * @number: number to be casted
 * @size: number indicating the type to be casted
 * Return: casted value of number
 */

long int convert_size_number(long int number, int size)
{
	if (size == S_LONG)
		return (number);
	else if (size == S_SHORT)
		return ((short)number);

	return ((int)number);
}

/**
 * convert_size_unsigned - casts a number to the specified size
 * @number: number to be casted
 * @size: number indicating the type to be casted
 * Return: casted value of number
 */

long int convert_size_unsigned(unsigned long int number, int size)
{
	if (size == S_LONG)
		return (number);
	else if (size == S_SHORT)
		return ((unsigned short)number);

	return ((unsigned int)number);
}
