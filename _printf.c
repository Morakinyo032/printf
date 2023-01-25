#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: Pointer to a character string
 * Return: Number of char strings printed
 */
int _printf(const char *format, ...)
{
	int (*f)(const char *);
	int i, num, j;
	char c, *tmp;
	va_list args;
	formats f_list[] = { {'b', 2}, {'x', 16}, {'o', 8}, {'u', 10}, {'\0', 0} };

	num = 0;
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (is_format_spec(&format[i]) != 1)
		{
			print_char(&format[i]);
			num++;
		}
		else
		{
			if (format[i + 1] == '%')
			{
				num += print_char(&format[i]);
				i += 1;
				continue;
			}
			f = get_func(format[i + 1]);
			if (format[i + 1] == 's')
				num += f(va_arg(args, char *));
			else if (format[i + 1] == 'c')
			{
				c = va_arg(args, int);
				num += f(&c);
			}
			else if (format[i + 1] == 'i' || format[i + 1] == 'd')
			{
				tmp = int_str(va_arg(args, int));
				num += f((const char *)tmp);
				free(tmp);
			}
			else if (format[i + 1] == 'p')
			{
				num += _printf("0x%x", va_arg(args, long long unsigned int));
			}
			else if (format[i + 1] == 'X')
			{
				tmp = c_xtoupper(va_arg(args, long long unsigned int));
				num += f((const char *)tmp);
				free(tmp);
			}
			else
			{
				for (j = 0; f_list[j].c != '\0'; j++)
				{
					if (format[i + 1] == f_list[j].c)
					{
						tmp = convert(va_arg(args, long long unsigned
									int), f_list[j].base);
						num += f((const char *)tmp);
						free(tmp);
					}
				}
			}
			i += 1;
		}
	}
	return (num);
}
