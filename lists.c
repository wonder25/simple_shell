#include "main.h"

/**
 * free_list - frees linked list
 * @header: pointer to head node
 */

void free_list(LL *head)
{
	LL *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp->str);
		free(tmp);
	}
}

/**
 * add_node - adds a new node to list
 * @head_ref: double pointer to head node
 * @str: string stored on new node
 */

void add_node(LL **head_ref, char *str)
{
	LL *new_node = (LL *)malloc(sizeof(LL));

	new_node->str = str;
	new_node->next = *head_ref;
	*head_ref = new_node;
}
