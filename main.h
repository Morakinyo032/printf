#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

struct func_t
{
	char c;
	int (*f)(const char *str);
};
typedef struct func_t func_t;

typedef struct formats
{
	char c;
	unsigned int base;
}
formats;

int _strlen(char *s);
char *int_str(long long int n);
char *uint_str(long long unsigned int n);
char *convert(long long unsigned int n, unsigned int base);
char *c_xtoupper(long long unsigned int n);
int (*get_func(char chr))(const char *s);
int print_string(const char *s);
int print_char(const char *s);
int print_int(const char *s);
int print_decimal(const char *s);
int _printf(const char *format, ...);
int is_format_spec(const char *s);

#endif
