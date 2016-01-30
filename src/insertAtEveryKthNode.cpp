/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	struct node *ptr = head;
	struct node *ptr2 = head;
	int count = 0;
	if (head == NULL)
		return NULL;
	if (K <= 0)
		return NULL;
	struct node *cur = (struct node *)malloc(sizeof(node));
	while (head){
		count++;
		if (count == K){
			cur->num = head->num;
			head->next = cur;
			cur->next = head->next->next;
		}
		head = head->next;
	}
	if (K > count)
		return ptr;
	return ptr2;
}
