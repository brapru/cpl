CC = gcc

CFLAGS  = -Icpl
CFLAGS += -std=c99
CFLAGS += -Wall -Wextra -Wpedantic -Wfatal-errors

TESTS = \
	tests/test_cpl.c \
	tests/test_vec.c

cpl-test:
	$(CC) $(CFLAGS) -o ./tests/cpl-test -g $(TESTS) 
	@./tests/cpl-test
	@rm -f ./tests/cpl-test
	@rm -rf ./tests/cpl-test.dSYM/

clean:
	@rm -f ./tests/cpl-test
	@rm -rf ./tests/cpl-test.dSYM/
