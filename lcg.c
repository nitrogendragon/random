#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
/**
the function that generates technicall random numbers
*/
int lcg(int crntx, int amult, int inc, int mod)
{
	return((amult * crntx + inc) % mod);
}
