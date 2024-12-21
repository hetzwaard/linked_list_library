/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   llist.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/21 03:20:32 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/12/21 03:21:34 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "llist.h"

Node	*merge_sorted_lists(Node *list1, Node *list2)
{
	if (list1 == NULL)
		return (list2);
	if (list2 == NULL)
		return (list1);
	Node *l1current, *l2current;
	Node *new_head, *newcurrent;
	l1current = list1;
	l2current = list2;
	if (l1current->value <= l2current->value)
	{
		new_head = l1current;
		l1current = l1current->next;
	}
	else
	{
		new_head = l2current;
		l2current = l2current->next;
	}
	newcurrent = new_head;
	while (l1current != NULL && l2current != NULL)
	{
		if (l1current->value <= l2current->value)
		{
			newcurrent->next = l1current;
			newcurrent = l1current;
			l1current = l1current->next;
		}
		else
		{
			newcurrent->next = l2current;
			newcurrent = l2current;
			l2current = l2current->next;
		}
	}
	if (l1current == NULL)
	{
		newcurrent->next = l2current;
	}
	else if (l2current == NULL)
	{
		newcurrent->next = l1current;
	}
	return (new_head);
}

Node	*duplicate_list(Node *node)
{
	Node	*new_node;

	if (node == NULL)
		return (NULL);
	new_node = calloc(sizeof(Node), 1);
	new_node->value = node->value;
	new_node->next = duplicate_list(node->next);
	return (new_node);
}

void	add_lists(Node *list1, Node *list2)
{
	if (list1 == NULL || list2 == NULL)
		return ;
	list1->value = list1->value + list2->value;
	add_lists(list1->next, list2->next);
}

Node	*delete_list(Node *node)
{
	if (node != NULL)
	{
		delete_list(node->next);
		free(node);
	}
	return (NULL);
}

Node	*insert_after(Node *head, int new_value, int after_value)
{
	Node	*new_node;
	Node	*current;

	new_node = calloc(1, sizeof(Node));
	new_node->value = new_value;
	if (head == NULL)
		return (new_node);
	else
	{
		current = head;
		while (current->next != NULL)
		{
			if (current->value == after_value)
			{
				new_node->next = current->next;
				current->next = new_node;
				return (head);
			}
			else
				current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
		return (head);
	}
}

void	delete_duplicates(Node *head)
{
	if (head == NULL)
		return ;
	if (head->next == NULL)
		return ;
	Node *current1, *current2, *duplicate;
	current1 = head;
	while (current1 != NULL && current1->next != NULL)
	{
		current2 = current1;
		while (current2->next != NULL)
		{
			if (current1->value == current2->next->value)
			{
				duplicate = current2->next;
				current2->next = current2->next->next;
				free(duplicate);
			}
			else
				current2 = current2->next;
		}
		current1 = current1->next;
	}
}

void	sort_list(Node *head)
{
	bool	swapped;
	Node	*current;
	Node	*prev;
	int		temp;

	if (head == NULL)
		return ;
	if (head->next == NULL)
		return ;
	swapped = false;
	do
	{
		swapped = false;
		current = head;
		prev = NULL;
		while (current->next != NULL)
		{
			prev = current;
			current = current->next;
			if (current != NULL)
			{
				if (current->value < prev->value)
				{
					temp = prev->value;
					prev->value = current->value;
					current->value = temp;
					swapped = true;
				}
			}
		}
	} while (swapped);
}

Node	*reverse_list(Node *head)
{
	Node	*current;
	Node	*next_node;
	Node	*tmp;

	if (head == NULL)
		return (NULL);
	if (head->next == NULL)
		return (head);
	current = head;
	next_node = head->next;
	current->next = NULL;
	while (next_node != NULL)
	{
		tmp = next_node->next;
		next_node->next = current;
		current = next_node;
		next_node = tmp;
	}
	return (current);
}

Node	*append_list(Node *head1, Node *head2)
{
	Node	*current;

	if (head1 == NULL)
		return (head2);
	current = head1;
	while (current->next != NULL)
		current = current->next;
	current->next = head2;
	return (head1);
}

Node	*efficient_delete_match(Node *head, int delete_value, int *num_deleted)
{
	*num_deleted = 0;
	if (head == NULL)
		return (NULL);
	Node *current, *temp, *new_head;
	current = head;
	while (current->value == delete_value)
	{
		temp = current;
		current = current->next;
		free(temp);
		*num_deleted = *num_deleted + 1;
		if (current == NULL)
			return (NULL);
	}
	new_head = current;
	while (current->next != NULL)
	{
		if (current->next->value == delete_value)
		{
			temp = current->next;
			current->next = current->next->next;
			free(temp);
			*num_deleted = *num_deleted + 1;
		}
		else
			current = current->next;
	}
	return (new_head);
}

Node	*delete_all_matches(Node *head, int delete_value, int *num_deleted)
{
	Node	*current;
	bool	deleted;

	current = head;
	deleted = false;
	*num_deleted = 0;
	do
	{
		current = delete_first_match(current, delete_value, &deleted);
		if (deleted)
			*num_deleted = *num_deleted + 1;
	} while (deleted);
	return (current);
}

Node	*delete_first_match(Node *head, int delete_value, bool *was_deleted)
{
	Node	*temp;
	Node	*current;
	Node	*prev;

	if (head == NULL)
	{
		*was_deleted = false;
		return (NULL);
	}
	if (head->value == delete_value)
	{
		temp = head->next;
		free(head);
		*was_deleted = true;
		return (temp);
	}
	current = head->next;
	prev = head;
	while (current != NULL)
	{
		if (current->value == delete_value)
		{
			prev->next = current->next;
			free(current);
			*was_deleted = true;
			return (head);
		}
		prev = current;
		current = current->next;
	}
	*was_deleted = false;
	return (head);
}

void	replace_matches(Node *node, int find_value, int replace_value)
{
	if (node != NULL)
	{
		if (node->value == find_value)
			node->value = replace_value;
		replace_matches(node->next, find_value, replace_value);
	}
}

int	count_matches(Node *node, int find_value)
{
	if (node == NULL)
		return (0);
	else if (node->value == find_value)
		return (1 + count_matches(node->next, find_value));
	else
		return (count_matches(node->next, find_value));
}

bool	is_member(Node *node, int find_value)
{
	if (node == NULL)
		return (false);
	else if (node->value == find_value)
		return (true);
	else
		return (is_member(node->next, find_value));
}

int	recursive_length(Node *node)
{
	if (node == NULL)
		return (0);
	else
		return (1 + recursive_length(node->next));
}

int	length(Node *head)
{
	Node	*current;
	int		length;

	current = head;
	length = 0;
	while (current != NULL)
	{
		length++;
		current = current->next;
	}
	return (length);
}

Node	*delete_at_tail(Node *head)
{
	Node	*current;
	Node	*prev;

	if (head == NULL)
		return (NULL);
	else if (head->next == NULL)
	{
		free(head);
		return NULL;
	}
	else
	{
		current = head;
		prev = NULL;
		while (current->next != NULL)
		{
			prev = current;
			current = current->next;
		}
		prev->next = NULL;
		free(current);
		return head;
	}
}

Node	*delete_at_head(Node *head)
{
	Node *to_return ;
	if (head == NULL)
		return NULL;
	else
	{
		to_return = head->next;
		free(head);
		return to_return ;
	}
}

Node	*insert_at_tail(Node *head, int new_value)
{
	Node	*new_node;
	Node	*current;

	new_node = calloc(1, sizeof(Node));
	new_node->value = new_value;
	if (head == NULL)
		return new_node;
	else
	{
		current = head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
		return head;
	}
}

Node	*insert_at_head(Node *head, int new_value)
{
	Node	*new_node;

	new_node = calloc(1, sizeof(Node));
	new_node->value = new_value;
	if (head == NULL)
		return new_node;
	else
	{
		new_node->next = head;
		return new_node;
	}
}

void	print_list(Node *head)
{
	Node	*current;
	int		i;

	current = head;
	i = 0;
	while (current != NULL)
	{
		printf("Node %d: %d\n", i, current->value);
		i++;
		current = current->next;
	}
}
