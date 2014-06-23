CC = gcc
CFLAGS = -I.
DEPS = fakeQueue.h
OBJ = fakeQueue.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o main
