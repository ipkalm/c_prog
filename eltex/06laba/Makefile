# variables
CC=clang
CXX=clang++
#CFLAGS=-march=amdfam10 -mtune=amdfam10 -O2 -mcx16 -mpopcnt -pipe -fomit-frame-pointer -fstack-protector-strong
CFLAGS="-march=amdfam10 -mtune=amdfam10 -O2 -mcx16 -mpopcnt -pipe -fomit-frame-pointer -fstack-protector-strong -mmmx -m3dnow -msse -msse2 -msse3 -msse4a"
CXXFLAGS="${CFLAGS}"

main: main.o worker
	${CC} ${CFLAGS} main.o -o $@

main.o: main.c
	${CC} -c $^

worker: worker.o
	${CC} ${CFLAGS} $^ -o $@

worker.o: worker.c
	${CC} -c $^

bin_reader: bin_reader.o
	${CC} ${CFLAGS} $^ -o $@

bin_reader.o: bin_reader.c
	${CC} -c $^

clean:
	rm -rf *.o main worker bin_reader base.bin mine.bin
