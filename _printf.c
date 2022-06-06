#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string containing the character and the specifiers
 * Description: this function will call the get_print() functions
 * that will determine which printing function to call depending on the
 * conversion specifiers
 *
 * Return: length of the formatted output string
 */
int _printf(const char *format, ...)
{
	int (*pfunc)(va_list, flags_t *);
	const char *s;
	va_list argument;
	flags_t flag = {0, 0, 0};

	register int counter = 0;

	va_start(argument, format);
	if (!format || (format[0] == '%' && !format[1]))
	{
		return (-1);
	}
	if (!format || (format[1] == ' ' && !format[2]))
		return (-1);

	for (s = format; *s; s++)
	{
		if (*s == '%')
		{
			s++;
			if (*s == '%')
			{
				counter += _putchar('%');
				continue;
			}
			while (get_flag(*s, &flag))
				s++;
			pfunc = get_print(*s);
			counter += (pfunc)
				? pfunc(argument, &flag)
				:_printf("%%%c", *s);
		}
		else
		{
			counter =+ _putchar(*s);
		}
	}
	_putchar(-1);
	va_end(argument);
	return (counter);
}
