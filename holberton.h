#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
void printescape(char a);
int print_str(va_list arg);
int print_num(int n, int c);
int print_integer(va_list arg);
int funct_format(va_list args, const char *format);
int _putchar(char c);
int noformat(char index);

#endif /*HOLBERTON_H*/
