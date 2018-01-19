#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//m is the modulus
//a is the multiplier
//c is the increment
//Xn = (aXn-1 + c) mod m
// m must be a prime somewhat larger than the range i want

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
int tofile(double* data,int repeat, FILE *randfile){
int i;

//int fo;
randfile = fopen("randomnums.txt", "w");
//fo = fwrite(data, sizeof(data),1,randfile);
for(i=0; i<repeat; i++){
fprintf(randfile,"%f\n", data[i]);
}
fclose(randfile);
};
double sysseed(){
	time_t now;
	now  =time(NULL);
	return((int) now%100000);
}

int lcg(int crntx, int amult, int inc, int mod)
{
	return((amult * crntx + inc) % mod);
}
float testavg(float totalv, int tnumber, int mod){
	return((double)totalv/tnumber/mod);
}
int main(void)
{
	FILE *randfile;
	
	double totalsarray[10];
	double randarray[10000];
	time_t crntx;// the current value of x
	int amult = 3;// what a is in the formula/ the multipler value
	int inc = 3;// the increment
	int mod = 101;// the mod 
	int repeat = 100;//how many times it runs through the rng
	float gennum; //the generated number
	int i;
	float totalv; //the total value of the numbers
	float average;// the average based on the average function
    crntx = sysseed();
	printf("%li\n", crntx);
	//printf("choose your starting x\n");
	//scanf("%d", &crntx);
	printf("choose your multipler\n");
	scanf("%d", &amult);
	printf("choose your increment\n");
	scanf("%d", &inc);
	printf("choose your mod\n");
	scanf("%d", &mod);
	printf("how many iterations do you want to run?\n");
	scanf("%d", &repeat);
	double gennumarray[repeat];
	for(i=0; i<repeat; i++)
	{
		if(i>0){
		
			
			printf("%f\n", gennum/mod);
			
		}
		
		gennum = (float)lcg(crntx, amult, inc, mod);//generates the number
		totalv= totalv + gennum;// adds the number to the total
		crntx=lcg(crntx, amult, inc, mod);//sets the current x to a new "random" number
		randarray[i] = (crntx/(float)mod);
		gennumarray[i] = (double)gennum;
		
		
	}
	tofile(randarray, repeat, randfile);
	histogram(gennumarray, totalsarray, repeat, randfile);
	average = testavg(totalv, repeat, mod);//returns the avg value
	
	printf("the average is %f\n", average);//prints the average
	if(average>.45 && average <.55){
		printf("it's probably maybe random\n");
	}
	else{
		printf("this could be bad, not very random or well distributed\n");	
	}
		return 0;
	fclose(randfile);
}
