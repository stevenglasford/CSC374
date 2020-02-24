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
