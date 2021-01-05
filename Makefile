CC = gcc -std=c11

CFLAGS  = -Icpl
CFLAGS += -Wall -Wextra -Wpedantic -Wfatal-errors

all: cpl-test

cpl-test:
	$(CC) $(CFLAGS) cpl.c -o cpl-test

clean:
	rm -rf cpl-test
