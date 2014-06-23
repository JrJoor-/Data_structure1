CC = gcc
CFLAGS = -I.
DEPS = DynamicList.h
OBJ = DynamicList.o main.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o main
