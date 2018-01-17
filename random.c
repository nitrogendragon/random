#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//m is the modulus
//a is the multiplier
//c is the increment
//Xn = (aXn-1 + c) mod m

int lcg(int crntx, int amult, int inc, int mod)
{
	return((amult * crntx + inc) % mod);
}
int main(void)
{
	int crntx;// the current value of x
	int amult;// what a is in the formula/ the multipler value
	int inc;// the increment
	int mod;// the mod 
	int repeat;//how many times it runs through the rng
	float gennum; //the generated number
	int i;
	printf("choose your starting x\n");
	scanf("%d", &crntx);
	printf("choose your multipler\n");
	scanf("%d", &amult);
	printf("choose your increment\n");
	scanf("%d", &inc);
	printf("choose your mod\n");
	scanf("%d", &mod);
	printf("how many iterations do you want to run?\n");
	scanf("%d", &repeat);
	for(i=0; i<repeat; i++)
	{
		if(i>0){
		
		
			printf("%f\n", gennum/mod);
		}
		gennum = (float)lcg(crntx, amult, inc, mod);
		crntx=lcg(crntx, amult, inc, mod);
	}
		return 0;
}