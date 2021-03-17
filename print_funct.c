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
	unsigned int unumber;

	number = va_arg(arg, int);
	if (number < 0)
	{
		unumber = number * -1;
		_putchar('-');
		if (number == -2147483648)
		{
			count += 1;
			count += print_num(unumber / 10, count);
			_putchar('8');
		}
		else
		{
			count += print_num(unumber, count);
			count += 1;
		}
	}
	else
	{
		unumber = number;
		count = print_num(unumber, count);
	}
	return (count);
}
/**
 * print_str - function that print a string
 * @arg: list that contains the format inserted
 *Return: tot
 */
int print_str(va_list arg)
{
	char *str;
	int i;

	str = va_arg(arg, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	return (i);
}
/**
 * noformat - handle cases where % doesn't match anything
 * @index: character ahead of %
 * Return: always -1
 */
int noformat(char index)
{
	if (index == '\0')
		return (-1);
	_putchar('%');
	return (-1);
}
