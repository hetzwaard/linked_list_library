#include "llist.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int	main(void)
{
	Node *list1, *list2, *list3, *list4, *list5, *list6;
	list1 = list2 = list3 = list4 = list5 = list6 = NULL;
	for (int i = 1; i <= 5; i++)
		list1 = insert_at_head(list1, i);
	for (int i = 8; i >= 4; i--)
		list2 = insert_at_head(list2, i);
	printf("List 1:\n");
	print_list(list1);
	printf("List 2:\n");
	print_list(list2);
	add_lists(list1, list2);
	printf("List 1 after add:\n");
	print_list(list1);

	for (int i = 1; i <= 2; i++)
		list3 = insert_at_head(list3, i);
	for (int i = 4; i <= 7; i++)
		list4 = insert_at_head(list4, i);
	printf("List 3:\n");
	print_list(list3);
	printf("List 4:\n");
	print_list(list4);
	add_lists(list3, list4);
	printf("List 3 after add:\n");
	print_list(list3);

	for (int i = 4; i <= 7; i++)
		list5 = insert_at_head(list5, i);
	for (int i = 1; i <= 2; i++)
		list6 = insert_at_head(list6, i);
	printf("List 5:\n");
	print_list(list5);
	printf("List 6:\n");
	print_list(list6);
	add_lists(list5, list6);
	printf("List 5 after add:\n");
	print_list(list5);

	Node *list7 = NULL;
	for (int i = 0; i < 10; i++)
		list7 = insert_at_head(list7, i);
	printf("List 7:\n");
	print_list(list7);
	Node *list7_duplicate = duplicate_list(list7);
	printf("List 7 duplicate list: \n");
	print_list(list7_duplicate);

	srand(time(NULL));
	Node *list11 = NULL;
	Node *list12 = NULL;
	for (int i = 0; i < 10; i++)
		list11 = insert_at_head(list11, rand() % 99);
	for (int i = 0; i < 10; i++)
		list12 = insert_at_head(list12, rand() % 99);
	sort_list(list11);
	sort_list(list12);
	printf("List 11:\n");
	print_list(list11);
	printf("List 12:\n");
	print_list(list12);
	Node *newhead = merge_sorted_lists(list11, list12);
	printf("Merged list:\n");
	print_list(newhead);
}