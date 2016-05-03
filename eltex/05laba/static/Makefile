# Makefile for static lib
main: main.o libmath.a
	gcc -o main main.o -L. -lmath

main.o: main.c
	gcc -c main.c

libmath.a: division.o subtraction.o summ.o multiple.o
	ar rc libmath.a division.o subtraction.o summ.o multiple.o
	ranlib libmath.a

division.o: division.c
	gcc -c division.c

subtraction.o: subtraction.c
	gcc -c subtraction.c

summ.o: summ.c
	gcc -c summ.c

multiple.o: multiple.c
	gcc -c multiple.c

clean:
	rm -rf *.o *.a main


