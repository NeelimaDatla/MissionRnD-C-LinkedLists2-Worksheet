/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	struct node *ptr = head;
	struct node *ptr_count = head;
	int count = 0;
	if (head == NULL)
		return -1;
	while (ptr_count){
		count++;
		ptr_count = ptr_count -> next;
	}
	int median = count / 2;
	int i = 0;
	if (count % 2 == 0)
		i = 1;
	int avg = 0;
	int num1, num2 = 0;
	if (count == 2){
		return (ptr->num + ptr->next->num) / 2;
	}
	while (i != median){
		ptr = ptr->next;
		i++;
	}
	if (count % 2 == 0){
		return (ptr->num + ptr->next->num) / 2;
	}
	else if (count % 2 != 0)
		return ptr->num;
	return -1;
}
