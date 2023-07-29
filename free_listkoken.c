#include "lists.h"

/**
 * free_listtoken - free listtoken_t list
 *
 * Description: free listtoken_t list
 *
 * @head: points to pointer that points to first node
 *
 * Return: void
 */
void free_listtoken(listtoken_t **head)
{
    listtoken_t *node;

    if (head == NULL)
        return;

    do
    {

        node = *head;


        if (node == NULL)
            break;


        *head = node->next;


        free(node->token);
        free(node);


        continue;


    } while (*head != NULL);

	head = NULL;
}

