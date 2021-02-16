# Richard Fernando Heise Ferreira & Carlos Iago Bueno
# GRR20191053 & GRR20190171

CC = gcc
CFLAGS = -Wall

OBJECTS = main.o myht.o
BINARIES = myht

all: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(BINARIES) -lm

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

myht.o: myht.c
	$(CC) $(CFLAGS) -c myht.c

clean:
	rm -rf *.o

purge: clean
	rm -rf $(BINARIES)
