#include<stdlib.h>
#include<stdio.h>

int
main(){

	int i;

	fork();

	for(i=0; i<100000000000;i++);

	return 0;
}
