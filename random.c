#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "randavg.h"
#include "tofile.h"
#include "seedgenerator.h"
#include "lcg.h"
#include "hist.h"

//m is the modulus
//a is the multiplier
//c is the increment
//Xn = (aXn-1 + c) mod m
// m must be a prime somewhat larger than the range i want

/** main function that runs all the other functions to create the rng
uses randavg.c to get th average of the random numbers
uses tofile.c to send the random numbers produced to the new text file defined as randomnums.txt
uses seedgenerator.c to generate the seed for the lcg from system time(computer clock)
uses hist.c to collect the data into an array and then change those numbers and\
put into another array to show data distribution which is appened to randomnums.txt
*/
int main(void)//main function
{
	FILE *randfile;//file pointer
	
	double totalsarray[10];//array used for counting how many values fall into certain ranges.. used in hist.c
	
	time_t crntx;// the current value of x
	int amult = 3;// what a is in the formula/ the multipler value
	int inc = 3;// the increment
	int mod = 101;// the mod 
	int repeat = 100;//how many times it runs through the rng
	float gennum; //the generated number
	int i;// integer i to be used for if statements/ for loops
	float totalv; //the total value of the numbers
	float average;// the average based on the average function
    crntx = sysseed();//runs sysseed functiona nd sets crntx
	printf("%li\n", crntx);//prints the initial value of crntx which is the system time
	//printf("choose your starting x\n");
	//scanf("%d", &crntx);
	printf("choose your multipler\n");//asks user for choosing multiplier value of lcg function
	scanf("%d", &amult);//scans answer and stores in amult
	printf("choose your increment\n");//asks user for choosing value by which seed increments
	scanf("%d", &inc);//scans answer and stores in inc
	printf("choose your mod\n");// question for determiningthe mod of the lcg function
	scanf("%d", &mod);//scans answer and stores in mod
	printf("how many iterations do you want to run?\n");//question for determing iterations
	scanf("%d", &repeat);//scans user input and stores in repeat
	double gennumarray[repeat];//takes all the values generated and pushes them to hist.c to be used for creating the distribution array
	double randarray[repeat];//array used to store all the values generated and is passed to tofile.c
	for(i=0; i<repeat; i++)//for loop to iterate through functions specified number of times either by user or predefined times
	{
		if(i>0){
		
			
			printf("%f\n", gennum/mod);//begins printing the values in terminal in range 0-1 
			
		}
		
		gennum = (float)lcg(crntx, amult, inc, mod);//generates the number
		totalv= totalv + gennum;// adds the number to the total
		crntx=lcg(crntx, amult, inc, mod);//sets the current x to a new "random" number
		randarray[i] = (crntx/(float)mod);//sets randarray[i] to the current seed/mod
		gennumarray[i] = (double)gennum;// sets gennumarray[i] to gennum in type double
		
		
	}
	tofile(randarray, repeat, randfile);//runs tofile using the various parameters
	histogram(gennumarray, totalsarray, repeat, randfile);// runs hist using the given parameters
	average = testavg(totalv, repeat, mod);//returns the avg value
	
	printf("the average is %f\n", average);//prints the average
	/**
	checks to see if the average computed by the average function is within the specified values
	*/
	if(average>.45 && average <.55){
		printf("it's probably maybe random\n");
	}
	else{
		printf("this could be bad, not very random or well distributed\n");	
	}
		return 0;
	fclose(randfile);//closes randfile(randomnums.txt will not be editable anymore
}
