#include "lists.h"

/**
 * find_listint_loop - Function that finds the loop in a linked list.
 * @head: pointer to the head of the list
 * Return: The address of the node where the loop starts, otherwise NULL
*/

listint_t *find_listint_loop(listint_t *head)
{
listint_t *s, *f;

if (!head)
return (NULL);

f = head;
s = head;
while (s && f && f->next)
{
if (s->next)
s = s->next;
if (f->next && f->next->next)
f = f->next->next;
else
return (NULL);
if (s == f)
{
s = head;
while (s && f && f->next)
{
if (s == f)
return (s);
s = s->next;
f = f->next;
}
}
}
return (NULL);
}
