#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
/**
takes array data which is the array of generated numbers from the lcg.c and creates or opens a file and prints/writes\
to the file.
*/
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
