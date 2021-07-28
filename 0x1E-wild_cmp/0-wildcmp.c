#include "holberton.h"

/**
 * len - lenght function
 * @s: string
 * Return: lenght of the string
 **/

int len(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}
	s++;
	return (len(s) + 1);
}

/**
 * compare - Function that helps to compare strings
 * @str1: string 1
 * @str2: string 2
 * @i: couter str1
 * @j: couter str2
 * @wc: wildcard
 * @lwc: last wildcard
 * @l: length of str1
 * Return: 1 if identical otherwise 0.
 **/

int compare(char *str1, char *str2, int i, int j, int wc, int lwc, int l)
{
	if (str2[j] == '\0' && (str2[j - 1] == '*' || str2[j - 1] == str1[l - 1]))
		return (1);
	if (str2[j] == '*')
	{
		lwc = ++j;
		wc = 1;
		return (compare(str1, str2, i, j, wc, lwc, l));
	}
	if (str2[j] == str1[i])
	{
		i++;
		j++;
		wc = 0;
		return (compare(str1, str2, i, j, wc, lwc, l));
	}
	if (str1[i] != str2[j] && wc == 1)
	{
		if (str1[i] == '\0')
			return (0);
		i++;
		return (compare(str1, str2, i, j, wc, lwc, l));
	}
	if (str1[i] == '\0')
		return (0);
	if (str1[i] != str2[j] && wc == 0)
	{
		j = lwc;
		wc = 1;
		if (lwc == 0)
			return (0);
		return (compare(str1, str2, i, j, wc, lwc, l));
	}
	return (0);
}

/**
 * wildcmp - compare two strings and can be considered identical.
 * @str1: string 1
 * @str2: string 2
 * Return: 1 if identical otherwise 0.
 */

int wildcmp(char *str1, char *str2)
{
	int i = 0, j = 0, wc = 1, lwc = 0;

	return (compare(str1, str2, i, j, wc, lwc, len(str1)));
}
