#include "holberton.h"
/**
 * _printf - imitate printf function
 * @format: string
 * Return: 0
 */
int _printf(const char *format, ...)
{
	int length;
	va_list args;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	length = funct_format(args, format);
	va_end(args);
	return (length);
}

/**
 * funct_format - Function that compares
 * the format given with a buch of cases to print.
 * @args: List of parameters to print.
 * @format: input given.
 * Return: Amount of printed bytes.
 */
int funct_format(va_list args, const char *format)
{
	int length = 0, index;
	char c;

	for (index = 0; format[index]; index++)
	{
		if (format[index] == '%')
		{
			switch (format[index + 1])
			{
			case 'c':
				c = va_arg(args, int);
				_putchar(c);
				break;
			case 's':
				length += (print_str(args) - 1);
				break;
			case '%':
				_putchar('%');
				break;
			case 'd':
				length += print_integer(args);
				break;
			case 'i':
				length += print_integer(args);
				break;
			default:
				index += noformat(format[index + 1]);
				break;
			}
			index++;
		}
		else
			_putchar(format[index]);
		length++;
	}
	return (length);
}
