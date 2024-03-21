#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to a pointer to the beginning of a linked list
 * @idx: index of the list where the new node should be added (starting from 0)
 * @n: integer value to be stored in the new node
 *
 * Return: the address of the new node, or NULL if it failed
 * If it is not possible to add the new node at index idx, do not add the new node and return NULL
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    dlistint_t *new_node = malloc(sizeof(dlistint_t));
    dlistint_t *current = *h;

    if (new_node == NULL)
        return NULL;

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (idx == 0)
    {
        if (*h != NULL)
        {
            new_node->next = *h;
            (*h)->prev = new_node;
        }
        *h = new_node;
        return new_node;
    }

    while (idx > 1 && current != NULL)
    {
        current = current->next;
        idx--;
    }

    if (current == NULL)
    {
        free(new_node);
        return NULL;
    }

    new_node->next = current->next;
    new_node->prev = current;
    if (current->next != NULL)
        current->next->prev = new_node;
    current->next = new_node;

    return new_node;
}
