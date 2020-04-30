/*
	This program is for Computer Organization and
	Architecture at NDSU Spring 2020 with Malik.
	Basically is a "Hello, World!" program that
	uses concurency using OpenMP.
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(){
	#pragma omp parallel
	{
		printf("Hello... Bitches from: %d\n", omp_get_thread_num());
	}
	return 0;
}
