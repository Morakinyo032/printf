#include "main.h"

/**
 * _strlen - Find the length of string
 * @s: Pointer to the string
 * Return: Length of the string
 */
int _strlen(char *s)
{
	int i;

	if (s == NULL)
		return (0);
	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}
/**
 * int_str - Converts an in to string
 * @n: integer to be converted
 * Return: Pointer to the string
 */
char *int_str(long long int n)
{
	int i, j, len, sign;
	char *buf;
	char s[24];

	j = 0;
	i = 0;
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		n *= -1;
	}
	s[i] = (n % 10) + '0';
	i++;
	n /= 10;
	while (n > 0)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	s[i] = '\0';
	len = _strlen(s);
	if (sign == 1)
	{
		buf = malloc(len + 1);
		if (buf == NULL)
			return (NULL);

		for (i = len - 1; i >= 0; i--)
		{
			buf[j] = s[i];
			j++;
		}
		buf[j] = '\0';
	}
	else
	{
		buf = malloc(len + 2);
		if (buf == NULL)
			return (NULL);
		buf[j] = '-';
		j++;
		for (i = len - 1; i >= 0; i--)
		{
			buf[j] = s[i];
			j++;
		}
		buf[j] = '\0';
	}
	return (buf);
}

/**
 * uint_str - Convert an unsigned int to str
 * @n: Number to be converted
 * Return: Pointer to the string
 */
char *uint_str(unsigned long long int n)
{
	long long int num;

	num = n;
	return (int_str(num));
}
