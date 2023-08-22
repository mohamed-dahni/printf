#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - function that produces output according to a format
 * @format: character string
 * @...: arguments
 * Return: Always success
 */

int _printf(char *format, ...)
{
	int bytes = 0;
	char c;
	char *s;

	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'c')
			{
				c = va_arg(args, int);
				write(STDOUT_FILENO, &c, sizeof(char));
				bytes += sizeof(char);
			} else if (*format == 's')
			{
				s = va_arg(args, char*);
				write(STDOUT_FILENO, s, _strlen(s));
				bytes += _strlen(s);
			} else if (*format == '%')
			{
				c = *format;
				write(STDOUT_FILENO, &c, sizeof(char));
				bytes += sizeof(char);
			}
		} else
		{
			c = *format;
			write(STDOUT_FILENO, &c, sizeof(char));
			bytes += sizeof(char);
		}

		format++;
	}

	va_end(args);

	return (bytes);
}
