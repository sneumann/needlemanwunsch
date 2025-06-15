CC=gcc
CFLAGS=-Wall -Wextra -std=c99 -I./src

all: main test

main: src/main.c src/needleman_wunsch.c src/needleman_wunsch.h
	$(CC) $(CFLAGS) -o bin/main src/main.c src/needleman_wunsch.c

test: src/test_needleman_wunsch.c src/needleman_wunsch.c src/needleman_wunsch.h
	$(CC) $(CFLAGS) -o bin/test_needleman_wunsch src/test_needleman_wunsch.c src/needleman_wunsch.c -lm
	bin/test_needleman_wunsch

clean:
	rm -f main test_needleman_wunsch