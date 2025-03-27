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

int print_number(int n)
{
		int count = 0;
		unsigned int num = 0;

		if (n < 0)
		{
			count += _putchar('-');
			num = -n;
		}
		else
		{
			num = n;
		}

		if (num / 10)
		{
			count += print_number(num / 10);
		}
		count += _putchar(num % 10 + '0');
		return (count);
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
			if (*format == '\0')
				return (-1);
			if (*format == 'c')
			{
				c = va_arg(args, int);
				count += _putchar(c);
			}
			else if (*format == 's')
			{
				s = va_arg(args, char *);
				if (s == NULL)
					s = "(null)";
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
			else if (*format == 'i' || *format == 'd')
			{
				count += print_number(va_arg(args, int));
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
