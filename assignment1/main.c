#include <stdio.h>
#include <stdlib.h>
#include "Q1.c"
#include "Q2.c"
#include "node.c"
#include "printListy.c"
#include "Q3.c"

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
