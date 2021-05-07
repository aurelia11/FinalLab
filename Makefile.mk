CC = g++
CFLAGS = -Wall -g

main: main.o rectBlocks.o sqrBaseRectBlocks.o cylindricalBlocks.o sphericalBlocks.o
	$(CC) $(CFLAGS) -o main main.o rectBlocks.o sqrBaseRectBlocks.o cylindricalBlocks.o sphericalBlocks.o

main.o: main.cpp rectBlocks.h sqrBaseRectBlocks.h cylindricalBlocks.h sphericalBlocks.h
	$(CC) $(CFLAGS) -c main.cpp

rectBlocks.o: rectBlocks.h rectBlocks.cpp

sqrBaseRectBlocks.o: sqrBaseRectBlocks.h sqrBaseRectBlocks.cpp

sphericalBlocks.o: sphericalBlocks.h sphericalBlocks.cpp

cylindricalBlocks.o: cylindricalBlocks.h cylindricalBlocks.cpp

cuboidBlocks.o: cuboidBlocks.h cuboidBlocks.cpp

clean:
	rm *.o main