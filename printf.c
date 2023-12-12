#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * format_detector - select format
 * @specifier: char subsequent to the format modifier
 * @args: list of variadic args
 * @count: pointer to the counter
 */

void format_specifier(const char specifier, va_list args, int *counter)
{
	switch (specifier)
	{
		case 'c':
			putchar(va_arg(args, int));
			(*counter)++;
			break;
		case 's':
			int pos;
			char *strp;

			pos = 0;
			*strp = va_arg(args, char *);
			while (strp[pos] != '\0')
			{
				putchar(strp);
				(*counter)++;
			}
		case '%':
			putchar('%');
			(*counter)++;
	}
}

/**
 * _printf - function that mimicks printf
 * @format: character string
 *
 * Return: the number of characters
 */

int _printf(const char *format, ...)
{
	int counter;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	counter = 0;

	for (; format != '\0'; format++)
	{
		/* if pointer called format is pointing to a format modifier */
		if (format == '%' && *(format + 1) != '\0')
		{
			format++;
			format_specifier(*format, args, &counter);
		}
		else if (format == '%' && *(format + 1) == '\0')
			return (-1);
		else
		{
			putchar(*format);
			counter++;
		}
	}
	putchar('\n');

	return (counter);
}
