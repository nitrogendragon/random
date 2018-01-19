#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double sysseed(){
	time_t now;
	now  =time(NULL);
	return((int) now%100000);
}
