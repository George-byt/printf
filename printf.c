#include "holberton.h"
/**
 * _printf - imitate printf function
 * @format: string
 * Return: 0
 */
int _printf(const char *format, ...)
{
  int length = 0, index;
  va_list args;

  va_start(args, format);

  for (index = 0; format != NULL && format[index] != '\0'; index++)
    {
      if (format[index] == '%')
	switch (format[index + 1])
	  {
	  case 'c':
	    _putchar(va_arg(args, int));
	    index += 2;
	    break;
	  case 's':
	    length += print_str(args);
	    length--;
	    index++;
	    break;                                                                                                                                                       case '%':
	    write(1, "%", 1);
	    index += 2;
	    break;
	  case 'd':
	    length += print_integer(args);
	    index++;
	    break;
	  case 'i':
	    length += print_integer(args);
	    index++;
	    break;
	  default:
	    _putchar(format[index]);
	    index += 2;
	    break;
	  }

      else
	
	  _putchar(format[index]);
	  length++;
       
    }
  return (length);
}
