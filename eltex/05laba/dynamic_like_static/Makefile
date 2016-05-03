# Makefile for static lib
main: main.o libmath.so
	gcc -o main main.o -L. -lmath -Wl,-rpath,.

main.o: main.c
	gcc -c main.c

libmath.so: division.o subtraction.o summ.o multiple.o
	gcc -shared -o libmath.so division.o subtraction.o summ.o multiple.o

division.o: division.c
	gcc -fPIC -c division.c

subtraction.o: subtraction.c
	gcc -fPIC -c subtraction.c

summ.o: summ.c
	gcc -fPIC -c summ.c

multiple.o: multiple.c
	gcc -fPIC -c multiple.c

clean:
	rm -rf *.o *.so main
