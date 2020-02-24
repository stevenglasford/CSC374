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
