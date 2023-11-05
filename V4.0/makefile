CC = gcc
CFLAGS = -Wall -Wextra -g -lm
DEPS = Generator.h
OBJ = GeneratorMain.o Generator.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

generator: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o generator