#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - deletes the node at index of a dlistint_t linked list
 * @head: pointer to a pointer to the beginning of a linked list
 * @index: index of the node that should be deleted (starting from 0)
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    if (*head == NULL)
        return -1;

    dlistint_t *current = *head;

    if (index == 0)
    {
        *head = (*head)->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(current);
        return 1;
    }

    unsigned int i;
    for (i = 0; i < index; i++)
    {
        if (current == NULL)
            return -1;
        current = current->next;
    }

    if (current == NULL)
        return -1;

    if (current->next != NULL)
        current->next->prev = current->prev;

    if (current->prev != NULL)
        current->prev->next = current->next;

    free(current);
    return 1;
}

