CC = gcc
CFLAGS = -I.
DEPS = dynamic_queue.h
OBJ = dynamic_queue.o main.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o main
