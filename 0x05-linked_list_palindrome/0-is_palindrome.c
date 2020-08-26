#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * is_palindrome - check if the list is palindrome or not
 * @head: the head of the list
 * Return: 1 of palindrome and 0 otherways
 */
int is_palindrome(listint_t **head)
{
	int d = 0, f = -1, r = 1, tab[2069];

	while (*head)
	{
		f++;
		tab[f] = (*head)->n;
		*head = (*head)->next;
	}
	while (--f > ++d && r == 1)
		if (tab[d] != tab[f])
			r = 0;
	return (r);
}
