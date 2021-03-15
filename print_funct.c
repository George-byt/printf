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
/**
 * print_integer -Function that print a integer.
 * @arg: List that contains the format inserted.
 * Return: Counter of the integers printed.
 */
int print_integer(va_list arg)
{
int number;
int count = 0;
number = va_arg(arg, int);
count = print_num(number, count);
return (count);
}
