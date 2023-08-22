#include <stdarg.h>
#include "main.h"
#include <unistd.h>

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
				write(STDOUT_FILENO, s, strlen(s));
				bytes += strlen(s);
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

	return bytes;
}