CC=gcc
OBJS=baka.o
CFLAGS=

baka: $(OBJS)
	$(CC) -o baka $(OBJS)
baka.o: baka.c baka.h
	$(CC) $(CFLAGS) -c baka.c
clean:
	rm -rf baka baka.exe $(OBJ)
