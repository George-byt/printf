#include "holberton.h"
#include <unistd.h>

/**
 * _printf - imitate printf function
 * @format: string
 * Return: 0
 */
int _printf(const char *format, ...)
{
	int length = 0, index;
	char *string;
	va_list args;

	va_start(args, format);
	for (index = 0; format != NULL && format[index] != '\0'; index++)
	{
		while (format[index] != '%' || format[index] != '\\')
		{
			_putchar(format[index]);
			index++;
		}

		if (format[index] == '%')
			switch (format[index + 1])
			{
			case 'c':
				_putchar(va_arg(args, int));
				index += 2;
				break;
			case 's':
				string = va_arg(args, char *);
				for (; string[length] != '\0'; length++)
					;
				write(1, string, length);
				index += 2;
				break;
			case '%':
				write(1, "%", 1);
				index += 2;
				break;
			default:
				_putchar(format[index]);
				index += 2;
				break;
			}
		if (format[index] == '\\')
		{
			printescape(format[index + 1]);
			index += 2;
		}
	}
	return (0);
}
/**
 * printescape - print escape characters
 * @a: escape character
 */
void printescape(char esc)
{
	switch (esc)
	{
	case 'a':
		write (1, "\a", 2);
		break;
	case 'b':
		write (1, "\b", 2);
		break;
	case 'f':
		write (1, "\f", 2);
		break;
	case 'n':
		write (1, "\n", 2);
		break;
	case 'r':
		write (1, "\r", 2);
		break;
	case 't':
		write (1, "\t", 2);
		break;
	case 'v':
		write (1, "\v", 2);
		break;
	default:
		write (1, "\\", 1);
		_putchar(esc);
		break;
	}
}
