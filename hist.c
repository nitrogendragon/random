#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//m is the modulus
//a is the multiplier
//c is the increment
//Xn = (aXn-1 + c) mod m
// m must be a prime somewhat larger than the range i want
/**
takes all the generated values puts them into an array and then divides them by 10 and turns to an integer to create 10 groups.\
then these numbers get put into a new array of size 10 and counts up the number of times that these numbers get put in
lastly it prints out how many each group got and writes it to the file randfile aka randomnums.txt
*/
int histogram(double* gennumarray,double* totalsarray, int repeat, FILE *randfile){
	int i;
	int loc;
	randfile = fopen("randomnums.txt", "a");
	fprintf(randfile, "\n");
	for(i = 0; i<repeat; i ++){
		
		gennumarray[i] = (int)(gennumarray[i] / 10);
		
		loc = (int)(gennumarray[i]);
		
		totalsarray[loc] += 1;
		
	}
	for(i=0; i<10; i++){
	fprintf(randfile, "the total for group %i is %f\n", i, totalsarray[i]); 
	int average = totalsarray[i];
	}
	

	
};//histogramdata end
