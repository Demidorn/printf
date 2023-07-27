#include "main.h"
#include <stdio.h>
#include <limits.h>

/**
 * main - entry point
 *
 *
 * Return: Always 0
 */

int main(void)
{
	int n = _printf("%u", 3.35);

	printf("\nn = %d\n", n);

	return (0);
}
