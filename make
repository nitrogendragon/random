averages: averages.o arithemtmic.o gemoetric.o harmonic.o
	gcc averages.o arithemtic.o \
	geometric.o harmonic.o -lm -o averages
			
averages.o: averages.c
	gcc averages.c -c

gemotric.o: geometric.c
	gcc geometric.c -c
	
harmonic.o: harmonic.c
	gcc harmonic.c -c

clean:
	rm -i *.c~ *.o averages
	//how to put files on athe server
tar czvf averages.tar.gz averages
scp averages.tar.gz \
cduncan19@cs1.cornellcollege.edu

