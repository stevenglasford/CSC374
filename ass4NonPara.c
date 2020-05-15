#include <stdio.h>

static long num_steps = 1000000;
double step = 0.0;
int main(){
	int i=0;
	double x=0.0, pi=0.0, sum=0.0;
	step = 1.0/((double) num_steps);
	for (i=0; i < num_steps; i++){
		x=(i+0.5)*step;
		sum=sum+4.0/(1.0+x*x);
	}

	pi = step*sum;
	printf("\n%f\n", pi);
}
