/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	struct node *l1 = head1;
	struct node *l2 = head2;
	struct node *head;
	struct node *ptr4;
	if (head1 == NULL && head2 == NULL)
		return NULL;
	else{
		if (head1 == NULL)
			return head2;
		if (head2 == NULL)
			return head1;
	}
	if (l1->num < l2->num) {
		head = l1;
	}
	else {
		head = l2;
		l2 = l1;
		l1 = head;
	}
	while (l1->next != NULL && l2 != NULL) {
		if (l1->next->num <= l2->num) {
			l1 = l1->next;
		}
		else {
			ptr4 = l1->next;
			l1->next = l2;
			l2 = ptr4;
		}
	}
	if (l1->next == NULL)
		l1->next = l2;
	return head;
}
