/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   llist.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/21 03:20:48 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/12/21 03:20:50 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int			value;
	struct node	*next;
}				Node;

void			print_list(Node *head);
Node			*insert_at_head(Node *head, int new_value);
Node			*insert_at_tail(Node *head, int new_value);
Node			*delete_at_head(Node *head);
Node			*delete_at_tail(Node *head);
int				length(Node *head);
int				recursive_length(Node *node);
bool			is_member(Node *node, int find_value);
int				count_matches(Node *node, int find_value);
void			replace_matches(Node *node, int find_value, int replace_value);
Node			*delete_first_match(Node *head, int delete_value,
					bool *was_deleted);
Node			*delete_all_matches(Node *head, int delete_value,
					int *num_deleted);
Node			*efficient_delete_match(Node *head, int delete_value,
					int *num_deleted);
Node			*append_list(Node *head1, Node *head2);
Node			*reverse_list(Node *head);
void			sort_list(Node *head);
void			delete_duplicates(Node *head);
Node			*insert_after(Node *head, int new_value, int after_value);
Node			*delete_list(Node *node);
void			add_lists(Node *list1, Node *list2);
Node			*duplicate_list(Node *node);
Node			*merge_sorted_lists(Node *list1, Node *list2);