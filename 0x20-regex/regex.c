#include "regex.h"
/**
 * regex_match - check whether a given pattern matches a given string
 * @str: string
 * @pattern: regular expression
 * Return: 1 if pattern matches str and 0 otherwise
 */

int regex_match(char const *str, char const *pattern)
{
	int point = 0;
	int etoile = 0;

	if (!str || !pattern)
		return (0);

	point = *str && (*str == *pattern || *pattern == '.');
	etoile = *(pattern + 1) == '*';

	if (!*str && !etoile)
		return (*pattern ? 0 : 1);
	else if (point && etoile)
		return (regex_match(str + 1, pattern) || regex_match(str, pattern + 2));
	else if (point && !etoile)
		return (regex_match(str + 1, pattern + 1));
	else if (etoile)
		return (regex_match(str, pattern + 2));
	return (0);
}
