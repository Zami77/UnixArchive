.SUFFIXES: .c .o
CC = gcc
CFLAGS = -g

.c.o:
	$(CC) $(CFLAGS) -c $<

hw3: main.o archiveToFile.o writeToArchive.o pluckArchive.o
	gcc main.o archiveToFile.o writeToArchive.o pluckArchive.o -o hw3

main.o: externs.h main.c
archiveToFile.o: externs.h archiveToFile.c
writeToArchive.o: externs.h writeToArchive.c
pluckArchive.o: externs.h pluckArchive.c

clean:
	rm -f *.o core
