#include "holberton.h"
/**
 * _printf - imitate printf function
 * @format: string
 * Return: 0
 */
int _printf(const char *format, ...)
{
<<<<<<< HEAD
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
if (!format[index])
return (-1);
switch (format[index + 1])
{
case 'c':
c = va_arg(args, int);
_putchar(c);
index++;
break;
case 's':
length += print_str(args);
length--;
index++;
break;
case '%':
_putchar('%');
index++;
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
_putchar('%');
break;
}
}
else
_putchar(format[index]);
length++;
}
return (length);
=======
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
>>>>>>> main
}
