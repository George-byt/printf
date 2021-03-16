#include "holberton.h"
/**
 * print_num - recursive function to print a number.
 * @n: number to print.
 * @c: length of the number.
 * Return: Counter.
 */
int print_num(int n, int c)
{
if (n / 10)
c = print_num(n / 10, c);
_putchar(n % 10 + '0');
return (c + 1);
}
