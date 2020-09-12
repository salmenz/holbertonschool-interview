#include <stdio.h>
#include <stdlib.h>
#include "palindrome.h"

/**
 * is_palindrome - check if n is palindrome or not.
 * @n: long int
 * Return: 1 if n is a palindrome, and 0 otherwise.
 */
int is_palindrome(unsigned long n)
{
	char c[100];
	int i, j = 0, b = 1;

	sprintf(c, "%lu", n);
	for (i = 0; c[i]; i++)
	;
	i--;
	while (i > j && b == 1)
	{
		if (c[i] != c[j])
			b = 0;
		i--;
		j++;
	}
	return (b);
}
