#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * insert_node - insert node
 * @head: head of the list
 * @number: the nuber to insert
*/
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *aux;
	listint_t *current;
	current = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	if (*head == NULL)
        *head = new;
    else
    {
        while (current->next != NULL && current->next->n < number)
            current = current->next;
	aux = current->next;
        current->next = new;
	new->next = aux;
    }

    return (new);
}
