CC = gcc
INCLUDE = include/*.h
CFLAGS = -O2
SRC = src/*.c
OUTPUT = acash

all:
	$(CC) -I$(INCLUDE) $(CFLAGS) $(SRC) -o $(OUTPUT)

clean:
	rm -rf $(OUTPUT)