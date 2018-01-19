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