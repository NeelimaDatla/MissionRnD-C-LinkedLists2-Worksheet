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
	int node_count = 0;
	if (head == NULL)
		return NULL;
	if (K <= 0)
		return NULL;
	while (ptr != NULL){
		node_count++;
		if (node_count == K){
			struct node *cur = (struct node *)malloc(sizeof(node));
			cur->num = K;
			cur->next = ptr->next;
			ptr->next = cur;
			node_count = 0;
			ptr = ptr->next;
		}
		ptr = ptr->next;
	}
	return ptr2;
}
