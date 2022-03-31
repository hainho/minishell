CC=gcc
CFLAGS=-g -O
OBJS=main.o smallsh.o
TARGET=main

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: smallsh.h main.c

clean:
	rm -f *.o main
