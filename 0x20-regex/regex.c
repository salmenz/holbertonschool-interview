#include "regex.h"
/**
 * regex_match - check whether a given pattern matches a given string
 * @str: string
 * @pattern: regular expression
 * Return: 1 if pattern matches str and 0 otherwise
 */

int regex_match(char const *str, char const *pattern)
{
	int i = 0;

	if (*str == '\0' && *pattern == '\0')
		return (1);
	if ((*str == *pattern || *pattern == '.') && *(pattern + 1) != '*')
		return (regex_match(str + 1, pattern + 1));
	if (*(pattern + 1) == '*')
	{
		if (*str != '\0' && (*str == *pattern || *pattern == '.'))
			i = regex_match(str + 1, pattern);
		return (regex_match(str, pattern + 2) || i);
	}
}
