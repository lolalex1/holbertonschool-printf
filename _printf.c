#include <stdarg.h>
#include <unistd.h>


/**
 * _putchar - write the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _printf - prints put the parameters just like printf
 * @format: The type of data the function needs to account for to print
 * Return: The length of the output
 */
int _printf(const char *format, ...)
{
	int count = 0;
	char c = ' ', *s = " ";
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				c = va_arg(args, int);
				count += _putchar(c);
			}
			else if (*format == 's')
			{
				s = va_arg(args, char *);
				while (*s)
				{
					count += _putchar(*s);
					s++;
				}
			}
			else if (*format == '%')
			{
				count += _putchar('%');
			}
			else
			{
				count += _putchar('%');
				count += _putchar(*format);
			}
		}
		else
		{
			count += _putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}
