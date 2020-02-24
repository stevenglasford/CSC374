/*
Question 3

Reverse a singly-linked list
*/

//reverse a singly linked list
struct ListNode* reverseList(struct ListNode* head){
	struct ListNode* backHead;
	//if the list is empty return null
	if (head == NULL){
		return NULL;
	}

	//if there is only a single entrant in the list
	//then return the first thing in the list
	if (head->next == NULL){
		return head;
	}

	//if there are two or more entrants then we can actually
	//reverse the list, use recursion for simplicity sake
	backHead = reverseList(head->next);
	//link to the last node in the reversed list
	head->next->next = head;
	//set the the first entrant at the beginning becomes the
	//last entrant
	head->next = NULL;

	//return the reversed list
	return backHead;
}
