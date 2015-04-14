all: warcraft worker read_mine

warcraft: warcraft.o
	clang warcraft.o -o warcraft

warcraft.o: main.c
	clang -c main.c -o warcraft.o

worker: worker.o
	clang worker.o -o worker

worker.o: worker.c
	clang -c worker.c

read_mine: read_mine.o
	clang read_mine.o -o read_mine

read_mine.o: read_mine.c
	clang -c read_mine.c

clean:
	rm -rf *.o warcraft worker read_mine
