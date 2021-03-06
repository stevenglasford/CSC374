/////////Steven Glasford
/////////Organization and Architecture CSC374
/////////Assignment 1
/////////Due 2-26-2020

#include <stdio.h>
#include <stdlib.h>

/*
Question 1

Given an arry A of non-negative integers, return an array
consisting of all the seven elements of A, followed by all the
odd elements of A. You may return any answer array that
satisfies this condition.
*/

int* sortArrayByParity(int* A, int ASize, int* returnSize){
	int i = 0;
	int j = 0;
	int *B = malloc(ASize*sizeof(int));

	//print out the input
	printf("Input: [ ");
	for (i = 0; i < ASize; i++){
		printf("%d ",A[i]);
	}
	printf("]\n");

	//find all of the even numbers
	for (i = 0; i < ASize; i++){
		if ((A[i] % 2) == 0){
			B[j] = A[i];
			j++;
		}
	}
	//find all of the odd numbers
	for (i = 0; i < ASize; i++){
		if ((A[i] % 2) != 0){
			B[j] = A[i];
			j++;
		}
	}

	//print out the output in a nice to see method
	printf("Output: [ ");
	for (i = 0; i < ASize; i++){
		printf("%d ", B[i]);
	}
	printf("]\n");

	//save the size of the array
	returnSize = &j;
	//return the size of the new array, this can be used as
	//a checksum to make sure the first array is the same
	//size as the first one.
	return B;
}

/*
Question 2

Balanced strings are those who have equal quanity of 'L' and
'R' characters. Given a balanced string s split it in the
maximum amount of balanced strings. Return the maximum amount
of splitted balanced strings
*/
int balancedStringSplit(char * s){
	int balance = 0;
	int i = 0;
	int count = 0;
	while (s[i] != '\0'){
		//find an L and increase the count
		if (s[i] == 'L'){
			count++;
		//reduce the count if finds an R
		} else {
			count--;
		}
		//there should be an balance of L and R and
		//increase the count of balanced strings
		if (count == 0){
			balance++;
		}
		//go to the next character
		i++;
	}

	i = 0;
	//output the cstring so there is no need for a loop
	//in the main body
	while (s[i] != '\0'){
		printf(" %c ", s[i]);
		i++;
	}
	//return the number of balanced strings
	return balance;
}

/*
Question 3

Reverse a singly-linked list
*/
struct ListNode {
	int val;
	struct ListNode *next;
};

//print out a singly linked list
void printListy(struct ListNode* head){
	do{
		printf(" %d -> ",head->val);
		head = head->next;
	}while(head != NULL);
	printf("NULL");
}

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

int main(){
	int ASIZE = 10;
	//a test array with 10 entrants
	int returnSize = 0;
	//make a test array
	int A[] = {1,2,3,4,5,6,7,8,9,0};
	//make a second array
	int *B;
	int temp = 0;
	int i = 0;
	//the reverse list for question 3
	struct ListNode* revHead;
	//test "balanced strings"
	char S1[] = {'R','L','R','R','L','L','R','L','R','L','\0'};
	char S2[] = {'R','L','L','L','L','R','R','R','L','R','\0'};
	char S3[] = {'L','L','L','L','R','R','R','R','\0'};
	char S4[] = {'R','L','R','R','R','L','L','R','L','L','\0'};
	//Question 1
	printf("Question 1: \n");
	B = sortArrayByParity(A, ASIZE, &returnSize);

	//Example 1 of Question 2
	printf("\nQuestion 2:\n");
	printf("Example 1: [");
	temp = balancedStringSplit(S1);
	printf("]\nExample 1 has %d splits\n",temp);

	//Example 2 of Question 2
	printf("Example 2: [");
	temp = balancedStringSplit(S2);
	printf("]\nExample 2 has %d splits\n",temp);

	//Example 3 of Question 2
	printf("Example 3: [");
	temp = balancedStringSplit(S3);
	printf("]\nExample 3 has %d splits\n", temp);

	//Example 4 of Question 2
	printf("Example 4: [");
	temp = balancedStringSplit(S4);
	printf("]\nExample 3 has %d splits\n",temp);

	//Question 3
	printf("\nQuestion 3\n");
	//make a singlylinked list
	struct ListNode ll5={5,NULL}, ll4={4,&ll5},
		 ll3={3,&ll4}, ll2={2,&ll3}, ll1={1,&ll2};

	//print out the input list
	printf("Input: [ ");
	printListy(&ll1);
	printf(" ]\n");

	//reverse that stanky list
	revHead = reverseList(&ll1);

	//print out the output list
	printf("Reverse of the input\nOutput: [ ");
	printListy(revHead);
	printf(" ]\n");
	return 0;
}
