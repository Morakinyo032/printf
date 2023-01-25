#include "main.h"

/**
 * print_char - Prints a char to stdout
 * @s: Char to be printed
 * Return: number of char printed
 */
int print_char(const char *s)
{
	write(1, s, 1);
	return (1);
}

/**
 * print_string - Prints a char to stdout
 * @s: Char to be printed
 * Return: number of char printed
 */
int print_string(const char *s)
{
	int i;

	if (s == NULL)
		return (0);
	for (i = 0; s[i] != '\0'; i++)
	{
		print_char(&s[i]);
	}
	return (i);
}
