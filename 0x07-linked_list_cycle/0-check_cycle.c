
#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - check if there is a loop in the list.
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle.
 */
int check_cycle(listint_t *list)
{
	listint_t *fast = list, *slow = list;

	if (list == NULL)
		return 0;
	fast = list->next;
	while (fast != NULL && slow != NULL && fast->next != NULL)
	{
		if (fast == slow)
			return 1;
		fast = fast->next->next;
		slow = slow->next;
	}
	return 0;
}
