#include "main.h"

/**
 * is_format_spec - Check if a char is a format specifier
 * @s: Pointer to the string to check
 * Return: 1 if true or -1 otherwise
 */
int is_format_spec(const char *s)
{
	int i;
	char *spec = "sc%fudxXpobi";

	if (*s == '%')
	{
		for (i = 0; spec[i] != '\0'; i++)
		{
			if (spec[i] == s[1])
				return (1);
		}
	}
	return (-1);
}
