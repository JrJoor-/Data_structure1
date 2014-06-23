CC = gcc
CFLAGS = -I.
DEPS = static_queue.h static_stack.h
OBJ = static_queue.o static_stack.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o main
