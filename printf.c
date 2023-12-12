#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * format_specifier - select format
 * @specifier: char subsequent to the format modifier
 * @args: list of variadic args
 * @counter: pointer to the counter
 */

void format_specifier(const char specifier, va_list args, int *counter)
{
	char *strpos;
	int number;
	int reverse;

	switch (specifier)
	{

		case 'c':
			putchar(va_arg(args, int));
			(*counter)++;
			break;
		case 's':
			strpos = va_arg(args, char *);

			if (strpos == NULL)
				*counter += printf("(null)");
			else
			{
				while (*strpos != '\0')
				{
					putchar(*strpos);
					strpos++;
					(*counter)++;
				}
			}
			break;
		case 'd':
			reverse = 0;
			number = va_arg(args, int);

			if (strpos < 0)
				putchar('-');
				number = -number;

			while (number > 9)
			{
				reverse = reverse * 10 + number % 10;
				number = number / 10;
			}
			putchar(number + '0');
			while (reverse)
			{
				putchar(reverse % 10 + '0');
				reverse = reverse / 10;
			}

			break;
		case 'i':	
			reverse = 0;
			number = va_arg(args, int);

			if (strpos < 0)
				putchar('-');
				number = -number;

			while (number > 9)
			{
				reverse = reverse * 10 + number % 10;
				number = number / 10;
			}
			putchar(number + '0');
			while (reverse)
			{
				putchar(reverse % 10 + '0');
				reverse = reverse / 10;
			}
			break;
		case '%':
			putchar('%');
			(*counter)++;
			break;
		default:
			putchar('%');
			putchar(specifier);
			(*counter) += 2;
			break;
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

	for (; *format != '\0'; format++)
	{
		/* if pointer called format is pointing to a format modifier */
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++;
			format_specifier(*format, args, &counter);
		}
		else if (*format == '%' && *(format + 1) == '\0')
			return (-1);
		else
		{
			putchar(*format);
			counter++;
		}
	}

	va_end(args);
	return (counter);
}
