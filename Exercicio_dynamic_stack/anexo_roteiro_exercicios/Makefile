CC = gcc
CFLAGS = -I.
DEPS = stack.h
OBJ = stack.o resolucao_exercicio.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o main