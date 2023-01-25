#include "main.h"

/**
 * convert - Convert unsigned int to another base
 * @n: Number to be converted
 * @base: base
 * Return: Pointer to string of 1 and 0
 */
char *convert(unsigned long long int n, unsigned int base)
{
	int i, j, len;
	char *buf;
	char s[24];

	j = 0;
	i = 0;
	s[i] = (n % base) + '0';
	if (s[i] > '9')
		s[i] = 'a' - 1 + (s[i] - '9');
	i++;
	n /= base;
	while (n > 0)
	{
		s[i] = (n % base) + '0';
		if (s[i] > '9')
			s[i] = 'a' - 1 + (s[i] - '9');
		n /= base;
		i++;
	}
	s[i] = '\0';
	len = _strlen(s);
	buf = malloc(len + 1);
	if (buf == NULL)
		return (NULL);
	for (i = len - 1; i >= 0; i--)
	{
		buf[j] = s[i];
		j++;
	}
	buf[j] = '\0';
	return (buf);
}

/**
 * c_xtoupper - Covert hex to upper_case hex
 * @n: Number to be converted
 * Return: Converted string
 */

char *c_xtoupper(unsigned long long int n)
{
	char *buf, *s;
	int i, len;

	buf = (char *)convert(n, 16);
	len = _strlen(buf);
	s = malloc(len + 1);
	for (i = 0; buf[i] != '\0'; i++)
	{
		if (buf[i] >= 'a' && buf[i] <= 'f')
			s[i] = buf[i] - 32;
		else
			s[i] = buf[i];
	}
	s[i] = '\0';
	free(buf);
	return (s);
}
