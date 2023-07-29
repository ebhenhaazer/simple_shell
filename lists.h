#ifndef LISTS_H_
#define LISTS_H_

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct listtoken_s - singly linked list
 * @token: its a pointer
 * @token_length: its an integer
 * @next: next node to be pointed
 *
 * Description: singly linked list
 *
 */
typedef struct listtoken_s
{
	char *token;
	int token_length;
	struct listtoken_s *next;
} listtoken_t;

void free_listtoken(listtoken_t **head);
size_t print_listtoken(const listtoken_t *head);
listtoken_t *add_nodetoken_end(listtoken_t **head, char *token);
size_t listtoken_len(const listtoken_t *head);

#endif
