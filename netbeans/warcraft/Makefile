all: warcraft worker read_mine

warcraft: warcraft.o
	gcc warcraft.o -o warcraft
	
warcraft.o: main.c
	gcc -c main.c -o warcraft.o

worker: worker.o
	gcc worker.o -o worker
	
worker.o: worker.c
	gcc -c worker.c
	
read_mine: read_mine.o
	gcc read_mine.o -o read_mine

read_mine.o: read_mine.c
	gcc -c read_mine.c

clean:
	rm -rf *.o warcraft worker read_mine