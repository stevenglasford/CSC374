//print out a singly linked list

void printListy(struct ListNode* head){
	do{
		printf(" %d -> ",head->val);
		head = head->next;
	}while(head != NULL);
	printf("NULL");
}
