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
	listint_t *cur, *deb, *fin;
	int d = 0, f, i, j, len = 0, r = 1;

	if (head == NULL)
		return (r);
	cur = *head;
	while (cur)
	{
		len++;
		cur = cur->next;
	}
	f = len - 1;
	while (f > d && r == 1)
	{
		deb = *head;
		fin = *head;
		i = 0;
		j = 0;
		while (i < f)
		{
			fin = fin->next;
			i++;
		}
		while (j < d)
		{
			deb = deb->next;
			j++;
		}
		if (deb->n != fin->n)
			r = 0;
		d++;
		f--;
	}
	return (r);
}
