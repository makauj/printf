CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99 -I.
SRC = _printf.c flush_buffer.c
OBJ = $(SRC:.c=.o)
TEST_SRC = tests/test_printf.c tests/test_flush_buffer.c
TEST_OBJ = $(TEST_SRC:.c=.o)
TARGET = libprintf.a
TEST_TARGET = test

all: $(TARGET)

$(TARGET): $(OBJ)
	ar rcs $@ $^

tests/%.o: tests/%.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(OBJ) $(TEST_OBJ)
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $^

clean:
	rm -f $(OBJ) $(TEST_OBJ) $(TARGET) $(TEST_TARGET)

.PHONY: all clean test
