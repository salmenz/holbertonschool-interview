#include <stdlib.h>
#include "holberton.h"
#include <stdio.h>

/**
 * main - The entry point of the program
 *
 * @argc: The number of arguments
 * @argv: Array of pointers to the arguments
 *
 * Return: 98 on failure, 0 on success
 **/
int main(int argc, char *argv[])
{
	char *result, *on1, *on2, *num1, *num2, *reson, *resend;
	uint reslen, len1, len2, carry = 0, temp;
	char cur_res, fresh = 1;

	if (argc != 3)
		fail();

	num1 = argv[1];
	num2 = argv[2];
	len1 = len(num1);
	len2 = len(num2);
	reslen = len1 + len2;
	result = malloc(sizeof(char) * (reslen + 1));
	resend = (result + reslen);
	*resend = '\0';

	for (on2 = num2 + len2 - 1; on2 >= num2; on2--)
	{
		reson = resend + (on2 - num2 - len2 + 1) - 1;
		carry = 0;
		for (on1 = num1 + len1 - 1; on1 >= num1; on1--)
		{
			cur_res = char_mul(*on1, *on2, &carry);
			temp = (cur_res - '0') + (fresh ? 0 : *reson - '0');
			carry += temp / 10;
			*reson = (temp % 10) + '0';
			reson--;
		}
		*reson = (char)(carry + '0');
		fresh = 0;
	}
	_print(reson);
	free(result);
	return (0);
}

/**
 * char_mul - Multiplies two characters and returns the 1's digit as a char
 *
 * @a: The first character
 * @b: The second character
 * @carry: Pointer to the carry number to add to the product
 *
 * Return: Char representation of the 1's digit of the product
 **/
char char_mul(char a, char b, uint *carry)
{
	uint ua, ub, val;

	if (!(a >= '0' && a <= '9') || !(b >= '0' && b <= '9'))
		fail();

	ua = (uint)(a - '0');
	ub = (uint)(b - '0');

	val = (ua * ub) + *carry;
	*carry = val / 10;

	return ((val % 10) + '0');
}

/**
 * len - Gets the length of a string
 *
 * @n: Pointer to the string to get the length of
 *
 * Return: The length of the string as an unsigned int
 **/
uint len(char *n)
{
	uint ret;

	for (ret = 0; *n; n++)
		ret++;

	return (ret);
}

/**
 * _print - Prints a string (excluding leading 0s)
 *
 * @s: Pointer to the first character of the string
 **/
void _print(char *s)
{
	while (*(s + 1) == '0')
		s++;

	if (*s == '0' && *(s + 1) != '\0')
		s++;

	while (*s)
		_putchar(*s++);

	_putchar('\n');
}

/**
 * fail - Prints an error message and exits
 */
void fail(void)
{
	_print("Error");
	exit(98);
}
