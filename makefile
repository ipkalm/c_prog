cards : new.c
	gcc -Wall -o cards new.c
clean : cards
	rm cards
