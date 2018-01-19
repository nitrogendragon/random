random: random.o tofile.o seedgenerator.o lcg.o hist.o randavg.o
	gcc random.o  tofile.o seedgenerator.o lcg.o hist.o randavg.o -lm -o random

random.o: random.c
	gcc random.c -c
	
tofile.o: tofile.c
	gcc tofile.c -c
	
seedgenerator.o: seedgenerator.c
	gcc seedgenerator.c -c
	
lcg.o: lcg.c
	gcc lcg.c -c
	
hist.o: hist.c
	gcc hist.c -c
	
randavg.o: randavg.c
	gcc randavg.c -c
	
clean:
	rm -i *.c~ *.o random
