# Compiler
CC = g++
# Compiler Flags
CFLAGS = -Wall -std=c++11

# Source Files
SRC = main.c Generator.cpp
# Object Files
OBJ = $(SRC:.cpp=.o)
# Executable Name
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)